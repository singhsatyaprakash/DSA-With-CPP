#include<iostream>
#include<vector>
using namespace std;
class Card{
    string cardnum;
    public:
        Card(string cardnum){
            this->cardnum=cardnum;
        }
        virtual void checkcard(string)=0;
};
class MasterCard:public Card{
    public:
    MasterCard(string cardnum):Card(cardnum){}
    void checkcard(string CardNumber){
        if((CardNumber.size()==16) && (CardNumber[0]=='5') && ((CardNumber[1]=='1' ||CardNumber[1]=='2' ||CardNumber[1]=='3' ||CardNumber[1]=='4'||CardNumber[1]=='5'))){
            cout<<"Valid! Card is MasterCard."<<endl;
        }
        else{
        cout<<"Invalid Card."<<endl;
        }
    }
};
class Visa:public Card{
    public:
    Visa(string cardnum):Card(cardnum){}
    void checkcard(string CardNumber){
        if((CardNumber.size()==13 ||CardNumber.size()==16) && (CardNumber[0]=='4')){
            cout<<"Valid! Card is Visa."<<endl;
        }
        else{
        cout<<"Invalid Card."<<endl;
        }
    }
};
class AmericanExpress:public Card{
    public:
    AmericanExpress(string cardnum):Card(cardnum){}
    void checkcard(string CardNumber){
        if((CardNumber.size()==15) && (CardNumber[0]=='3') && ((CardNumber[1]=='4'||CardNumber[1]=='7'))){
            cout<<"Valid! Card is AmericanExpress."<<endl;
        }
        else{
        cout<<"Invalid Card."<<endl;
        }
    }
};

int main(){
    Card *ref;
    string cardnum;
    cout<<"Enter card number: ";
    getline(cin,cardnum);
    cout<<"MENU:"<<endl;
    cout<<"Press[1] for MasterCard."<<endl;
    cout<<"Press[2] for Visa."<<endl;
    cout<<"Press[3] for American Express."<<endl;
    cout<<"Press[0] for exit."<<endl;
    int n;//for option choose..
    do{
        cout<<"Choice:";
        cin>>n;
        switch(n){
            case 1:{
                MasterCard card(cardnum);
                ref=&card;
                ref->checkcard(cardnum);
                break;
            }
            case 2:{
                Visa card(cardnum);
                ref=&card;
                ref->checkcard(cardnum);
                break;
            }
            case 3:{
                AmericanExpress card(cardnum);
                ref=&card;
                ref->checkcard(cardnum);
                break;
            }
            case 0:cout<<"Exiting system."<<endl;
            default:
            cout<<"Invalid choice."<<endl;
        }    
    }while(n!=0);
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}