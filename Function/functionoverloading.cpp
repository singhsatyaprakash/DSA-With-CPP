
#include<iostream>
using namespace std;
int sum(int a,int b){
     int sum=a+b;
    return sum;
}
// function overloading complier automatically dected this function for double datatype
double sum(double a,double b){//return type se oveloading ka koi concept nahi hai their should be differnt parameter datatype or extra parameter
    double sum=a+b;
    return sum;
}
int sum(int a,int b,int c){
    int sum=a+b+c;
    return sum;
}
int main(){
cout<<sum(2,3)<<endl;
cout<<sum(2,3)<<endl;
cout<<sum(1.5,2.5)<<endl;//it give 3 instead of 4-->>
cout<<sum(1,2,3)<<endl;
    return 0;
}