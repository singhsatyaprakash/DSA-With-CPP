#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter Number:";
    cin>>n;
    bool isprime=true;
    for(int i=2;i<=n-1;i++){//for n=2 condition is not true hence it will give prime for number 2 also..
        if(n%i==0){
            isprime=false;
            break;
        }
    }
    if(isprime){
        cout<<"Number is prime."<<endl;
    }
    else{
        cout<<"Number is NOT prime."<<endl;
    }
    return 0;
}