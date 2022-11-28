#ifndef Time_h
#define Time_h
#include <iostream>

using namespace std;

class Time
{
    int Hours,Minutes,daycount;
    string Day;
public:
    Time(){Hours=00;Minutes=00;Day="Sunday";daycount=1;};
    Time(int,int,string);
    double calc_stay_time(const Time &);
    friend ostream& operator<<(ostream& os,const Time& T);
};

ostream& operator<<(ostream& os,const Time& T)
{
    os<<T.Day<<" : "<<T.Hours<<" : "<<T.Minutes;
}

Time::Time(int h,int m,string d)
{
    if (h<=23)
        Hours=h;
    else{
        cout<<"Hour Is Not Correct And Is Set To 00"<<endl;
        Hours=00;}
    if (m<=59)
        Minutes=m;
    else{
        cout<<"Minutes Is Not Correct And Is Set To 00"<<endl;
        Minutes=00;}
    if (d=="sunday"){
        Day=d; daycount=1;
    }
    else if (d=="monday"){
        Day=d; daycount=2;
    }
    else if(d=="tuesday"){
        Day=d; daycount=3;
    }
    else if(d=="wednesday"){
        Day=d; daycount=4;
    }
    else if(d=="thursday"){
        Day=d; daycount=5;
    }
    else if(d=="friday"){
        Day=d; daycount=6;
    }
    else if(d=="saturday"){
        Day=d; daycount=7;
    }
    else{
        cout<<"Day Is not Correct And Is Set To Sunday"<<endl; Day="sunday"; daycount=1;
    }
}
double Time::calc_stay_time(const Time &obj)
{
    double minutes_stayed;
    double hours_stayed;
    if(Day!=obj.Day){
            if((obj.daycount-daycount)<0){
                    minutes_stayed=(60-Minutes)+(60*(24-Hours))+(60*(24*(7-(daycount+1))))+(60*(24*obj.daycount-1))+(60*obj.Hours)+obj.Minutes;
                    hours_stayed=(minutes_stayed/60);
                    return hours_stayed;}
            else if(obj.daycount-daycount>0){
                    minutes_stayed=(60-Minutes)+(60*(24-Hours-1))+(60*(24*(obj.daycount-daycount-1)))+(60*obj.Hours)+(obj.Minutes);
                    hours_stayed=(minutes_stayed/60);
                    return hours_stayed;}}
    else{
        minutes_stayed=(60-Minutes)+(60*(obj.Hours-(Hours+1)))+obj.Minutes;
        hours_stayed=(minutes_stayed/60);
        return hours_stayed;
    }
}

#endif // Time_h

