#include<iostream>
#include<string>
using namespace std;
void binString(int n,int lastpalacevalaue,string ans){
    ///base case..
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(lastpalacevalaue!=1){
        binString(n-1,0,ans+'0');
        binString(n-1,1,ans+'1');
    }
    else{
        binString(n-1,0,ans+'0');
    }
}
int main(){
    int n;
    cout<<"Enter size n:";
    cin>>n;
    string ans="";
    binString(n,0,ans);
    return 0;

}