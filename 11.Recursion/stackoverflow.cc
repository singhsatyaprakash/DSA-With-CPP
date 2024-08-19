#include<iostream>
using namespace std;
//infinite recursion...
void fun(){
    cout<<"Function is called..."<<endl;
    fun();
}
int main(){
    fun();
}