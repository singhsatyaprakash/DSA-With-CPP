#include<iostream>
#include<string>
using namespace std;
void printSubsets(string str,string subset){
    if(str==""){
        cout<<subset<<endl;
        return;
    }
    char ch=str[0]; 
    //yes choice
    printSubsets(str.substr(1,str.size()-1),subset+ch);
    //no choice
    printSubsets(str.substr(1,str.size()-1),subset);
}
int main(){
    string str;
    cout<<"Enter string:"; 
    string subset=""; 
    getline(cin,str);
    printSubsets(str,subset);
    return 0; 
}