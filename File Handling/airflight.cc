#include<iostream> 
#include<fstream> 
using namespace std; 
class Airlines 
{ 
    private: 
    char tktno[5]; 
    int fare; 
    public: 
    void add() 
    { 
        cout<<"Enter Ticket Number:"; 
        cin.ignore();
        cin>>tktno; 
        cout<<"Enter the Fare:"; 
        cin>>fare; 
    } 
    void display() 
    { 
        cout<<"\nTicket Number is:" <<tktno; 
        cout<<"\nFare is:"<<fare; 
    } 
}; 
int main() 
{ 
    char flname[15]; 
    cout<<"Enter Filename:"; 
    cin>>flname; 
    ofstream flight(flname,ios::out|ios::binary); 
    if(!flight){
        cerr<<"error in opening file"<<endl;
    }
    flight.open(flname); 
    Airlines air; 
    air.add(); 
    flight.write((char*) &air,sizeof(air)); 
    flight.close(); 
    cout<<"\nContents of the File is "<<flname; 
    ifstream flight1; 
    flight1.open(flname,ios::in); 
    flight1.read((char *) &air,sizeof(air)); 
    do 
    { 
        air.display(); 
        flight1.read((char *) &air,sizeof(air)); 
    } while (flight1); 
    flight1.close(); 
    return(0); 
}