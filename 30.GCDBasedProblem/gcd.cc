#include<iostream>
using namespace std;
int findGCD(int a,int b){
    if(b==0)
        return a;
    return findGCD(b,a%b);
}
int main(){
    int a,b;
    cout<<"Enter a,b:";
    cin>>a>>b;
    int res=findGCD(a,b);
    cout<<"GCD is:"<<res<<endl;
    return 0;
}