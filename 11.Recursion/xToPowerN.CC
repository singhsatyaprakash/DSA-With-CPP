#include<iostream>
using namespace std;
int power(int x,int n){
    if(n==0){
        return 1;
    }
    int halfpow= power(x,n/2);
    if(n%2==0){//even
    return halfpow*halfpow;
    }
    else if(n%2!=0){//odd
    return x*halfpow*halfpow;
    }
    return 0;
}
int main(){
    int x,n;
    cout<<"Enter num:";
    cin>>x;
    cout<<"Enter power:";
    cin>>n;
    cout<<x<<" to the power "<<n<<" = "<<power(x,n);
    return 0;
}