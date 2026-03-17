#include<iostream>
using namespace std;

void primeFactors(int n){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            cout<<i<<" ";
            n/=i;
        }
    }
    //self divisble..
    if(n>1){
        cout<<n;
    }
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    primeFactors(n);
}