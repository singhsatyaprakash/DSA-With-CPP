#include<iostream>
using namespace std;
class Parent{
public:
    void show(){
        cout<<"Parent class show...\n";
    }
};
class Child:public Parent{
public:
    void show(){
        cout<<"Child class show...\n";
    }
};

int main(){
    // Child child1;
    // child1.show();
    Parent p1;
    p1.show();
    return 0;
}