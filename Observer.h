#ifndef Observer_h
#define Observer_h
#include <iostream>
#include<string>
#include "ParkGate.h"
#include "ParkingArea.h"
#include "Time.h"

class Observer
{
    ParkingArea *Area;
public:
    virtual void Update(int,Time&){};
};

class Email : public Observer
{
    ParkingArea *Area;
public:
    Email(ParkingArea *a){Area=a;};
    void Update(int,Time&);
};
void Email::Update(int sn,Time &obj)
{
    cout<<"Type Of Notification : Email"<<endl;
    cout<<"Slot Number : "<<sn+1<<endl;
    cout<<"Slot Cost Per Hour : "<<Area->garage[sn].get_cost()<<endl;
    cout<<"Arrival Time : "<<Area->garage[sn].get_time()<<endl;
    cout<<"Leaving Time : "<<obj<<endl;
    cout<<"Total Hours Parked : "<<Area->garage[sn].get_time().calc_stay_time(obj)<<endl;
    Area->garage[sn].print_vehicle();
    cout<<endl;
}

class SMS : public Observer
{
    ParkingArea *Area;
public:
    SMS(ParkingArea *a){Area=a;};
    void Update(int,Time&);
};
void SMS::Update(int sn,Time &obj)
{
    cout<<"Type Of Notification : SMS"<<endl;
    cout<<"Slot Number : "<<sn+1<<endl;
    cout<<"Slot Cost Per Hour : "<<Area->garage[sn].get_cost()<<endl;
    cout<<"Arrival Time : "<<Area->garage[sn].get_time()<<endl;
    cout<<"Leaving Time : "<<obj<<endl;
    cout<<"Total Hours Parked : "<<Area->garage[sn].get_time().calc_stay_time(obj)<<endl;
    Area->garage[sn].print_vehicle();
    cout<<endl;

};

using namespace std;
#endif // Observer_h
