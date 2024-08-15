#include<iostream>
using namespace std;
int main(){
    int n,prod=1;
    cout<<"Enter Number:";
    cin>>n;
    for(int i=n;i>0;i--){
        prod*=i;
    }
    cout<<"Factorial of "<<n<<" is:"<<prod<<endl;
    return 0;
}