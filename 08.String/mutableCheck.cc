#include<iostream>
using namespace std;
int main(){
    string str="hot";
    for(int i=0;i<26;i++){
        str[0]=char(i+'a');
        cout<<str<<endl;
    }
    return 0;
}