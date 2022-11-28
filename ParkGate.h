#ifndef ParkGate_h
#define ParkGate_h
#include<iostream>
#include <string>
#include "Reserving.h"
#include "Observer.h"

int TotalVehicles,i=0;
double TotalIncome=0;
class ParkGate
{
    ParkingArea *Area;
public:
    ParkGate(ParkingArea *a){Area=a;};
    void Park_In();
    void Park_out();
    void Notification(int,Time&);
};
void ParkGate::Park_In()
{
    cout<<"Enter Vehicle ModelName-ModelYear-Vehicle Length-Vehicle Width :";
    string mn,my; int l,w;
    cin>>mn>>my>>l>>w;
    cout<<"Enter Your Phone Number :";
    string pn; cin>>pn;
    Vehicle C(mn,my,l,w,pn);
    if(Area->check_for_slot(C)==1){
            cout<<"Enter Arrival Time(24H Format) In Form Of Hour-Minute-Day:";
            int h,m; string d;
            cin>>h>>m>>d;
            Time T(h,m,d);
            cout<<"Slots That Are Available: ";
            Area->display_available_slots(C);
            cout<<"Choose Method Of Selection"<<endl<<"1)First Fit"<<endl<<"2)Best Fit"<<endl;
            int choice;
            cin>>choice;
            if(choice==1){
                FirstFit f(ParkingArea::get_instance());
                f.reserve_spot(C,T);
                }
            else if(choice==2){
                BestFit f2(ParkingArea::get_instance());
                f2.reserve_spot(C,T);
            }
            cout<<"Enjoy Your Parking"<<endl;}
    else
        cout<<"No Available Slots"<<endl;
}
void ParkGate::Park_out()
{
    cout<<"Enter Your Slot Number : ";
    int sn; cin>>sn;
    if(Area->free_spot(sn)==1){
        int h,m;
        string d;
        cout<<"Enter Time Of Leaving In Form Of Hour-Minute-Day"<<endl;
        cin>>h>>m>>d;
        Time T2(h,m,d);
        Area->Calculate_Fee(sn,T2);
        cout<<"Your Fee Is: "<<Area->Calculate_Fee(sn,T2)<<"LE"<<endl;
        TotalVehicles++;
        TotalIncome+=Area->Calculate_Fee(sn,T2);
        string choice;
        do{
                cout<<"Would You Like A Notfication?(yes/no)"<<endl;
                cin>>choice;
                for (int i = 0; i < choice.length(); i++)
                {
                        choice[i] = tolower(choice[i]);
                }
                if(choice=="yes"){
                    Notification(sn-1,T2);
                    break;}
                else if(choice=="no"){
                    cout<<"Ok No Notification Will Be Sent"<<endl;
                    break;}
                else
                    cout<<"Wrong Input Try Again"<<endl;
        }while(choice!="yes" || choice!="no");
    }
}
void ParkGate::Notification(int sn,Time &obj)
{
    cout<<"Choose Notification Method 1)Email 2)SMS"<<endl;
    int choice;
    do{
    cin>>choice;
    if(choice==1){
        Email e(ParkingArea::get_instance());
        e.Update(sn,obj);
        break;
    }
    else if(choice==2){
        SMS s(ParkingArea::get_instance());
        s.Update(sn,obj);
        break;
    }
    else
        cout<<"Wrong Input Try Again"<<endl;
    }while(choice!=1 || choice!=2);
}

#endif // ParkGate_h
