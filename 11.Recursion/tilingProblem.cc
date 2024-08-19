#include<iostream>
using namespace std;
int combination(int n){
    if(n==0||n==1){
        return 1;
    }
    return combination(n-1)+combination(n-2);
}
int main(){
    int n;
    cout<<"Enter size of floor(2xn):";
    cin>>n;
    cout<<"Total no.of ways to fit tile(2x1):"<<combination(n)<<endl;
    return 0;
}