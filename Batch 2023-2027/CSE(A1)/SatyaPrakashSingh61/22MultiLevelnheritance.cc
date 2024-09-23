#include<iostream>
using namespace std;
class Base{
public:
    Base(){
        cout<<"Base constructor called.."<<endl;
    }
    ~Base(){
        cout<<"Base destructor called.."<<endl;
    }
};
class Derived1:public Base{
public:
    Derived1(){
        cout<<"Derived1 constructor called..."<<endl;
    }
    ~Derived1(){
        cout<<"Derived1 destructor called..."<<endl;
    }
};
class Derived2:public Derived1{
public:
    Derived2(){
        cout<<"Derived2 constructor called..."<<endl;
    }
    ~Derived2(){
        cout<<"Derived2 destructor called..."<<endl;
    }
};
int main(){
    Derived2 obj; //Creating an object of Derived2 class
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}
