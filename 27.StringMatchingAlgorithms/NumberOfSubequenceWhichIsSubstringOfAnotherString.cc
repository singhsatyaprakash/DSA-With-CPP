#include<iostream>
#include<vector>
using namespace std;
void constructLPS(string &str,vector<int>&lps){
    int n=str.size();
    int len=0,i=1;
    lps[0]=0;
    while(i<n){
        if(str[i]==str[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
bool KMPMatch(string &txt,string &pat){
    int m=pat.size();
    int n=txt.size();
    vector<int>lps(m);
    constructLPS(pat,lps);
    int i=0,j=0;
    while(i<n){
        if(txt[i]==pat[j]){
            i++;
            j++;
            if(j==m){
                return true;
            }
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return false;
}
void genrateSubsequence(vector<string>&subseq,string str,int idx){
    if(idx==str.size()){
        return ;
    }
    


    
}
int main(){
    string str1,str2;
    cout<<"Enter String 1:";
    cin>>str1;
    cout<<"Enter String 2:";
    cin>>str2;

    int n=str1.size();
    int m=str2.size();

    int count=0;
    vector<string>subseq;
    genrateSubsequence(subseq,str1,0);
    cout<<"Total Number of Subsequenc in the first string that is a substring of second string:"<<count<<endl;
    return 0;

}