/*
Question 1 : Create a class to store Complex numbers. Using operator overloading, create the logic to subtract one complex number from another.
*/
#include<iostream>
using namespace std;
class Complex{
    public: 
       int real;
       int img;
       //constructor
       Complex (int r,int i){
        real=r;
        img=i;
        }
        void showNum(){
            cout<<real<<" + "<<img<<"i"<<endl;
        }
        //operator overloading
        Complex operator - ( Complex &c2){
            int resReal=real-c2.real;
            int resImg=img-c2.img;
            Complex c3(resReal,resImg);
            return c3;
        }

    
};
int main(){
    Complex c1(2,4);
    Complex c2(3,6);
    Complex c3=c1-c2;
    c3.showNum();
    return 0;
}