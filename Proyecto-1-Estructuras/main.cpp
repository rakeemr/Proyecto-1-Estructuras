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

// Main list's group structures
struct Locality{
    string name;
    double energyIntake;
    struct Locality *next;
    struct Home * linkH;
    struct localitySector * linkLS;
    Locality(string n, double eI){
        name = n;
        energyIntake = eI;
        next = NULL;
    }
}*firstL;

struct Home{
    string code;
    string address;
    struct Home * next;
    struct Intake * linkI;
    Home(string code, string address){
        code = code;
        address = address;
        next = NULL;
    }
};

struct Persons{
    int id;
    string name;
    string lastName;
    int age;
    char intakeStandar;
    struct Persons *next;
    struct Persons *bef;
    Persons(int i, string n, string l, int a, char s){
        id = i;
        name = n;
        lastName = l;
        age = a;
        intakeStandar = s;
        next = NULL;
        bef = NULL;
    }
}*firstP;

struct Intake{
    struct Intake * next;
    struct electricalDevices * linkED;
    struct Energy * linkE;
    struct Sector * linkS;
};

struct Sector {
    string type;
    string name;
    int percent;
    struct Sector * next;
    Sector(string type, string name, int percent){
        type = type;
        name = name;
        percent = percent;
        next = NULL;
    }
}*firstS;

struct electricalDevices{
    double kilowatts;
    struct electricalDevices *next;
    electricalDevices(double k){
        kilowatts = k;
        next = NULL;
    }
}*firstED;

struct Energy{
    string name;
    int usagePercentage;
    struct Energy * next;
    Energy(string name, int usagePercentage){
        name = name;
        usagePercentage = usagePercentage;
        next = NULL;
    }
}*firstE;

// Sublist's group structures
struct localityHome{
    struct Home * linkS;
    struct localityHome * next;
}*firstLH;

struct homePersons{
    struct Persons * linkP;
    struct homePersons * next;
}*firstHP;

struct personsIntake{
    struct Intake * linkI;
    struct personsIntake * next;
}*firstPI;

struct localitySector{
    struct Sector * linkS;
    struct localitySector * next;
}*firstLS;

struct intakeElectricalDevicesEnergySector{
    struct electricalDevices * linkED;
    struct Energy * linkE;
    struct Sector * linkS;
    struct intakeElectricalDevicesEnergySector * next;
}*firstIEDES;


///--------------------------------End of Structures ------------------------------///
bool isAlphabeticallyGreaterThan(struct Locality * nn, struct Locality * temp, int i){
    int x = nn -> name[i];
    int y = temp -> name[i];
    //  s > a
    if (x > y){
        return false;
    }else if(x = y){
        isAlphabeticallyGreaterThan(nn, temp, i+1);
    }else{
        return true;
    }
}


void insertLocality(string name, double energyIntake){
    struct Locality * nn = new Locality(name, energyIntake);

    if(firstL == NULL){ //Its the first
        firstL = nn;
        nn -> next = nn;
    }else{

        //Busqueda del campo a donde insertar.

        struct Locality * temp = firstL;

        bool alphaOrder = true; // only to initialice.

        do{
            alphaOrder = isAlphabeticallyGreaterThan(nn, temp, 0);

            if (alphaOrder){
                nn -> next = temp -> next;
                temp ->next = nn;
            }
            temp = temp ->next;
        }while(alphaOrder == false);

        /*
        nn -> next = firstL;
        do{
            temp = temp -> next;
        }while(temp -> next != firstL);
        temp -> next = nn;
        firstL = nn;
        */
    }
}

// In process....
void insertElectricalDevices(string name, double energyIntake){
    struct Locality * nn = new Locality(name, energyIntake);

    if(firstL == NULL){ //Its the first
        firstL = nn;
        nn -> next = nn;
    }else{
        struct Locality * temp = firstL;
        nn -> next = firstL;
        do{
            temp = temp -> next;
        }while(temp -> next != firstL);
        temp -> next = nn;
        firstL = nn;
    }
}

void insertSector(string type, string name,int percent){
    struct Sector * nn = new Sector(type, name, percent);

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
    struct Energy * nn = new Energy(name, usagePercentage);

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

void printLocality(){
	struct Locality * temp = firstL;

	if(temp==NULL)
		cout<<"\nNo hay lista.....\n";
	else{

		do{
			cout<< temp ->name <<", \n";
			temp = temp->next;
		}while(temp!=firstL);
	}
}


int main()
{
    cout << "Contruction!!";
    char c = 'A';

    int x = c; // Look ma! No cast!

    cout << "The character '" << c << "' has an ASCII code of " << x << endl;

    insertLocality("alajuela", 5.0);
    insertLocality("san jose", 5.0);
    insertLocality("cartago", 5.0);
    insertLocality("puntarenas", 5.0);
    insertLocality("limon", 5.0);
    printLocality();
    return 0;
}
