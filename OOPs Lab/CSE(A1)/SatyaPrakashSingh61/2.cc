/*
Write a program in C++ to display the sum of the series [ 9 + 99 + 999 + 9999 ...]
*/
#include<iostream>
#include<cmath>// For pow function
using namespace std;
int main(){
    int n;
    cout<<"Enter number of terms: ";
    cin>>n;
    long long sum=0;
    long long term=9;
    for(int i=0;i<n;i++){
        cout<<term<<" "; 
        sum+=term;
        term=term*10+9;
    }
    cout<<endl;
    cout<<"The sum of the Series = "<<sum<<endl;
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}
