#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    //opening file using constructor
    //create and writing in file
    ofstream out("sample.txt");//out is object of fstream class to open file...// Open file in truncated mode...
    out<<"ram goes to home.";
    return 0;
}