#include<iostream>
using namespace std;
class Ride{
    public:
    int km;
    Ride(int km):km(km){}
    virtual int calculateFare()=0;
    virtual void menu()=0;
};
class StandardRide:public Ride{
    int fareperkm=19;
    public:
    StandardRide(int km):Ride(km){}
    int calculateFare(){
        return km*fareperkm;
    }
    void menu(){
        cout<<"Welcome!\nThanks for choosing Standard Ride.\nHere we will drop you at your destination.\nYou can claim:AC / Music\nPrice/km:19"<<endl;
    }
};
class PremiumRide:public Ride{
    int fareperkm=29;
    public:
    PremiumRide(int km):Ride(km){}
    int calculateFare(){
        return km*fareperkm;
    }
    void menu(){
        cout<<"Welcome!\nThanks for choosing Premium Ride.\nHere we will drop you at your destination.\nYou can claim:AC / Music / Water Bottle\nPrice/km:29"<<endl;
    }
};
class CarPoolRide:public Ride{
    int fareperkm=9;
    public:
    CarPoolRide(int km):Ride(km){}
    int calculateFare(){
        return km*fareperkm;
    }
    void menu(){
        cout<<"Welcome!\nThanks for choosing CoolPoolRide.\nHere we will drop you at your destination.\nWe will pick other people b/w ride sorry for inconvience\nPrice/km:19"<<endl;
    }
};
int main(){
    Ride* ref;
    cout<<"*****MENU***********"<<endl;
    cout<<"Press[1] for StandardRide."<<endl;
    cout<<"Press[2] for PremimumRide."<<endl;
    cout<<"Press[3] for CarPoolRide."<<endl;
    cout<<"Press[0] for Exit."<<endl;
    int n,totalfare;
    do{
        cout<<"Choice:";
        cin>>n;
        switch(n){
            case 1:{
                int km;
                cout<<"Total Distance to travel:";
                cin>>km;
                StandardRide s(km);
                ref=&s;
                totalfare=ref->calculateFare();
                ref->menu();
                cout<<"Your Totalfare for distance "<<km<<" is Rs."<<totalfare<<endl;
                break;
            }
            case 2:{
                int km;
                cout<<"Total Distance to travel:";
                cin>>km;
                PremiumRide p(km);
                ref=&p;
                ref->menu();
                totalfare=ref->calculateFare();
                cout<<"Your Totalfare for distance "<<km<<" is Rs."<<totalfare<<endl;
                break;
            }
            case 3:{
                int km;
                cout<<"Total Distance to travel:";
                cin>>km;
                CarPoolRide c(km);
                ref=&c;                
                ref->menu();
                totalfare=ref->calculateFare();
                cout<<"Your Totalfare for distance "<<km<<"km is Rs."<<totalfare<<endl;
                break;
            }
            case 0:cout<<"Exit."<<endl;
            break;
            default:cout<<"Invalid Option!"<<endl;
        }
    }while(n!=0);
    return 0;
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;  
}
