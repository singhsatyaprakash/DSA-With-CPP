#include<iostream>
#include<iomanip>
using namespace std;
class Time{
    private:
        int ss;
        int mm;
        int hh;
    public:
        // Constructor initialization
        Time(): hh(0), mm(0), ss(0){}
        Time(int a,int b,int c): hh(a), mm(b), ss(c){}
        // Display the time in HH:MM:SS format
        void display()const{
            cout<<setfill('0')<<setw(2)<<hh<<":"<<setfill('0')<<setw(2)<<mm<<":"<<setfill('0')<<setw(2)<<ss<<endl;
        }
        // Operator + overloading for adding two Time objects
        Time operator +(Time temp){
            Time result;
            result.hh=hh + temp.hh;
            result.mm=mm + temp.mm;
            result.ss=ss + temp.ss;
            // Adjust seconds and minutes if they exceed 60
            if(result.ss>=60){
                result.mm +=result.ss/60;
                result.ss%=60;
            }
            if(result.mm>=60){
                result.hh +=result.mm/60;
                result.mm %=60;
            }
            return result;
        }
};

int main(){
    Time t1;
    Time t2(5,45,45);
    Time t3(10,45,45);
    Time t4 =t2 +t3; // Add two time objects

    cout<<"Individual times:"<<endl;
    t1.display();
    t2.display();
    t3.display();
    cout<<"Result time:"<<endl;
    t4.display();
    cout << "****************************************************************************" << endl;
    cout << "Prepared and Executed By: Satya Prakash Singh  CSE3(A1)  ClassRollNo: 61" << endl;
    cout << "****************************************************************************" << endl;
    return 0;
}
