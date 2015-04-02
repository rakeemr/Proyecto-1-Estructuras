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
    int percent;
    struct Sector * next;
    Sector(string type, string name, int percent){
        type = t;
        name = n;
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

///--------------------------------End of Structures------------------------------///

void insertSector(string type, string name,int percent){
    struct Sector * nn = new Sector(t, n, p);

    if(firstS == NULL)
        firstS = nn;
    else{
        struct Sector * temp = firstS;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = nn;
    }

}

void insertEnergy(string name, int usagePercentage){
    struct Energy * nn = new Energy(n, u);

    if(firstE == NULL)
        firstE = nn;
    else{
        struct Energy * temp = firstE;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = nn;
    }
}

/*void insertLocality(string name, double energyIntake){
    struct Locality * nn = new Locality(n, e);
    if(firstL == NULL)
        firstL = nn;
    else{
        struct Locality * temp = firstL -> next;
        struct Locality * ant = firstL;

        while(temp -> next != firstL){
            if(nn -> name > ant -> name){

            }
        }
    }
}*/

int main()
{
    cout << "Contruction!!";
    return 0;
}
