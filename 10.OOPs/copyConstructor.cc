#include<iostream>
using namespace std;


class Car{
    public://accesable to anywhere even out of class
       string name;
       string color;
    ///constructor
    Car(){
        cout<<"(c0)calling constructor without parameter...\n";
    }
    Car(string name,string color){
        cout<<"(c1)calling constructor with parameter...\n";
        this->name=name;
        this->color=color;
    }
    // copy constructor...
    Car(Car &c1){//reference
    cout<<"Coyping c1 to c2...\n";
    name=c1.name;
    color=c1.color;
    // color="Silver";///this will only change in object c2...
    }

};
int main(){
    Car c0;
    Car c1("Venue","White");
    Car c2(c1);///copying c1 to c2


    cout<<c0.name<<endl;
    cout<<c0.color<<endl;

    cout<<c1.name<<endl;
    cout<<c1.color<<endl;

    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    return 0;
}