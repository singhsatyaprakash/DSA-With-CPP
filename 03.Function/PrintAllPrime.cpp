#include<iostream>
using namespace std;
int isprime(int n){
    if(n==1){
        return 0;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int s,l;
    cout<<"Enter Range:";
    cin>>s;
    cin>>l;
    for(int i=s;i<=l;i++){
        if(isprime(i)){
            cout<<i<<" ";
        }
    }
    return 0;
}