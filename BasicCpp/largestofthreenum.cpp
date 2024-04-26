#include<iostream>
using namespace std;;
int main(){
    int a,b,c;
    cout<<"Enter a,b,& c:";
    cin>>a;
    cin>>b;
    cin>>c;
    if(a>=b&&a>=c){
        cout<<"largest:"<<a;
    }
    else if(b>=a&&b>=c){
        cout<<"largest:"<<b;
    }
    else{
    cout<<"largest:"<<c;
    }

}