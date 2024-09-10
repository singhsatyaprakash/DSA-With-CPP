//Banking System
#include<iostream>
using namespace std;
class Account{
private:
    int PIN;
protected:
    double balance;
    double intersetRate;
public:
    string AccountNumber;
    string AccountHolderName;
    //constructor..
    Account(string A,string b,double c,double d,int e){
        AccountNumber=A;
        AccountHolderName=b;
        balance=c;
        intersetRate=d;
        PIN=e;
    }
    void DisplayAccountInfo()const{
        cout<<"Account Number:"<<AccountNumber<<endl;
        cout<<"Account Holder Name:"<<AccountHolderName<<endl;
        cout<<"Balance:"<<balance<<endl;
    }
};
class SavingsAccount:public Account{
public:
    SavingsAccount(string accNumber,string accHolderName,double bal,double rate,int pinCode):Account(accNumber,accHolderName,bal,rate,pinCode){}
    void calculateInterset(){
        double interest=balance*(intersetRate/100);
        cout<<"Interset Earned:"<<interest<<endl;
    }
    //function overrriding...
    void DisplayAccountInfo()const{
        Account::DisplayAccountInfo();
        cout<<"Interset Rate:"<<intersetRate<<"%"<<endl;
    }
};
class CheckingAccount:protected Account{
    public:
    CheckingAccount(string accNumber,string accHolderName,double bal,double rate,int pinCode):Account(accNumber,accHolderName,bal,rate,pinCode){}
    void applyOverDraftFee(){
        double overDraftFee=30.0;//fixed overdraft fee
        balance-=overDraftFee;
        cout<<"OverDraft Fee applided:"<<overDraftFee<<endl;
    }
    void DisplayAccountInfo()const{
        cout<<"Checcking account Info:"<<endl;
        Account::DisplayAccountInfo();
        cout<<"Balance:"<<balance<<endl;
    }
};
int main(){
    SavingsAccount savings("SA12345","Satya",1500.0,5.0,9369);
    cout<<"Savings Account Details:"<<endl;
    savings.DisplayAccountInfo();
    savings.calculateInterset();
    cout<<endl;

    CheckingAccount Checking("CA67890","Deepa",2000.0,0.0,9889);
    cout<<"Checking Account Details:"<<endl;
    Checking.DisplayAccountInfo();
    Checking.applyOverDraftFee();
    Checking.DisplayAccountInfo();
    cout<<endl;
    return 0;
}