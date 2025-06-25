/*A class Telcall calculates the monthly phone bill of a consumer. Some of the members of the class are given below: 
Class name: 
Data members/instance variable : phno(phone Number), sname(subscriber Name ) n(number of calls made) and amt (bill amount). 
Member function/methods: 
TelCall() : Parameterized constructor to assign values to data members. 
Void compute( ) : to calculate the phone bill amount base on the slabs given below. 
Void display( ) : to display the details in the specified format. 
Number of calls Rate 
1 – 100 Rs. 500/- rental charge only 
101 – 200 Rs 1.00 per call + rental charge 
201-300 Rs. 1.20 per call + rental charge 
Above 300 Rs. 1.50 per call + rental charge
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Tellcal{
    private:
        string phno;//phone number
        string sname;//suscriber name
        int n;//no. of call
        float billamount;
    public:
        Tellcal(string x,string y,int z){
            n=z;
            sname=x;
            phno=y;
        }
        void compute(){
            if(n<=100){
                billamount=500;
            }
            else if(n<200){
                billamount=500+(n-100)*1;
            }
            else if(n<300){
                billamount=500+100+(n-200)*1.20;
            }
            else{
                billamount=720+(n-300)*1.50;
            }

        }
        void display(){
            cout<<"\n"<<setw(51)<<"******Bharat Sacnhar Nigam Ltd.******"<<"\n"<<endl;
            cout<<"PhoneNumber"<<setw(25)<<"SuscriberName"<<setw(26)<<"No. of Calls"<<setw(25)<<"BillAmount"<<endl;
            cout<<phno<<setw(25)<<sname<<setw(26)<<n<<setw(25)<<billamount<<endl;
        }
};
int main(){
    string vname,vphono;
    int vcall;
    cout<<"Enter suscriber name:";
    getline(cin,vname);
    cout<<"Enter phone number:";
    getline(cin,vphono);
    cout<<"Enter no. of calls:";
    cin>>vcall;
    Tellcal s1(vname,vphono,vcall);
    s1.compute();
    s1.display();
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}