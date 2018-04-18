#include <string>
#include <bitset>               //For  binary conversion handling
#include <iostream>
#include <fstream>
using namespace std;
int main(){
  string input;
  cout<<"Enter a input string"<<endl;           //Input string data from users
  cin>>input;
  ofstream InpFile;
  InpFile.open("input_binary.txt");              //Creating new file for outputs and opening
  for (std::size_t i = 0; i < input.size(); ++i)
  {
      InpFile << bitset<8>(input.c_str()[i]);       //Convert each character to <8> bit ASCII value
  }
  cout<<endl;
  InpFile.close();                  //Close file
}
