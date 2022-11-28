#ifndef Reserving_h
#define Reserving_h
#include<iostream>
#include"ParkingArea.h"
#include"Slot.h"
using namespace std;

class Reserving
{
public:
    virtual void reserve_spot(Vehicle&,Time&){};
};

class FirstFit : public Reserving
{
    ParkingArea *Area;
public:
    FirstFit(ParkingArea *a){Area=a;};
    void reserve_spot(Vehicle&,Time&);
};

void FirstFit::reserve_spot(Vehicle &obj,Time &obj2)
{
   for(int i=0;i<Area->no_slots;i++){
            if(Area->garage[i].get_availability()==1){
                if(Area->garage[i].get_length()>=obj.get_length()&&Area->garage[i].get_width()>=obj.get_width()){
                        Area->garage[i].set_availability(0);
                        Area->garage[i].set_time(obj2);
                        Area->garage[i].set_vehicle(obj);
                        cout<<"Reserved Spot Number : "<<i+1<<" You Will Pay "<<Area->garage[i].get_cost()<<" LE Per Hour"<<endl;
                        break;
                        }}
}
}
class BestFit : public Reserving
{
    ParkingArea *Area;
public:
    BestFit(ParkingArea *a){Area=a;};
    void reserve_spot(Vehicle&,Time&);
};
void BestFit::reserve_spot(Vehicle &obj,Time &obj2)
{
    int temp=0;
        int _count=0;
        for(int i=0;i<Area->no_slots;i++){
            if(Area->garage[i].get_availability()==1){
                if(Area->garage[i].get_length()>=obj.get_length()&&Area->garage[i].get_width()>=obj.get_width()){
                    _count++;
            }}
        }
        int arr[_count];
        int j=0;
        for(int i=0;i<Area->no_slots;i++){
            if(Area->garage[i].get_availability()==1)
                if(Area->garage[i].get_length()>=obj.get_length()&&Area->garage[i].get_width()>=obj.get_width()){
                    arr[j]=i;
                    j++;
            }
            else
                continue;
        }
        for(int i=1;i<_count;i++){
                if((Area->garage[arr[i]].get_length()<=Area->garage[temp].get_length())&&Area->garage[arr[i]].get_width()<=Area->garage[temp].get_width()){
                    temp=arr[i];
                    }}
            Area->garage[temp].set_availability(0);
            Area->garage[temp].set_time(obj2);
            Area->garage[temp].set_vehicle(obj);
            cout<<"Reserved Spot Number : "<<temp+1<<" You Will Pay "<<Area->garage[temp].get_cost()<<" LE Per Hour"<<endl;
}
#endif // Reserving_h
