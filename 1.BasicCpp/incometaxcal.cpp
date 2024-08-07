#include<iostream>
using namespace std;
int main(){
    long salary;
    float tax;
    long income;
    cout<<"Enter salary of emmployee:";
    cin>>salary;
    if(salary<500000){
        tax=(0/100.0)*salary;
        income=salary-tax;
        cout<<"Net Income:"<<income;
    }
     else if(salary>500000 && salary<1000000){
        tax=(20/100.0)*salary;
        income=salary-tax;
        cout<<"Net Income:"<<income;
    }
    else{
        tax=(30/100.0)*salary;
        income=salary-tax;
        cout<<"Net Income:"<<income;
    }
}