#include<iostream>
using namespace std;
class Base{
    public:
        int publicVar;
    protected:
        int protectedVar;
    private:
        int privateVar;
    public:
    Base():publicVar(1),protectedVar(2),privateVar(3){}
    void showVars()const{
        cout<<"Base Class-PublicVar:"<<publicVar<<endl;
        cout<<"Base Class-ProtectedVar:"<<protectedVar<<endl;
        cout<<"Base Class-privateVar:"<<privateVar<<endl;
    }
};
class Derivedpublic:public Base{
    public:
        void accessBaseMembers(){
            cout<<"\nDerivedPulic class (public inheritance)--Accessing Base"<<endl;
            cout<<"PublicVar:"<<publicVar<<endl;
            cout<<"ProtectedVar:"<<protectedVar<<endl;
            cout<<"privateVar not accessible here:"<<endl;
        }

};
class DerivedProtected:protected Base{
    public:
        void accessBaseMembers(){
            cout<<"\nDerivedProtected class (protected inheritance)--Accessing Base"<<endl;
            cout<<"PublicVar:"<<publicVar<<endl;
            cout<<"ProtectedVar:"<<protectedVar<<endl;
            cout<<"privateVar not accessible here:"<<endl;
        }

};
class DerivedPrivate:private Base{
    public:
        void accessBaseMembers(){
            cout<<"\nDerivedPrivate class (private inheritance)--Accessing Base"<<endl;
            cout<<"publicVar not accessible here:"<<endl;
            cout<<"protectedVar not accessible here:"<<endl;
            cout<<"privateVar not accessible here:"<<endl;
        }

};
int main(){
    Derivedpublic ob1;
    DerivedProtected ob2;
    DerivedPrivate ob3;
    ob1.accessBaseMembers();
    ob2.accessBaseMembers();
    ob3.accessBaseMembers();
    return 0;
}