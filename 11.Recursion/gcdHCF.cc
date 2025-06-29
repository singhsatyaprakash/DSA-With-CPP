#include<iostream>
using namespace std;
int getGCD(int num1,int num2){ //O(log(min(num1,num2)))
    if(num2%num1==0){
        return num1;
    }
    return getGCD(num2%num1,num1);
}
int main(){
    int num1,num2;
    cout<<"Enter num1 & num2:";
    cin>>num1>>num2;
    cout<<"HCF is:"<<getGCD(min(num1,num2),max(num1,num2));
}