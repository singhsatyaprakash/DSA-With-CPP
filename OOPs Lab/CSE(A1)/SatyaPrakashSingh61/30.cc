/*Write a program to count number of characters, words and lines in a file. */
#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error in opening file!"<<endl;
        return 1;
    }
    char ch;
    int charCount=0,wordCount=0,lineCount=0;
    string line;
    while(getline(inputFile,line)){//get one by one line
        lineCount++;
        charCount+=line.length(); //including space
        bool inWord=false;
        for(char ch:line){
            if(isspace(ch)){
                if(inWord){
                    wordCount++;
                    inWord=false;
                }
            }
            else{
                inWord=true;
            }
        }
        //count last word if exist.
        if(inWord){
            wordCount++;
        }
    }
    cout<<"Total letters:"<<charCount<<endl;
    cout<<"Total words:"<<wordCount<<endl;
    cout<<"Total lines:"<<lineCount<<endl;
    inputFile.close();
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}