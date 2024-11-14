/*26. Define an exception class called “MyNation” that is thrown when a string is not equal to “jai 
hind” or “JAI HIND”.  Write a program that implements this exception.*/
#include<iostream>
#include<string>
#include<exception>
#include<ctype.h>
using namespace std;
class MyNation:public exception{
    public:
    string name;
    MyNation(string name){
        this->name=name;
    }
    const char* what(){
        return " input is not JAI HIND.";
    }
};
int main(){
    string str;
    cout<<"Enter slogan:";
    getline(cin,str);
    try{
        if(str!="jai hind" && str!="JAI HIND"){
            MyNation obj(str);
            throw obj;
        }
        else{
            cout<<"My Nation:"<<str<<endl;
        }
    }
    catch(MyNation& obj){
        cout<<obj.name<<obj.what()<<endl;
    }
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}