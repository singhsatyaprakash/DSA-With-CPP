#include<iostream>
using namespace std;
int main(){
    string s;
    cout<<"Enter string:";
    cin>>s;

    int n=s.size();
    int idx=0;
    int i;
    for(i=1;i<n;i++){
        if(s[i-1]<=s[i]) continue;
        else{
            idx=i-1;
            break;
        }
    }
    if(i==n){
        cout<<s.substr(0,n-1);
    }
    else{
        cout<<s.substr(0,idx)+s.substr(idx+1);
    }

}