/*
Develop a simulation for an autonomous vehicle. Create a base class Vehicle with properties like speed and fuelLevel. Then, derive LandVehicle and FlyingVehicle, where each has unique attributes like wheelCount and altitude. Create a FlyingCar class that inherits from both LandVehicle and FlyingVehicle, demonstrating how a flying car would combine the capabilities of land and aerial vehicles.*/
#include<iostream>
using namespace std;
class Vehicle{
public:
    int speed;
    int fuelLevel;
};
class LandVehicle:virtual public Vehicle{
public:
    int wheelCount;
    
};
class FlyingVehicle:virtual public Vehicle{
public:
    int altitude;

};
class FlyingCar:public LandVehicle,public FlyingVehicle{

};
int main(){
    int speed,fuelLevel,wheelCount,altitude;
    cout<<"Speed of car:";
    cin>>speed;
    FlyingCar car(speed,fuelLevel,wheelCount,altitude);
    return 0;
}