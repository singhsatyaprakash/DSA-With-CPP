#include<iostream>
#include<string>
#include<unordered_map>
#include<cctype>
using namespace std;
bool isAnagram(string str1,string str2){
    if(str1.size()!=str2.size()){
        return false;
    }
    unordered_map<char,int>m;
    for(int i=0;i<str1.size();i++){
        if(m.count(tolower(str1[i]))){
            m[tolower(str1[i])]++;
        }
        else{
            m[tolower(str1[i])]=1;
        }
    }
    for(int i=0;i<str2.size();i++){
        if(!m.count(tolower(str2[i]))){
            return false;
        }
        m[tolower(str2[i])]--;
        if(m[tolower(str2[i])]==0){//if frequecey 0 delete that key..
            m.erase(tolower(str2[i]));
        }
    }
    return m.size()==0;
    // for(pair<char,int>el:m){
    //     if(el.second!=0){
    //         return false;
    //     }
    // }
    // if(m.size()!=0){//if map is empty anagram
    //     return false;
    // }
    // return true;
}
int main(){
    string str1,str2;
    cout<<"Enter word1:";
    getline(cin,str1);
    cout<<"Enter word2:";
    getline(cin,str2);
    if(isAnagram(str1,str2)){
        cout<<"Both word are anagram.";
    }
    else{
        cout<<"Not a anagram"<<endl;
    }
    return 0;
}