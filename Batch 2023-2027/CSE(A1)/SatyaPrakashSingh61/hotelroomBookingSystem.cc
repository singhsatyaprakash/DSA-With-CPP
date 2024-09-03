#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Room{
public:
    int RoomNumber;
    string type;
    double price;
    bool isAvailable;
    //Constructor to initial the room...
    Room(int rNum,string rType,double rPrice){
        RoomNumber=rNum;
        type=rType;
        price=rPrice;
        isAvailable=true;//Initailly,all room are avialable
    }
    //Fuction to book room...
    void BookRoom(){
        if(isAvailable){
            isAvailable=false;
            cout<<"Room "<<RoomNumber<<" has been suceesfully booked!"<<endl;
        }else{
            cout<<"Sorry,Room "<<RoomNumber<<" is already booked!"<<endl;
        }
    }
    //Function to cancel room...
    void cancelbooking(){
        if(!isAvailable){
            isAvailable=true;
            cout<<"Booking for Room "<<RoomNumber<<" has been suceesfully canceled!"<<endl;
        }else{
            cout<<"Room "<<RoomNumber<<" is not booked,so cannot cancel!"<<endl;
        }
    }
    void DispalyRoomInfo(){
       
        cout<<setw(25)<<RoomNumber<<setw(25)<<type<<setw(25)<<price<<setw(25)<<(isAvailable?"Available":"Booked")<<endl;
    }
};
int main(){
    const int NumberOfRooms=5;
    //array of pointer to object...
    Room* hotelRooms[NumberOfRooms];
    hotelRooms[0]=new Room(101,"Single",50.0);
    hotelRooms[1]=new Room(102,"Single",50.0);
    hotelRooms[2]=new Room(201,"Double",80.0);
    hotelRooms[3]=new Room(202,"Double",80.0);
    hotelRooms[4]=new Room(301,"Suite",150.0);

    int choice;
    do{
        cout<<"\n# Hotel Booking System"<<endl;
        cout<<"1.Dispaly All Rooms.."<<endl;
        cout<<"2.Book a Room.."<<endl;
        cout<<"3.Cancel Booking"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"\nAvialable rooms:\n";
                cout<<setw(25)<<"Room Number"<<setw(25)<<"Type"<<setw(25)<<"Price"<<setw(25)<<"Availability"<<endl;
                for(int i=0;i<NumberOfRooms;i++){
                    hotelRooms[i]->DispalyRoomInfo();
                }
                break;
            }
            case 2:{
                int roomNum;
                cout<<"Enter room number to book:";
                cin>>roomNum;
                bool found=false;
                for(int i=0;i<NumberOfRooms;i++){
                    if(hotelRooms[i]->RoomNumber==roomNum){
                        hotelRooms[i]->BookRoom();
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Room Number "<<roomNum<<" Does not exist!"<<endl;
                }
                break;
            }
            case 3:{
                int roomNum;
                cout<<"Enter room number to cancel:";
                cin>>roomNum;
                bool found=false;
                for(int i=0;i<NumberOfRooms;i++){
                    if(hotelRooms[i]->RoomNumber==roomNum){
                        hotelRooms[i]->cancelbooking();
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Room Number "<<roomNum<<" Does not exist!"<<endl;
                }
                break;
            }
            case 4:{
                cout<<"Exiting the system.Thank you!"<<endl;
                break;
            }
            default:
            cout<<"Invalid choice!Please try again."<<endl;
        }

    }while(choice!=4);
    return 0;
} 