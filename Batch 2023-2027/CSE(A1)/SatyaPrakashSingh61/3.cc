/*
3.An electricity board charges the following rates to domestic users to discourage large consumption of energy.
For the first 100 units:60 P per unit 
For the next 200 units:80 P per unit 
Beyond 300 units:90 P per unit
All users are charged a minimum of Rs 50 if the total amount is more than Rs 300 then an additional surcharge of 15% is added.
Implement a C++ program to read the names of users and number of units consumed and display the charges with names.
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void display(string name,int unit,float Totalbill){
    cout<<setw(26)<<"Name"<<setw(15)<<"Units"<<setw(20)<<"Bill Amount"<<endl;
    cout<<setw(26)<<name<<setw(15)<<unit<<setw(20)<<Totalbill<<endl;
}
float calculate(int unit){
    float total=0.0;
    if(unit<=100){
        total=unit*0.60;
    }else if(unit<=300){
        total=(100*0.60)+((unit-100)*0.80);
    }else{
        total=(100*0.60)+(200*0.80)+((unit-300)*0.90);
    }
    // Minimum charge of Rs. 50
    if(total<50){
        total=50;
    }
    // Additional surcharge of 15% if total exceeds Rs. 300
    if(total>300){
        total+=total*0.15;//Adding 15% surcharge
    }
    return total;
}
int main(){
    string name;
    cout<<"Enter User Name:";
    getline(cin,name);
    int unit;
    cout<<"Enter number of unit:";
    cin>>unit;
    float Totalbill=calculate(unit);
    display(name,unit,Totalbill);
    return 0;
}