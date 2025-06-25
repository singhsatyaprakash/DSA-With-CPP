#include<iostream>
#include<exception>
#include<string>
using namespace std;
//function to validate account
void validateAccount(const string& account){
    if(account.empty()){
        throw invalid_argument("Invalid account:Account Number is empty.");
    }
}
//function to process fund transfer.
void transferFunds(const string& account, double balance,double amount){
    try{
        validateAccount(account);
        if(balance<amount){
            throw runtime_error("Insufficient balance for the transfer.");
        }
        //simulate fund transfer
        cout<<"Transferring $ "<<amount<<"to account:"<<account<<endl;
    }
    catch(const exception& e){
        cerr<<"Error in transferFunds:"<<e.what()<<endl;
        throw;//rethrow the exception to be handled at higher level
    }
}
int main(){
    try{
        string account;
        cout<<"Transfer to Account:";
        getline(cin,account);
        double balance=500.0;
        double amount;
        cout<<"Enter amount to transfer:";
        cin>>amount;
        transferFunds(account,balance,amount);
    }
    catch(const invalid_argument& e){
        cout<<"User Notification:"<<e.what()<<endl;
    }
    catch(const runtime_error& e){
        cout<<"User Notification:"<<e.what()<<endl; 
    }
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl; 
    return 0; 
}
