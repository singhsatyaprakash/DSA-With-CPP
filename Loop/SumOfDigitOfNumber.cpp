#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter Number:";
    cin>>num;
    int sum=0,d;
while(num!=0){
        d=num%10;
        num=num/10;
        sum+=d;

    }
    cout<<"Sum of digits:"<<sum;
    return 0;
}