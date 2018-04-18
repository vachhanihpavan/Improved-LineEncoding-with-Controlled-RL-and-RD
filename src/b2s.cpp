#include <bitset>
#include <iostream>
#include <sstream>                  //For bit to string stream conversion
#include <string>
#include <fstream>                  //For InFilee Streams
using namespace std;
int main()
{

    std::string line;                   //Store the bit stream string
    ifstream InFile;                    //File pointer
    InFile.open("decoded_data.txt");
    while(!InFile.eof())                //Read file till end of file (eof)
    {
        InFile>>line;                   //Store data from file to string variable
    }
    std::istringstream in(line);        //To allow operation on input streams
    std::bitset<8> bs;                  //Binary conversion handling
    while(in >> bs)
        std::cout << char(bs.to_ulong());       //Returns an unsigned long with the integer value that has the same bits set as the bitset.
    InFile.close();                        //Close file
}
