#include<iostream>
#include<string>
using namespace std;
class Card{
    string CardType;
    string CardNumber;
public:
    Card(string CardType,string CardNumber){
        this->CardType=CardType;
        this->CardNumber=CardNumber;
    }
    void checkValidity(int choice){
        switch(choice){
            case 1:{
                if((CardNumber.size()==16) && (CardNumber[0]=='5') && ((CardNumber[1]=='1' ||CardNumber[1]=='2' ||CardNumber[1]=='3' ||CardNumber[1]=='4'||CardNumber[1]=='5'))){
                    cout<<"Valid! Card is MasterCard"<<endl;
                }
                else{
                    cout<<"Invalid Card."<<endl;
                }
                break;
            }
            case 2:{
                if((CardNumber.size()==13 ||CardNumber.size()==16) && (CardNumber[0]=='4')){
                    cout<<"Valid! Card is Visa."<<endl;
                }
                else{
                    cout<<"Invalid Card."<<endl;
                }
                break;
            }
            case 3:{
                if((CardNumber.size()==15) && (CardNumber[0]=='3') && ((CardNumber[1]=='4'||CardNumber[1]=='7'))){
                    cout<<"Valid! Card is American Express."<<endl;
                }
                else{
                    cout<<"Invalid Card."<<endl;
                }
                break;
            }
            default:
            cout<<"Error!!"<<endl;
        }
    }
};
int main(){
    // string varCardType;
    // cout<<"Enter CardType:";
    // getline(cin,varCardType);
    string varCardnumber;
    cout<<"Enter CardNumber:";
    getline(cin,varCardnumber);
    Card c1("Card",varCardnumber);
    cout<<"Press[1] for MasterCard check"<<endl;
    cout<<"Press[2] for VISA check"<<endl;
    cout<<"Press[3] for American Express check"<<endl;
    cout<<"Press[0] to exit.."<<endl;
    
    int choice;
    do{
        cout<<"Choice:";
        cin>>choice;
        switch(choice){
            case 1:c1.checkValidity(1);
            break;
            case 2:c1.checkValidity(2);
            break;
            case 3:c1.checkValidity(3);
            break;
            default:
            cout<<"Invalid Command."<<endl;
        }
    }while(choice!=0);
}