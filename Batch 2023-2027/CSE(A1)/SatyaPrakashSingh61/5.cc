/*Create a C++ program to perform survey on four different model of Maruti (Maruti -K10, Zen-Astelo, Wagnor, Maruti- SX4) owned by person living in four metro cities(Delhi, Mumbai, Chennai & Kolkatta). Display tabulated report like format given below:
            Maruti-K10      Zen-Astelo      Wagnor      Maruti-SX4
Delhi
Mumbai
Cheenai
Kolkatta
Calculate numbers of cars of different model in each metro city.*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main(){
    int cars=4,cities=4;  
    // Car models
    string carNames[cars]={"Maruti-K10", "Zen-Astelo", "Wagnor", "Maruti-SX4"};
    // City names
    string cityNames[cities]={"Delhi", "Mumbai", "Chennai", "Kolkata"};

    int survey[4][4]={0};
    int cityChoice,carChoice;
    char moreInput;
        cout << "\nMenu:\n";
        cout << "Select the city:\n";
        cout<<"Press[0] for Maruti-K10"<<endl;
        cout<<"Press[1] for Zen-Astelo"<<endl;
        cout<<"Press[2] for Wagnor"<<endl;
        cout<<"Press[3] for Maruti-SX4"<<endl;
        cout <<"\nSelect the car model:\n";
        cout<<"Press[0] for Delhi"<<endl;
        cout<<"Press[1] for Mumbai"<<endl;
        cout<<"Press[2] for Chennai"<<endl;
        cout<<"Press[3] for Kolkata"<<endl;

    do {
        cout<<"Enter the city index: ";
        cin>>cityChoice;
        cout<<"Enter the car model index: ";
        cin>>carChoice;

        survey[cityChoice][carChoice]++;

        cout<<"Record updated!\n";
        cout<<"Do you want to enter more data? (y/n): ";
        cin>>moreInput;
        
    }while(moreInput=='y'||moreInput=='Y');
    // Display the survey result
    cout<<"\nSurvey Report:\n";   
    // Display header row
    cout<<setw(15)<<"City/Car";
    for(int i=0;i<cars;i++){
        cout<<setw(15)<<carNames[i];
    }
    cout<<endl;
    // Display city rows with car counts
    for(int i=0;i<cities;i++){
        cout<<setw(15)<<cityNames[i];// City name
        for(int j=0;j<cars;j++){
            cout<<setw(15)<<survey[i][j]; // Car count
        }
        cout<<endl;
    }
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}


