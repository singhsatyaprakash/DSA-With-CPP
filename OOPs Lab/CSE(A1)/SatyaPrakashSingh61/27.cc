/*27. Define an exception class called InvalidAgeException that accept user’s age and if the age 
is less than 18 then throw an exception with suitable error message and catch it by displaying 
that message. */
#include<iostream>
#include<exception>
#include<string>
using namespace std;
class InvalidAgeException{
    public:
    int age;
    InvalidAgeException(int age){
        this->age=age;
    }
    const char* what(){
        return "Error: You cannot apply for Competition as your age is below 18.";
    }
};
int main(){
    int age;
    cout<<"Enter your age:";
    cin>>age;
    try{
        if(age<18){
            InvalidAgeException obj(age);
            throw obj;
        }
        else{
            cout<<"You are eligible to apply."<<endl;
        }
    }
    catch(InvalidAgeException& obj){
        cout<<obj.what()<<endl;
    }
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}
