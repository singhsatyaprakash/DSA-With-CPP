#include<iostream>
using namespace std;
class Complex{
    int real;
    int img;
    public:
       Complex (int r,int i){
        real=r;
        img=i;
       }
       void numShow(){
        cout<<real<<" + "<<img<<"i"<<endl;
       }
       ///operator overloading
       Complex operator +(Complex & c2){
        int resReal=this->real + c2.real;//this->real refers to???? Ans:calling object of class...
        int resImg=this->img + c2.img;
        Complex c3( resReal,resImg);
        return c3;

       }
};
int main(){
    Complex c1(13,2);
    Complex c2(-3,4);
    c1.numShow();
    c2.numShow();
    Complex c3=c1+c2;/// c1 is calling  function and c2 is pass as argument.
    cout<<"____________"<<endl;
    c3.numShow();
    // c1.numShow();
    return 0;
}
