/*Develop a simulation for an autonomous vehicle. Create a base class Vehicle with properties like speed and fuelLevel. Then, derive LandVehicle and FlyingVehicle, where each has unique attributes like wheelCount and altitude. Create a FlyingCar class that inherits from both LandVehicle and FlyingVehicle, demonstrating how a flying car would combine the capabilities of land and aerial vehicles.
*/
#include<iostream>
using namespace std;
//Base class...
class Vehicle{
protected:
    float speed;
    float fuelLevel;
public:
    Vehicle(float spd=0, float fuel=100):speed(spd),fuelLevel(fuel){}
    virtual void display()const{
        cout<<"Speed:"<<speed<<" km/h\nFuel Level: "<<fuelLevel<<"%"<<endl;
    }
};
// LandVehicle class derived from Vehicle...
class LandVehicle:virtual public Vehicle{
protected:
    int wheelCount;
public:
    LandVehicle(int wheels=4,float spd=0,float fuel=100):Vehicle(spd,fuel),wheelCount(wheels){}
    void display()const override{
        Vehicle::display();
        cout<<"Wheel Count: "<<wheelCount<<endl;
    }
};
// FlyingVehicle class derived from Vehicle....
class FlyingVehicle:virtual public Vehicle{
protected:
    float altitude;
public:
    FlyingVehicle(float alt=0,float spd=0,float fuel=100):Vehicle(spd,fuel),altitude(alt){}
    void display()const override{
        Vehicle::display();
        cout<<"Altitude: "<<altitude<< " meters"<<endl;
    }
};
// FlyingCar class derived from both LandVehicle and FlyingVehicle
class FlyingCar: public LandVehicle, public FlyingVehicle {
public:
    FlyingCar(int wheels=4,float alt=0,float spd=0,float fuel=100):Vehicle(spd,fuel),LandVehicle(wheels,spd,fuel),FlyingVehicle(alt,spd,fuel){}
    void display()const override{
        LandVehicle::display();//Display land vehicle details
        cout<<"Altitude: "<<altitude<<" meters"<<endl; // Add flying vehicle details
    }
};
int main(){
    FlyingCar myFlyingCar(4,5000,300,75);//(wheels,altiude,speed,fuel)...
    // Display FlyingCar details
    myFlyingCar.display();
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}