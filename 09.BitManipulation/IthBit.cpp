#include<iostream>
using namespace std;
int GetIthBit(int num,int i){
    int bitmask=1<<i;
    if(!(num&bitmask)){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    cout<<GetIthBit(6,2)<<endl;
    cout<<GetIthBit(6,3)<<endl;
    cout<<GetIthBit(57,6)<<endl;
    cout<<GetIthBit(57,5)<<endl;
    cout<<GetIthBit(100,3)<<endl;
    cout<<GetIthBit(100,13)<<endl;
    return 0;
}