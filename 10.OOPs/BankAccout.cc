/*
Question 2 : Create a class BankAccount with private attributes accountNumber and balance. Implement public methods deposit(), withdraw(), and getBalance() to manage the account.
*/

#include<iostream>
using namespace std;
class BankAccount { 
private:
int accountNumber;
double balance;
public:
BankAccount(int accNum, double bal) { 
    accountNumber = accNum;
    balance = bal;
}
void deposit(double amount) { 
    balance += amount;
}
void withdraw(double amount) { 
    if(amount <= balance) {
        balance -= amount;
        } 
        else {
            cout << "No sufficient balance for this withdrawal.\n";
        }
}
double getBalance() {
    return balance;
    }
};
int main() {
BankAccount myAccount(123456, 500.0); 
myAccount.deposit(150.0); 
myAccount.withdraw(100.0);
cout << "Current Balance: Rs." << myAccount.getBalance() << endl;
return 0;
}



// #include<iostream>
// using namespace std;
// class BankAccount{
// private:
//     int accountNumber;
//     float balance;
// public:
//     void deposit(){
//         cout<<"Your money has been deposited...\n";
//     }
//     void withdraw(float withdraw){
//         cout<<"Your money has been withdrawn...\nPlease collect your CASH...\n";
//         float remainBalance=balance-withdraw;
//         setBalance(remainBalance);
//     }
//     void getBalance(BankAccount &customer){
//         cout<<"Your account bank balance is:Rs."<<customer.balance;
//     }
// //setter
// void setAccountNumber(int x ){
//     accountNumber=x;
// }
// void setBalance(float y){
//     balance=y;
// }

    
// };
// int main(){
//     BankAccount customer1;
//     customer1.setAccountNumber(230112058);
//     float rupees;
//     cout<<"How much money you want to deposit:Rs. ";
//     cin>>rupees;
//     customer1.setBalance(rupees);
//     float withdraw;
//     cout<<"How much money you want to withdraw:Rs. ";
//     cin>>withdraw;
//     customer1.withdraw(&withdraw);
//     cout<<"Do you want to check balance??\nIf yes PRESS 'Y'\n else PRESS 'N'\n";
//     char input='N';
//     cin>>input;
//     if(input=='Y'){
//         customer1.getBalance(customer1);
//     }
//     return 0;
// }