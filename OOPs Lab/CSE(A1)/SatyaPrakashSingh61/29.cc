/*Write a program to copy the contents of one text file to another while changing the case of 
every alphabet. */
#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
int main(){
    ifstream inputFile("source.txt");
    ofstream outputFile("destination.txt");
    if(!inputFile.is_open() || !outputFile.is_open()){
        cerr<<"Error opening file!"<<endl;
        return 1;
    }
    char ch;
    while(inputFile.get(ch)){
        if(isalpha(ch)){
            ch=islower(ch)?toupper(ch):tolower(ch);
        }
        outputFile.put(ch);
    }
    cout<<"File is copied from Source to desitnation."<<endl;
    inputFile.close();
    outputFile.close();
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}