
#include<iostream>
using namespace std;
int sum(int a,int b=1){
    return a+b;
}
int main(){
    int a;
    cout<<"Enter a:";
    cin>>a;
    int res=sum(a);
    cout<<"Sum="<<res;
    return 0;
}