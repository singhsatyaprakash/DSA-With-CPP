#include<iostream>
using namespace std;
// Global variable
int globalVar=100;
// Global function
void globalFunction(){
    cout<<"This is the global function."<<endl;
}
// Namespace example
namespace ExampleNamespace{
    int value=10;
    void displayValue(){
        cout<<"Value inside ExampleNamespace: "<<value<<endl;
    }
}
// Class example
class MyClass{
public:
    static int staticVar;
    static void staticFunction(){
        cout<<"Static function in MyClass."<<endl;
    }
    void memberFunction(int staticVar) {
        cout<<"Local variable in member function: "<<staticVar<<endl;
        cout<<"Static variable of MyClass: "<<MyClass::staticVar<<endl;
    }
};
// Define static member
int MyClass::staticVar=50;
int main(){
    // 1. Accessing global variable when there is a local variable with the same name
    int globalVar=200;
    cout<<"Local variable globalVar: "<<globalVar<<endl;
    cout<<"Global variable globalVar: "<<::globalVar<<endl;

    // 2. Accessing global function
    globalFunction();

    // 3. Accessing namespace variables and functions
    cout<<"Value in namespace ExampleNamespace: "<<ExampleNamespace::value<<endl;
    ExampleNamespace::displayValue();

    // 4. Accessing class static member variables and functions
    MyClass::staticFunction();
    cout<<"Static variable of MyClass: "<<MyClass::staticVar<<endl;
    
    // 5. Accessing static member variable using scope resolution operator inside class member function
    MyClass obj;
    obj.memberFunction(30);
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}
