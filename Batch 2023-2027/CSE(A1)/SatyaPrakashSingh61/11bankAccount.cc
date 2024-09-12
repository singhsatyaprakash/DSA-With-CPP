#include<iostream>
#include<string>
#include<iomanip>
// #include "mylib.cc"
using namespace std;
//Bank Account..
class Bank{
    private:
        string Depositer;
        string AccountNumber;
        string TypeAcccount;
        double balance;
    public:
        Bank(string Depositer,string AccountNumber,string TypeAcccount,double balance){
            this->Depositer=Depositer;
            this->AccountNumber=AccountNumber;
            this->TypeAcccount=TypeAcccount;
            this->balance=balance;
        }
        void deposit(double amount){
            balance+=amount;
        }
        double Dispalybalance(){
            return balance;
        }
        void withdrawal(double withdr){
            if(balance<withdr){
                cout<<"Insufficient bank balance..."<<endl;
                return;
            }
            else{
            balance-=withdr;
            cout<<"Your money debited sucessfully.."<<endl;
            }
        } 
        void displayDetails(){
            cout<<"Account Holder"<<setw(26)<<"Acoount Number"<<setw(26)<<"Account Type"<<setw(26)<<"Balance"<<endl;
            cout<<Depositer<<setw(26)<<AccountNumber<<setw(26)<<TypeAcccount<<setw(26)<<balance<<endl;
        }
};
int main(){
    string vname,vacc,vtype;
    double vbalance;
    cout<<"Enter Account Holder name:";
    getline(cin,vname);
    cout<<"Enter Account Number:";
    getline(cin,vacc);
    cout<<"Enter Account Type:";
    getline(cin,vtype);
    cout<<"Enter Bank Balance:";
    cin>>vbalance;
    Bank c1(vname,vacc,vtype,vbalance);
    int n;
    do{
    cout<<"*******Main Menu********"<<endl;
    cout<<"Press[1] for Deposit..."<<endl;
    cout<<"Press[2] for CheckBalance..."<<endl;
    cout<<"Press[3] for Withdrawn..."<<endl;
    cout<<"Press[4] for Details..."<<endl;
    cout<<"Press:";
    cin>>n;
    switch(n){
        case 1:
        {
        cout<<"How much money have to deposit:";
                double D;
                cin>>D;
                cout<<"Your current balance is:"<<c1.Dispalybalance()<<endl; 
                c1.deposit(D);
                cout<<"Your Amount has been deposited.."<<endl;
                cout<<" Now,Your current balance is:"<<c1.Dispalybalance()<<endl; 
                break;
        }
        case 2:
        {
                cout<<"Your current balance is:"<<c1.Dispalybalance()<<endl; 
                break;
        }
        case 3:
        {
                cout<<"How much you want to withdraw:";
                double w;
                cin>>w;
                c1.withdrawal(w);
                cout<<"Your current balance is:"<<c1.Dispalybalance()<<endl;    
                break;
        }
        case 4:
        {
                c1.displayDetails();
                break;
        }
        case 0:
        {
                cout<<"Thank You For Visit..."<<endl;
                break;
        }
        default:
        cout<<"Invalid Option"<<endl;
    }
    } while(n!=0);
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl
    return 0;
}