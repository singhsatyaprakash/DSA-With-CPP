#include<iostream>
using namespace std;
int ispal(int num){
    int temp=num,res=0;
    for(int i=1;num!=0;i++){
        int d=num%10;
        res=res*10+d;
        num/=10;
    }
    if(res==temp){
        return 1;
    }
    else 
    return 0;
}
int main(){
    int num;
    cout<<"Enter number:";
    cin>>num;
    if(ispal(num)){
        cout<<"Number is palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome."<<endl;
    }
    return 0;
}