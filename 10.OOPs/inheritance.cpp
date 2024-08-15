#include<iostream>
using namespace std;
class Animal{
    public:
       string color;
       void eat(){
        cout<<"They can eat...\n";
       }
       void breath(){
        cout<<"They can breaths...\n";
       }
};

class Fish:public Animal{ //inheritance of base class Animal to Derives classs Fish...
    public:
       int fins;
       void swim(){
       cout<<"They can swims..."<<endl;
       }

};

int main(){
   // Animal a1("Brown");// no function is present for this call;

cout<<"\n\nOBJECT 1:"<<endl;
   Animal a1;
   a1.color="Brown";
//    a1.fins=4;//cannot accese it is member of fish and here is no derived member...
   cout<<a1.color<<endl;
    a1.eat();
    a1.breath();
//    cout<<"Fins:"<<a1.fins<<endl;//cannot accese it is member of fish and here is no derived member...
//    cout<<a1.swim()<<endl;


cout<<"\n\nOBJECT 2:"<<endl;

   Fish f1;
   f1.color="silver";
   f1.fins=4;
   cout<<f1.color<<endl;
   cout<<"Fins:"<<f1.fins<<endl;
   f1.eat();
   f1.breath();
   f1.swim();

    return 0;
}
