#include<iostream>
#include<iomanip>
using namespace std;
class Time{
    private:
        int ss;
        int mm;
        int hh;
    public:
        void display(){
            cout<<hh<<":"<<mm<<":"<<ss<<endl;
        }
    // Time(){
    //     ss=0;
    //     mm=0;
    //     hh=0;
    // }
    Time():hh(0),mm(0),ss(0){}
    Time(int a,int b,int c){
        hh=a;
        mm=b;
        ss=c;
    }
    void display()const{
        cout<<setfill('0')<<setw(2)<<hh<<":";
        cout<<setfill('0')<<setw(2)<<mm<<":";
        cout<<setfill('0')<<setw(2)<<ss;
    }
    Time operator + (Time temp){
        this->hh=this->hh+temp.hh;
        this->mm=this->mm+temp.mm;
        this->ss=this->ss+temp.ss;
        if(this->ss>60){
            int x=this->ss/60;
            this->ss%=60;
            this->mm+=x;
        }
        if(this->mm>60){
            int y=this->mm/60;
            this->mm%=60;
            this->mm+=y;
        }
        return *this;
    }

};

int main(){
    Time t1;
    Time t2(5,45,45);
    Time t3(10,45,45);
    Time t4=t2+t3;
    cout<<"Result time:"<<endl;
    t4.display();
    t1.display();
    t2.display();
    t3.display();
    return 0;
}