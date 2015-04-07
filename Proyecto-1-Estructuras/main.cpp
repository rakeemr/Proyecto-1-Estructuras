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

// se supone no deberia existir, se crea para ser sublista
struct Home{
    string code;
    string address;
    struct Home * next;
    struct Intake * linkI;
    Home(string c, string ad){
        code = c;
        address = ad;
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
        //intakeStandar = s;
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
    Sector(string t, string n, int p){
        type = t;
        name = n;
        percent = p;
        next = NULL;
    }
}*firstS;

struct electricalDevices{
    string name;
    double kilowatts;
    int intakeEnergyPerHour;
    struct electricalDevices *next;
    electricalDevices(string n,double k, int i){
        name = n;
        kilowatts = k;
        intakeEnergyPerHour = i;
        next = NULL;
    }
}*firstED;

struct Energy{
    string name;
    int usagePercentage;
    struct Energy * next;
    Energy(string n, int uP){
        name = n;
        usagePercentage = uP;
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

    if (x > y){
        return false;
    }else if(x < y){
        return true;
    }else if(x == y){
        isAlphabeticallyGreaterThan(nn, temp, i+1);
    }
}

void insertLocality(string name, double energyIntake){
    struct Locality * nn = new Locality(name, energyIntake);

    if(firstL == NULL){ //Its the first
        firstL = nn;
        nn -> next = nn;
    }else{
        struct Locality * temp = firstL;

        bool alphaOrder = true; // only to initialice.
        int j = 0;

        do{
            alphaOrder = isAlphabeticallyGreaterThan(nn, temp, 0);
            struct Locality * bef = temp;

            if (alphaOrder){
                nn -> next = temp;
                do{
                    bef = bef -> next;
                }while(bef -> next != temp);
                bef -> next = nn;
                if(j==0)
                    firstL = nn;
            }else if(temp -> next == firstL){
                nn -> next = temp -> next;
                temp -> next = nn;
                alphaOrder = true;
            }
            temp = temp ->next;
            j++;
        }while(alphaOrder == false);
    }
}

void insertElectricalDevices(string name, double killowats, int intakeEnergyPerHour){
    struct electricalDevices * nn = new electricalDevices(name, killowats, intakeEnergyPerHour);

    if(firstED == NULL){ //Its the first
        firstED = nn;
        nn -> next = nn;
    }else{
        struct electricalDevices * temp = firstED;
        nn -> next = firstED;
        do{
            temp = temp -> next;
        }while(temp -> next != firstED);
        temp -> next = nn;
        firstED = nn;
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

void insertPerson(int id, string name, string lastName, int age, char intakeStandar){
    struct Persons * nn = new Persons(id, name, lastName, age, intakeStandar);
    if(firstP == NULL)
        firstP = nn;
    else{
        struct Persons * actually = firstP;
        struct Persons * bef = NULL;
        while((actually !=NULL)&&(id > actually->id)){
            bef = actually;
            actually = actually -> next;
        }if(actually == NULL){   // insert at the final list
            bef -> next = nn;
            nn -> bef = bef;
        }else if(bef == NULL){    // insert in the begin
            nn -> next = firstP;
            firstP -> bef = nn;
            firstP = nn;
        }else{   // insert in the middle
            bef -> next = nn;
            actually -> bef = nn;
            nn -> next = actually;
            nn -> bef = bef;
        }
    }
}

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

void printElectricalDevices(){
	struct electricalDevices * temp = firstED;

	if(temp==NULL)
		cout<<"\nNo hay lista.....\n";
	else{
        do{
			cout<< temp ->name <<", ";
			cout<< temp ->kilowatts <<", ";
			cout<< temp ->intakeEnergyPerHour <<", \n";

			temp = temp->next;
		}while(temp!=firstED);
	}
}

void printEnergy(){
	struct Energy * temp = firstE;

	if(temp==NULL)
		cout<<"\nNo hay lista.....\n";
	else{
	    for(;temp != NULL; temp = temp->next){
            	cout<< temp -> name <<", ";
            	cout<< temp -> usagePercentage <<", \n";
	    }
	}
}

void printPersons(){
	struct Persons * temp = firstP;

	if(temp==NULL)
		cout<<"\nNo hay lista.....\n";
	else{
	    for(;temp != NULL; temp = temp->next){
                cout<< temp -> id <<", ";
            	cout<< temp -> name <<", ";
                cout<< temp -> lastName <<", ";
            	cout<< temp -> age <<", ";
            	cout<< temp -> intakeStandar <<" \n";
	    }
	}
}

int main()
{
    cout << "Contruction!!";
    char c = 'A';

    int x = c; // Look ma! No cast!

    cout << "The character '" << c << "' has an ASCII code of " << x << endl;

    insertLocality("Alajuela", 5.0);
    insertLocality("San Jose", 5.0);
    insertLocality("Cartago", 5.0);
    insertLocality("Puntarenas", 5.0);
    insertLocality("Limon", 5.0);
    insertLocality("San Carlos", 5.0);
    insertLocality("Palmera", 5.0);
    insertLocality("Marina", 5.0);
    insertLocality("Aguas Zarcas", 5.0);
    insertLocality("Florencia", 5.0);
    insertLocality("Fortuna", 5.0);

    cout<<"\n\n";
    printLocality();

    //Pruebas en el main
    insertElectricalDevices("Licuadora",34.9,45);
    insertElectricalDevices("Lavadora",12.5,1245);
    insertElectricalDevices("Refrigeradora",21.2,124);
    insertElectricalDevices("Horno Microndas",57.1,34);
    insertElectricalDevices("Televisor",86.4,43);
    insertElectricalDevices("Computador",36.9,67);

    cout<<"\n\n";
    printElectricalDevices();

    insertPerson(2098, "Hola", "Bsd", 14, 'A');
    insertPerson(2003, "Mundo", "Bsd", 15, 'B');
    insertPerson(2002, "soy", "Bsd", 16, 'C');
    insertPerson(2000, "xD ", "Bsd", 17, 'D');
    insertPerson(1999, "Yo", "Bsd", 18, 'E');
    insertPerson(2001, "Tu", "Bsd", 19, 'F');
    insertPerson(2045, "Aasd", "Bsd", 20, 'G');

    cout<<"\n\n";
    printPersons();
    return 0;
}
