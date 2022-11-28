#include <iostream>
#include "ParkingArea.h"
#include "ParkGate.h"
using namespace std;
//Karim Amr Hamdy Mohamed-20206138
//Shrouk Ashraf Ramadan-20206131

int main()
{
    ParkGate G(ParkingArea::get_instance());
    cout<<"Your Garage Is Ready Now Choose An Action: "<<endl;
    int choice;
    do{
        cout<<"1)Park A New Vehicle"<<endl<<"2)Vehicle Wants To Leave"<<endl<<"3)Display Total Vehicles Served"<<endl
        <<"4)Display Total Income"<<endl<<"5)Display Car Info In Slot"<<endl<<"6)Exit"<<endl;
        cin>>choice;
        if(choice==1){
              G.Park_In();
        }
        if(choice==2){
                G.Park_out();
        }
        if(choice==3){
            cout<<"Total Vehicles Served: "<<TotalVehicles<<endl;}
        if(choice==4){
            cout<<"Total Income: "<<TotalIncome<<endl;}
        if(choice==5){
            cout<<"Enter Slot Number : ";
            int sn; cin>>sn;
            ParkingArea::get_instance()->display_vehicle_info(sn-1);
        }

    }while(choice!=6);
    return 0;

}
