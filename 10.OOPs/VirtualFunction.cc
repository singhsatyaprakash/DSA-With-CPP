#include<iostream>
using namespace std;
class Parent{
public:
    void show(){
        cout<<"Prent class show...\n";
    }
    virtual void hello(){
        cout<<"Parent hello...\n";
    }
};
class Child:public Parent{
public:
    void show(){
        cout<<"Child class show...\n";
    }
    void hello(){
        cout<<"Parent hello...\n";
    }
};

int main(){
    Child child1;
    Parent *ptr;
    ptr=&child1;//run time binding
    ptr->hello();//virtual function
    return 0;
}   