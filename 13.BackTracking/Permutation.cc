#include<iostream>
#include<string>
using namespace std;
void arrangement(string str,string ans){
    int n=str.size();
    if(n==0){
        cout<<ans<<endl;
    }
    for(int i=0;i<n;i++){
        char ch=str[i];
        // "ABCDEFGH" IF i=2 --> "AB" + "DEFGH"
        string newstr=str.substr(0,i)+str.substr(i+1,n-i-1); //(staringPoint,Length)
        arrangement(newstr ,ans+ch);//need to delete str[i]
    }
}
int main(){
    string str;
    cout<<"Enter string:";
    getline(cin,str);
    string ans="";
    arrangement(str,ans);
    return 0;
}