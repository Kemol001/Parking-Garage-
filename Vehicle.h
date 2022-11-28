#ifndef Vehicle_h
#define Vehicle_h
#include<string>
using namespace std;

int idcount=0;
class Vehicle
{
    string ModelName,PhoneNo,ModelYear;
    int IDNumber,Length,Width;
public:
    Vehicle(){};
    Vehicle(string MN,string MY,int l,int w,string pn){ModelName=MN;IDNumber=idcount;ModelYear=MY;Length=l,Width=w,PhoneNo=pn,idcount++;};
    Vehicle(Vehicle &obj){ModelName=obj.ModelName;ModelYear=obj.ModelYear;Length=obj.Length;Width=obj.Width;PhoneNo=obj.PhoneNo,IDNumber=obj.IDNumber;}
    string get_modelname(){return ModelName;}
    string get_modelyear(){return ModelYear;}
    int get_length(){return Length;}
    int get_width(){return Width;}
    int get_id(){return IDNumber;}
    string get_PhoneNo(){return PhoneNo;}
};
#endif // Vehicle_h
