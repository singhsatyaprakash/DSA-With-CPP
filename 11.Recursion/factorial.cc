#include<iostream>
using namespace std;
long long factorial(long long n){
    if(n==1|| n==0){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
    long long n;
    cout<<"Enter num:";
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}