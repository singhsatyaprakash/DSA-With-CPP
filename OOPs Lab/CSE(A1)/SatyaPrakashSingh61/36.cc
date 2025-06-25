
#include<map>
#include<string>
#include<iostream>
#include<cctype>
using namespace std;
int main(){
    string sentence="the quick brown fox jumped over the lazy dog";
    map<string,int>wordCount;
    string word="";
    for(char ch:sentence){
        if(isalnum(ch)){
            word+=ch;
        }else if(!word.empty()){
            wordCount[word]++;
            word="";
        }
    }
    if(!word.empty()){
        wordCount[word]++;
    }
    cout<<"Word frequencies: "<<endl;
    for(auto it=wordCount.begin();it!=wordCount.end();++it){
        cout<<it->first<<": "<<it->second<<endl;
    }
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}

