#include <iostream>
#include<string>
using namespace std;
class MyClass{
public:
    int num;
    string text;
    void display(){
        cout<<"Number: "<<num<<endl;
        cout<<"Text: "<<text<<endl;
    }
};

int main(){
    // Creating an object using pointer
    MyClass *ptr=new MyClass; //dynamic memory allocation..
    // Initializing class members using pointer
    ptr->num = 42;;
    ptr->text ="Hello, World!";
    // Displaying the contents of class members
    ptr->display();
    // Freeing allocated memory
    delete ptr;
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}
