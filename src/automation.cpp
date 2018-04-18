#include <iostream>
#include <cstdlib>          //Support system calls
using namespace std;
int main()
{
    system("g++ s2b.cpp -o s2b.exe");           
    system("s2b.exe");
    system("g++ encode.cpp -o encode.exe");
    system("encode.exe");
    system("g++ decode.cpp -o decode.exe");
    system("decode.exe");
    system("g++ b2s.cpp -o b2s.exe");
    system("b2s.exe");
}
/* This program automatically executes all the files in proper sequence 
and provides the final results. It is made to make demonstration easier */