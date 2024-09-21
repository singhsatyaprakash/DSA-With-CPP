C++ program that demonstrates all the possible uses of the scope resolution operator in a single program: */ 
#include <iostream> 
using namespace std;  
int globalv = 50;  
namespace MyNamespace { 
    int namespacev = 60; 
    void displaynamespacev() { 
        cout << "Namespace variable: " << namespacev << endl;     } 
    class main_Class { 
    public: 
        static int staticvalue;
        void display() { 
            cout << "Class member function: " << MyNamespace::main_Class::staticvalue << endl;         } 
        void setstaticvalue(int value) { 
            MyNamespace::main_Class::staticvalue = value;         }     }; }  
int MyNamespace::main_Class::staticvalue = 30;  
class GlobalClass { 
public: 
    void show() {         cout << "Global variable: " << ::globalv << endl;  } };  
int main() { 
    cout << "Access global variable: " << ::globalv << endl; 
    cout << "Access namespace variable: " << MyNamespace::namespacev << endl;  
    MyNamespace::displaynamespacev();      
    MyNamespace::main_Class A; 
    A.display();  
    A.setstaticvalue(50); 
    A.display();      
    GlobalClass globalA; 
    globalA.show();     
    cout<<endl;  
    cout << "*\n";  
    cout << "Program Prepared & Executed by: UPASANA GAUR, CSE(A1), Class Roll no: 73\n";  
    cout << "*\n";  
    return 0; }