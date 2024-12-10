#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    //reading from file
    ifstream in("sample.txt");
    string str;
    getline(in,str);
    cout<<str;
    return 0;
}