#include <iostream>

using namespace std;
///---------------------------------------------INFORMATION-----------------------------------------------------///
/*
Starting Date: March 09
Creators: Raquel Mora Rojas
          Andrés Garcia Salas

Begin Hour: 4:30 pm
*/
///-------------------------------------Declaration of the structures-----------------------------------------///

struct Persons{
    int id;
    string name;
    string lastName;
    int age;
    struct Persons *next;
    struct Persons *bef;
    Persons(int i, string n, string l, int a){
        id = i;
        name = n;
        lastName = l;
        age = a;
        next = NULL;
        bef = NULL;
    }
}*firstP;

struct electricalDevices{
    double kilowatts;
    struct electricalDevices *next;
    electricalDevices(double k){
        kilowatts = k;
        next = NULL;
    }
}*firstED;

struct Sector {
    string type;
    string name;
    string trend;
    int percent;
    struct Sector * next;
    Sector(string type, string name, string trend, int percent){
        type = t;
        name = n;
        trend = tr;
        percent = p;
        next = NULL;
    }
}*firstS;

struct Energy{
    string name;
    int usagePercentage;
    struct Energy * next;
    Energy(string name, int usagePercentage){
        name = n;
        usagePercentage = u;
        next = NULL;
    }
}*firstE;

struct Locality{
    string name;
    double energyIntake;
    struct Locality *next;
    struct Home * linkH;
    struct localitySector * linkLS;
    Locality(string name, double energyIntake){
        name = n;
        energyIntake = e;
        next = NULL;
    }
}*firstL;

struct Home{
    string code;
    string address;
    struct Home * next;
    struct Intake * linkI;
    Home(string code, string address){
        code = c;
        address = a;
        next = NULL;
    }
};

struct Intake{
    struct Intake * next;
    struct electricalDevices * linkED;
    struct Energy * linkE;
    struct Sector * linkS;
};

struct localitySector{
    struct Sector * linkS;
    struct localitySector * next;
}*firstLS;

struct homePersons{
    struct Persons * linkP;
    struct homePersons * next;
}*firstHP;

int main()
{

    return 0;
}
