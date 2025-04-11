#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int pow= 1 << n;
    cout<<"2 to power "<<n<<  ":"<<pow;
    return 0;
    
}