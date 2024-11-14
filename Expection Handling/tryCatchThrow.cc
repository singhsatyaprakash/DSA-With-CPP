#include<iostream>
using namespace std;
int main(){
    int a=5,b=0,c;
    try{
        c=a/b;
    }
    catch(...){
        cout<<c<<endl;
    }
    cout<<"Program Exected"<<endl;
    return 0;
}