#include<iostream>
using namespace std;
int main(){
    for(int i=1;i<=5;i++){
        cout<<i;// scope of i variable only valid to this loop..
        cout<<endl;
    }
    return 0;
}