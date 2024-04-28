#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter Number:";
    cin>>num;
    int n=0,d;
while(num!=0){
    int d=num%10;
    n=n*10+d;
    num/=10;
    }
    cout<<"Reverse Number is:"<<n<<endl;
    return 0;
}