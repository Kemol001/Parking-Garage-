#ifndef Slot_h
#define Slot_h
#include<string>
#include "Time.h"
#include "Vehicle.h"
using namespace std;

class Slot
{
    Vehicle _vehicle;
    Time Arrival_Time;
    int length,width;
    double cost_per_hour;
    bool available;
public:
    Slot(){};
    void set_vehicle(Vehicle&);
    void set_time(Time &t){Arrival_Time=t;}
    void set_length(int l){length=l;}
    void set_width(int w){width=w;}
    void set_cost(double c){cost_per_hour=c;}
    void set_availability(bool a){available=a;}
    Time get_time(){return Arrival_Time;}
    void print_vehicle();
    int get_length(){return length;}
    int get_width(){return width;}
    double get_cost(){return cost_per_hour;}
    bool get_availability(){return available;}
};
void Slot::set_vehicle(Vehicle &obj)
{
    _vehicle=obj;
}

void Slot::print_vehicle()
{
    cout<<"Vehicle Model Name: "<<_vehicle.get_modelname()<<endl;
    cout<<"Vehicle ModelYear : "<<_vehicle.get_modelyear()<<endl;
    cout<<"Vehicle Length : "<<_vehicle.get_length()<<endl;
    cout<<"Vehicle Width : "<<_vehicle.get_width()<<endl;
    cout<<"Vehicle Owner Number : "<<_vehicle.get_PhoneNo()<<endl;
}
#endif // Slot_h
