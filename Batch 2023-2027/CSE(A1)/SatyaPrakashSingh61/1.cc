/*
1. Write a program in C++ to display the multiplication table vertically from 1 to n.
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n;
    cout<<"Enter n upto print table:";
    cin>>n;
    cout<<setw(50)<<"*****Multipilication Table from 1 to "<<n<<" *********\n"<<endl;
    for(int i=1;i<=10;i++){
        for(int j=1;j<=n;j++){
            cout<<j<<"*"<<i<<"="<<i*j<<"\t\t";
        }
        cout<<endl;
    }
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}