#include <string>
#include <bitset>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
  string input;
  cout<<"Enter a input string"<<endl;
  cin>>input;
  ofstream InpFile;
  InpFile.open("bininpstring.txt");              //Creating new file for outputs
  for (std::size_t i = 0; i < input.size(); ++i)
  {
      InpFile << bitset<8>(input.c_str()[i]);
  }
  cout<<endl;
  InpFile.close();
}
