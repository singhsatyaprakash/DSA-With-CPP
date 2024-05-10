#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of rows:";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}