#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter Number:";
    cin>>num;
    int sum=0,d;
while(num!=0){
        d=num%10;
        cout<<d;
        num=num/10;
        sum+=d;

    }
    return 0;
}