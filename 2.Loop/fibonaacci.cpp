#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"How many terms:";
    cin>>n;
    int a=0,b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=1;i<n;i++){
        int c=a+b;
        a=b;
        b=c;
        cout<<c<<" ";
    }
    return 0;
}