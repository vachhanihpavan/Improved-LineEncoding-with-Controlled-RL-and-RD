#include<bits/stdc++.h>
using namespace std;
#define outside 0       //Indication for current position outside S-block
#define inside 1        //Indication for current position inside S-block

int maxrl=3;            //Max possible value of RL after encoding
int rl=-1;              //RL value for current position of iterator
int prev=-1;            //Value just before current iterator position
int rd=0;               //RD value for current position of iterator
int rd_th=4;            //Threshold value of RD, S-block active after this limit
int maxsize=8;          //Size of input stream
int s=4;                //Size of S-block
int pos=0;              //Iterator
int ends=0;             //End of input vector indicator
std::vector<int> input; //Input vector
std::vector<int> output;//Output Vector


int min(int x,int y)    //Return min value of 2 integers
{
	if(x<y)
		return x;
	else
		return y;
}

int mod(int x)          //Returns absolute value
{
	if(x<0)return(-x);
	return(x);
}

int get_data()          //Moves iterator to next position and return data bit
{
	return(input[::pos++]);	//Referring global variable in function scope
}

void update_rl(int x)       //Updates real time value of RL
{
	if (rl==-1)             //For initial value
	{
		rl=1;
		::prev=x;		//Referring global variable in function scope
	}
	else if(x==::prev)      //Increment if same bit repeats
	{
		rl++;
	}
	else                    //Reset RL value to 1
	{
		rl=1;
		::prev=x;		//Referring global variable in function scope
	}
}

void apply_rl(int x)                //Insert bits in the output vector as stuffing if required
{
	output.push_back(x);            //Insert current bit in output
	update_rl(x);                   //Check for RL limits
	if (rl==maxrl)                  //Bit stuffing required here
	{
		if (x==0)                   //Bit 1 is stuffed
		{
			output.push_back(1);
			rl=1;                   //Reset RL
			::prev=1;
		}
		else                        //Bit 0 is stuffed
		{
			output.push_back(0);
			rl=1;                   //Reset RL
			::prev=0;
		}
	}
}

void update_rd()                                    //Real time RD value updater
{
	rd=0;                                           //Reset RD
	for (int i = 0; i < output.size(); ++i)         //Iterator for full vector, count number of 0s and 1s and difference
	{
		if(output[i]==0)
			rd--;
		else
			rd++;
	}
}

int calculate_rd_sblock()
{
	int rdfifo=0;
	int i;
	while(::pos+s>maxsize)
	{
		input.push_back(0);
		maxsize++;
	}
	for (i = pos; i < ::pos+s; ++i)
	{
		if(input[i]==0)
		{
			rdfifo--;
		}
		else
		{
			rdfifo++;
		}
	}
	::ends=i;
	return(rdfifo);
}

int prepare_s_block(int rdfifo)                     //Sets sflag for S-bit inversion technique
{
	if(rdfifo==0)
	{
		return(0);
	}
	else
	{
		if(rd==rd_th)
		{
			if(rdfifo>0)
			{
				return(1);
			}
			else{
				return(-1);
			}
		}
		else
		{
			if(rdfifo<0)
			{
				return(1);
			}
			else{
				return(-1);
			}
		}
	}
}

int invert(int x)               //Just inverts bit value from 1->0 or 0->1 required in S-block
{
	if(x==0)
		return 1;
	else
		return 0;
}

void insert_indication_bit(int sflag)       //Bit stuffing for start of S-block indication
{
	if(sflag==0)                            //No indication bit if all unchanged i.e. |RD| < RD_TH
	{
		return;
	}
	else if(sflag==-1)                      //If not inverted i.e. {RD = -RD_TH and RD_FIFO > 0} or {RD = RD_TH and RD_FIFO < 0}
	{
		apply_rl(0);
		return;
	}
	else                                    //If inverted i.e. {RD = RD_TH and RD_FIFO < 0} or {RD = -RD_TH and RD_FIFO > 0}
	{
		apply_rl(1);
		return;
	}
}

