#include<iostream>
using namespace std;
class Print{
    public:
    ///function overloading...
       void show(int x){
        cout<<"int:"<<x<<endl;
       }
       void show(string x){
        cout<<"string:"<<x<<endl;
       }
};
int main(){
    Print obj1;
    obj1.show(25);
    obj1.show("Satya");
    return 0;
}