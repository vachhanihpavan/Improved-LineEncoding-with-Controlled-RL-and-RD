#include <bits/stdc++.h>
#include <string>
using namespace std;
#define outside 0				//Indication for current position outside S-block
#define inside 1				//Indication for current position inside S-block
#define pibit 2					//Process Indication bit to know process in S-block

int maxrl=3;					//Max possible value of RL after encoding
int rl=-1;						//RL value for current position of iterator
int prev=-1;					//Value just before current iterator position
int rd=0;						//RD value for current position of iterator
int rd_th=4;            		//Threshold value of RD, S-block active after this limit
int maxsize=8;          		//Size of input stream
int s=4;                		//Size of S-block
int pos=0;						//Iterator
int ends=0;						//End of input vector indicator
std::vector<int> input;			//Input vector
std::vector<int> output;		//Output Vector
std::vector<int> fifo;			//FIFO for S-block processing


int mod(int x)					//Returns absolute value
{
	if(x<0)
		return (-x);
	else
		return (x);
}

int getdata()					//Data bits insertion in input vector from string
{
	return input[pos++];
}

void put_data(int x)			//Data push(entry) to output vector
{
	output.push_back(x);
}

void append_fifo(int x)			//Data push to FIFO while RD_TH is reached
{
	fifo.push_back(x);
}

void update_rl(int x)			//Measure RL for current bit position / Real time RL calculation 
{
	if (rl==-1)					//Initial or base case
	{
		rl=1;
		::prev=x;
	}
	else if(x==::prev)			//Increating RL acc to previous value
	{
		rl++;
	}
	else						//Reset RL value
	{
		rl=1;
		::prev=x;
	}
}

void update_rd()				//Measure RD for current bit position / Real time RD calculation 
{
	rd=0;								//Initialize counter to 0
	for (int i = 0; i < pos; ++i)		//Count number of 0 or 1s till current pos pointer
	{
		if(input[i]==0)
			rd--;
		else
			rd++;
	}
}

int decode_rl()					//Manage RL bit stuffings if MAX_RL is reached
{
	int x=getdata();
	update_rl(x);				//Calculating current RL value
	if(::rl==maxrl)				//Check if current RL is at threshold
	{
		int y=getdata();
		update_rl(y);
	}
	return x;
}

int calculate_rd()									//Calculate RD value of FIFO only...Bits inside FIFO
{
	int rdfifo=0;									//Initialise counter to 0
	for(int i=0;i<fifo.size();i++)					//Count 0 or 1s for each bits in FIFO
	{
		if(fifo[i]==0)
			rdfifo--;
		else
			rdfifo++;
	}
	return rdfifo;									//Return RD value
}

void invertfifo()									//Inverts FIFO based on Indication bits
{
	for(int i=0;i<fifo.size();i++)
	{
		if(fifo[i]==0)								//Inverting 0 to 1 and vice versa
			fifo[i]=1;
		else
			fifo[i]=0;
	}
}

void decode()										//Main Decode funnction as per the reference paper.
{
	int mode=outside;								//Initialise mode to outside S-block
	int z;
	int count=0;									//Counter for FIFO
	while(true)
	{
		if(pos==maxsize)							//Condition to exit as decode process is over
			break;
		int x=decode_rl();							//Step 1 to handle RL
		if(mode==outside)							//If outside S-block
		{
			put_data(x);
			update_rd();
			if(mod(rd)==rd_th)						//If threshold is reached then activate S-block
			{
				mode=inside;						//Change mode
				count=0;							//Reset counter
				fifo.clear();						//Clear FIFO for new bits
			}
		}
		else if(mode==inside)						//If already inside S-block
		{
			count++;								//Insert bit to FIFO and increament counter
			append_fifo(x);
			if(count==s-1)							//If it is last bit of S-block, it is process indication bit
			{
				mode=pibit;							//Change mode to pib
			}
		}
		else if(mode==pibit)						//Check pib and handle FIFO bits accordingly
		{
			append_fifo(x);

			int rdfifo=calculate_rd();				//Calculate RD for FIFO bits
			if(rdfifo!=0)
			{
				x=decode_rl();					
				if(x==1)							//If indication bit is 1 and RD_FIFO != 0 then invert
				{
					invertfifo();
				}
			}
			for(int i=0;i<fifo.size();i++)
			{
				put_data(fifo[i]);					//Put inverted bits to output vector
			}
			update_rd();							//Recheck RD value if S-block is to be continued

			while(mod(rd)>rd_th)					//Continue RL decode if RD is > RD_TH
			{

				int x=decode_rl();
				update_rd();
			}

			if(mod(rd)==rd_th)						//Restart S-block again if RD==RD_TH
			{
				mode=inside;						//Mode reset to inside again and FIFO reinitialised
				count=0;
				fifo.clear();
			}
			else
			{
				mode=outside;						//Exit S-block if everything is normal i.e. RD<RD_TH
			}
		}
	}
}

int main()
{
	cout<<"Enter the value of MAX_RL.\n";
	cin>>maxrl;
	cout<<"Enter the value of RD_TH.\n";
	cin>>rd_th;
	cout<<"Enter the size of the S-Block.\n";
	cin>>s;
	string inp;											//It will store data read from input file
	ifstream InFile;									//Input file pointer
	InFile.open("encoded_data.txt");
	while(!InFile.eof())								//Reading data from file to decode
    {
        InFile>>inp;
    }
    InFile.close();
	maxsize = inp.size();								//Initialize size of input vector
	for(int i=0;i<maxsize;i++)
	{
	    int x = inp[i] - '0';							//Input vector data entry and char to int conversion
		input.push_back(x);
	}

	decode();											//Decoding.........

	ofstream OutFile ("decoded_data.txt");
	ofstream MatDecode ("buffer_decode.txt");             //Creating new file for outputs
	for (int i = 0; i < output.size(); ++i)
	{
		OutFile<<output[i];
		MatDecode<<output[i]<<" ";                      //Adding outputs to file
	}
	OutFile.close();
	MatDecode.close();                                 //Closing the file
}