void rd_adjust()                            // RD adjustment after S-block
{
	while(mod(rd)>rd_th)                    //After exiting S-block check if RD value is exceeding RD_TH
	{
		if(rd>0)                            //Continue adding 0s or 1s till RD becomes = RD_TH
		{
			apply_rl(0);
		}
		else
		{
			apply_rl(1);
		}
		update_rd();                        //Re calculate RD value
	}
	return;
}

void encode()
{
	int mode=outside;
	int sflag;

	while(true)
	{
		if(pos==maxsize)                //Exit loop if end of input
			break;
		int x=get_data();               //Input next bit from user
		if (mode==outside)              //If outside S-block.....
		{
			apply_rl(x);                //Bit stuffing for RL
			update_rd();                //Rechecks RD after bit stuffing by RL and updates RD value
			if (mod(rd)==rd_th)         //If RD value is at threshold, then reduce absolute value...
			{
				int rdfifo;
				rdfifo=calculate_rd_sblock();       //
				sflag=prepare_s_block(rdfifo);
				::ends=pos+s;                       //Iterator for end of S-block
				mode=inside;                        //Mode switch
			}
		}
		else if (mode==inside)          //If inside S-block......
		{
			if(sflag>0)                 //S-block inversion is done
			{
				x=invert(x);
			}
			apply_rl(x);                //Check and stuff bits for RL adjustment
			if(pos==::ends)             //Check end of S-block
			{
				insert_indication_bit(sflag);   //Adds indication bit to show inversion of S-block at the end

				update_rd();                    //Update and adjust RD values
				rd_adjust();
				if(mod(rd)==rd_th)              //Check if new S-block is again required
				{
					int rdfifo=calculate_rd_sblock();       //Redo all S-block procedures
					sflag=prepare_s_block(rdfifo);
				}
				else                                           //No S-block required just mode switch
				{
					mode=outside;
				}
			}

		}
	}
}

int main()
{
    //Taking inputs
	cout<<"Enter the value of MAX_RL.\n";
	cin>>maxrl;
	cout<<"Enter the value of RD_TH.\n";
	cin>>rd_th;
	cout<<"Enter the size of the S-Block.\n";
	cin>>s;
	cout<<"Enter the size of the input sequence.\n";
	cin>>maxsize;
	cout<<"Enter the input sequence bit by bit.\n";
	//Taking bit stream as input in vector
	for (int i = 0; i < maxsize; ++i)
	{
		int x;
		cin>>x;
		input.push_back(x);
	}

	ofstream InFile ("raw_data.txt");           //Creating new file for inputs
	for (int i = 0; i < input.size(); ++i)
	{
        InFile<<input[i]<<" ";                  //Adding input data to file
	}
	InFile<<"\n";
	InFile.close();                             //Closing file

	int max_rd = rd_th + (s/2);             //Calculating Max_RD value
	cout<<"Max_RD = "<<max_rd<<endl;

	encode();                               //Main encoding function

	//Print Outputs
	cout<<"o/p size is:"<<output.size()<<endl;
	cout<<"The output encoded sequence is : \n";

	for (int i = 0; i < output.size(); ++i)
	{
		cout<<output[i]<<"\n";
	}
	cout<<"\n";

	//Print comparison of results
	cout<<"----------------------------------------------------------"<<endl;
	cout<<"| Results"<<endl;
	float average_bit_overhead = (float)(output.size()-maxsize)/maxsize;
	cout<<"| Average Number of Inserted Bits = "<<average_bit_overhead*100<<"%"<<endl;
	cout<<"----------------------------------------------------------"<<endl;

	ofstream OutFile ("encoded_data.txt");              //Creating new file for outputs
	for (int i = 0; i < output.size(); ++i)
	{
		OutFile<<output[i]<<" ";                        //Adding outputs to file
	}
	OutFile<<"\n";
	OutFile.close();                                    //Closing the file
}
