#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter a & b:";
    cin>>a>>b;
    int res=a/b; //program terminated when b=0
    cout<<"a divides by b= "<<res<<endl;
    return 0;
}