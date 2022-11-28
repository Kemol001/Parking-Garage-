#ifndef ParkingArea_h
#define ParkingArea_h
#include "Slot.h"
#include "Vehicle.h"
#include <iostream>

using namespace std;

class operations
{
    virtual  bool check_for_slot(Vehicle&){};
    virtual void display_available_slots(Vehicle&){};
    virtual bool free_spot(int){};
    virtual double Calculate_Fee(int,Time&){};
};

class ParkingArea:public operations
{
ParkingArea(int);
static ParkingArea *a;
public:
    int no_slots;
    Slot *garage;
    bool check_for_slot(Vehicle &);
    void display_available_slots(Vehicle &);
    bool free_spot(int);
    double Calculate_Fee(int,Time &);
    void display_vehicle_info(int);
    static ParkingArea* get_instance();
};
ParkingArea* ParkingArea::get_instance()
{
    if(a==nullptr){
        int s;
        cout<<"Enter Size Of Your Garage: ";
        cin>>s;
        a=new ParkingArea(s);}
    return a;
}
ParkingArea::ParkingArea(int ns)
{
    no_slots=ns;
    garage=new Slot[no_slots];
    for(int i=0;i<no_slots;i++){
            cout<<"Enter Slot Number "<<i+1<<" Length And Width :";
            int l,w; cin>>l>>w;
            garage[i].set_length(l);garage[i].set_width(w);
            double area,cost;
            area=(garage[i].get_length()*garage[i].get_width());
            cost=(area/50)*2;
            garage[i].set_cost(cost);
            garage[i].set_availability(1);
    }
}
bool ParkingArea::check_for_slot(Vehicle &obj)
{
    for(int i=0;i<no_slots;i++){
        if(garage[i].get_availability()==1&&garage[i].get_length()>=obj.get_length()&&garage[i].get_width()>=obj.get_width())
            return 1;
            }
            return 0;
}
void ParkingArea::display_available_slots(Vehicle &obj)
{
    for(int i=0;i<no_slots;i++){
        if(garage[i].get_availability()==1&&garage[i].get_length()>=obj.get_length()&&garage[i].get_width()>=obj.get_width()){
            cout<<i+1<<" ";
        }
    }
}

bool ParkingArea::free_spot(int spot_N)
{
    if(garage[spot_N-1].get_availability()==0){
        garage[spot_N-1].set_availability(1);
        return 1;}
    else{
        cout<<"Spot Is Already Empty"<<endl;
        return 0;}
}
double ParkingArea::Calculate_Fee(int sn,Time &leaving_time)
{
    double stay_time,fee;
    stay_time=garage[sn-1].get_time().calc_stay_time(leaving_time);
    fee=stay_time*garage[sn-1].get_cost();
    return fee;
}
void ParkingArea::display_vehicle_info(int sn)
{
    if(garage[sn].get_availability()==0)
        garage[sn].print_vehicle();
    else
        cout<<"This Slot Is Empty"<<endl;
}
ParkingArea *ParkingArea::a=nullptr;
#endif // ParkingArea_h
