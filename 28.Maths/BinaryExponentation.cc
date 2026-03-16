#include<iostream>
using namespace std;
/// O(log b)...
int findPower(int a,int b){
    if(b==0){
        return 1;
    }
    int half=findPower(a,b/2);
    int result=half*half;
    if(b%2==1){
        result=result*a;
    }
    return result;
}
int main(){
    int a,b;
    cout<<"a to the power b"<<endl;
    cout<<"Enter a & b:";
    cin>>a>>b;
    int res=findPower(a,b);
    cout<<"Result is:"<<res<<endl;
    return 0;
}