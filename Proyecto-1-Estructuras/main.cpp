#include <iostream>
#include <stdlib.h>

using namespace std;
///---------------------------------------------INFORMATION-----------------------------------------------------///
/*
Starting Date: March 09
Creators: Andrés Garcia Salas
          Raquel Mora Rojas


Begin Hour: 4:30 pm
*/
///-------------------------------------Declaration of the structures-----------------------------------------///

// Main list's group structures
struct Locality{
    int id;
    string name;
    double energyIntake;
    struct Locality *next;
    struct Home * firstH;
    struct localitySector * linkLS;
    Locality(int i,string n, double eI){
        id = i;
        name = n;
        energyIntake = eI;
        next = NULL;
    }
}*firstL;

// se supone no deberia existir, se crea para ser sublista
struct Home{
    int code;
    string address;
    struct Home * next;
    struct Intake * linkI;
    Home(int c, string ad){
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
    int id;
    string type;
    string name;
    int percent;
    struct Sector * next;
    Sector(int i, string t, string n, int p){
        id = i;
        type = t;
        name = n;
        percent = p;
        next = NULL;
    }
}*firstS;

struct electricalDevices{
<<<<<<< HEAD
    int id;
=======
>>>>>>> origin/master
    string name;
    double kilowatts;
    int intakeEnergyPerHour;
    struct electricalDevices *next;
<<<<<<< HEAD
    electricalDevices(int i, string n,double k, int iEPH){
        id = i;
        name = n;
        kilowatts = k;
        intakeEnergyPerHour = iEPH;
=======
    electricalDevices(string n,double k, int i){
        name = n;
        kilowatts = k;
        intakeEnergyPerHour = i;
>>>>>>> origin/master
        next = NULL;
    }
}*firstED;

struct Energy{
    int id;
    string name;
    int usagePercentage;
    struct Energy * next;
    Energy(int i, string n, int uP){
        id = i;
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

///------------------------ Declaration of Apparence's Methods----------------------///

void insertMenu();
void insertMenuCout();
void reportMenu();
void reportMenuCout();
void consultMenu();
void consultMenuCout();
void mainMenuCout();
void mainMenu();

///-------------------------------- End of Structures ------------------------------///

///-------------------------------- Insert Methods ---------------------------------///
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

void insertLocality(int id, string name, double energyIntake){
    struct Locality * nn = new Locality(id, name, energyIntake);

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
<<<<<<< HEAD
        cout<<"Data Insert Correctly!\n";
=======
<<<<<<< HEAD
=======
>>>>>>> origin/master
    }
}

void insertSector(int id, string type, string name,int percent){
    struct Sector * nn = new Sector(id, type, name, percent);

    if(firstS == NULL)
        firstS = nn;
    else{
        struct Sector * temp = firstS;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = nn;
>>>>>>> origin/master
    }
    cout<<"Data Insert Correctly!\n";
}

<<<<<<< HEAD
void insertElectricalDevices(int id, string name, double killowats, int intakeEnergyPerHour){
    struct electricalDevices * nn = new electricalDevices(id, name, killowats, intakeEnergyPerHour);
=======
void insertElectricalDevices(string name, double killowats, int intakeEnergyPerHour){
    struct electricalDevices * nn = new electricalDevices(name, killowats, intakeEnergyPerHour);
>>>>>>> origin/master

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
    cout<<"Data Insert Correctly!\n";
}

void insertEnergy(int id, string name, int usagePercentage){
    struct Energy * nn = new Energy(id, name, usagePercentage);

    if(firstE == NULL)
        firstE = nn;
    else{
        struct Energy * temp = firstE;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = nn;
    }
    cout<<"Data Insert Correctly!\n";
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
<<<<<<< HEAD
    }
    cout<<"Data Insert Correctly!\n";
}
///--------------------------------- Searches ----------------------------///

struct Locality * searchL (int id){
    struct Locality * temp = firstL;

    if(firstL == NULL)
        return NULL;
    do{
        if(temp -> id == id)
            return temp;
        temp = temp -> next;
    }while(temp != firstL);

    return NULL;
};

struct  Home * searchH (string nameLocality, int searchCode){
    struct Locality * tempL = searchL(nameLocality);
    struct Home * temp = tempL -> firstH;

    if((tempL  == NULL)||(temp  == NULL))
        return NULL;
    for (;temp != NULL; temp = temp -> next){
        if(temp -> code == searchCode)
            return temp;
    }
    return NULL;
};

struct  Persons * searchP (int id){
    struct Persons * temp = firstP;

    if(firstP == NULL)
        return NULL;
    for (;temp != NULL; temp = temp -> next){
        if(temp -> id == id)
            return temp;
    }
    return NULL;
};

struct  Sector * searchS (int id){
    struct Sector * temp = firstS;

    if(firstS == NULL)
        return NULL;
    for (;temp != NULL; temp = temp -> next){
        if(temp -> id == id)
            return temp;
    }
    return NULL;
};

struct  Energy * searchE (int id){
    struct Energy * temp = firstE;

    if(firstS == NULL)
        return NULL;
    for (;temp != NULL; temp = temp -> next){
        if(temp -> id == id)
            return temp;
    }
    return NULL;
};

struct  electricalDevices * searchED (int id){
    struct electricalDevices * temp = firstED;

    if(firstED == NULL)
        return NULL;
    for (;temp != NULL; temp = temp -> next){
        if(temp -> id == id)
            return temp;
    }
    return NULL;
};

///------------------------------- End of Searches -------------------------///

///------------------------------- Relation Methods ------------------------///

void localitySectorRelation(int idLocality, int idSector){
    struct Locality * local = searchL(idLocality);
    struct Sector * sect = searchS(idSector);

    if (local == NULL){
        cout<<"Locality doesn't found!";
        return;
    }else if (sect == NULL){
        cout<<"Sector doesn't found!";
        return;
    }


}



///------------------------------- Output Methods ------------------------///
=======
    }
}
>>>>>>> origin/master

void printLocality(){
	struct Locality * temp = firstL;

	if(temp==NULL)
		cout<<"\nNo hay lista.....\n";
	else{

		do{
            cout<< temp -> id <<", ";
			cout<< temp ->name <<", \n";
			temp = temp->next;
		}while(temp!=firstL);
	}
}

void printElectricalDevices(){
	struct electricalDevices * temp = firstED;
<<<<<<< HEAD

	if(temp==NULL)
		cout<<"\nNo hay lista.....\n";
	else{
        do{
            cout<< temp -> id <<", ";
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
                cout<< temp -> id <<", ";
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

void loadData(){
    insertLocality(1,"San Jose", 5.0);
    insertLocality(2,"Alajuela", 5.0);
    insertLocality(3,"San Jose", 5.0);
    insertLocality(4,"Cartago", 5.0);
    insertLocality(5,"Puntarenas", 5.0);
    insertLocality(6,"Limon", 5.0);
    insertLocality(7,"San Carlos", 5.0);
    insertLocality(8,"Palmera", 5.0);
    insertLocality(9,"Marina", 5.0);
    insertLocality(10,"Aguas Zarcas", 5.0);
    insertLocality(11,"Florencia", 5.0);
    insertLocality(12,"Fortuna", 5.0);
    cout<<"\n\n";
    //Pruebas en el main
    insertElectricalDevices(1,"Licuadora",34.9,45);
    insertElectricalDevices(2,"Lavadora",12.5,1245);
    insertElectricalDevices(3,"Refrigeradora",21.2,124);
    insertElectricalDevices(4,"Horno Microndas",57.1,34);
    insertElectricalDevices(5,"Televisor",86.4,43);
    insertElectricalDevices(6,"Computador",36.9,67);
    cout<<"\n\n";
=======

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
<<<<<<< HEAD
    insertLocality("San Jose", 5.0);
=======
    insertLocality("San jose", 5.0);
>>>>>>> origin/master
    insertLocality("Cartago", 5.0);
    insertLocality("Puntarenas", 5.0);
    insertLocality("Limon", 5.0);
    insertLocality("San Carlos", 5.0);
    insertLocality("Palmera", 5.0);
    insertLocality("Marina", 5.0);
    insertLocality("Aguas Zarcas", 5.0);
    insertLocality("Florencia", 5.0);
    insertLocality("Fortuna", 5.0);

<<<<<<< HEAD
=======
    /*
    Aarón 	27
Adrian 	100
Adur 	26
Agustín 	118
Ahmed 	16
Aimar 	137
Aitor 	407
Alain 	59
Alberto 	236
Alejandro 	127
Alex 	42
Alexander
*/
>>>>>>> origin/master
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

>>>>>>> origin/master
    insertPerson(2098, "Hola", "Bsd", 14, 'A');
    insertPerson(2003, "Mundo", "Bsd", 15, 'B');
    insertPerson(2002, "soy", "Bsd", 16, 'C');
    insertPerson(2000, "xD ", "Bsd", 17, 'D');
    insertPerson(1999, "Yo", "Bsd", 18, 'E');
    insertPerson(2001, "Tu", "Bsd", 19, 'F');
    insertPerson(2045, "Aasd", "Bsd", 20, 'G');
<<<<<<< HEAD
}
//-------------------------------------Aparience Methods--------------------------------
void mainMenuCout(){
    cout<<"\t\t Main Menu\n"<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<"1. Insert Menu."<<endl;
    cout<<"2. Edit Electrical Devices."<<endl;
    cout<<"3. Delete Persons."<<endl;
    cout<<"4. Consult Menu."<<endl;
    cout<<"5. Report Menu."<<endl;
    cout<<"0. Exit."<<endl;
    cout<<"-------------------------------------------"<<endl;
	cout<<"Choose an Option: ";
}

void reportMenuCout(){
    cout<<"\t\t Report Menu\n"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"1. % Intakes per Sector."<<endl;
    cout<<"2. % Intakes per Electrical Devices."<<endl;
    cout<<"3. % Intakes of Energy Sources per month."<<endl;
    cout<<"4. Classification Localities in Energy Consumption."<<endl;
    cout<<"5. Classification Persons in Energy Consumption."<<endl;
    cout<<"6. Electrical Devices in descending order according to Home intake."<<endl;
    cout<<"7. Descending localities in total consumption."<<endl;
    cout<<"0. Back."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Choose an Option: ";
}

void consultMenuCout(){
    cout<<"\t\t Consult Menu\n"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"1. Consult the monthly consumption of the any device 'X' in a locality 'Y'."<<endl;
    cout<<"2. Consult most used Energy Source in a locality."<<endl;
    cout<<"3. Consult in a home, who is the most consumer person."<<endl;
    cout<<"0. Back."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Choose an Option: ";
}

void insertMenuCout(){
    cout<<"\t\t Insert Menu\n"<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<"1. Insert Locality."<<endl;
	cout<<"2. Insert Home."<<endl;
	cout<<"3. Insert Person."<<endl;
	cout<<"4. Insert Sector."<<endl;
	cout<<"5. Insert Electrical Devices."<<endl;
	cout<<"6. Insert Energy."<<endl;
	cout<<"0. Back."<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<"Choose an Option: ";
}

void reportMenu(){
    string option;
    system("cls");

    do{
        reportMenuCout();
        cin >> option;

        if (option == "1")
            cout<<"% Intakes per Sector."<<endl;
        else if (option == "2")
            cout<<"% Intakes per Electrical Devices."<<endl;
        else if (option == "3")
            cout<<"% Intakes of Energy Sources per month."<<endl;
        else if (option == "4")
            cout<<"Classification Localities in Energy Consumption."<<endl;
        else if (option == "5")
            cout<<"Classification Persons in Energy Consumption."<<endl;
        else if (option == "6")
            cout<<"Electrical Devices in descending order according to Home intake."<<endl;
        else if (option == "7")
            cout<<"Descending localities in total consumption."<<endl;
        else if (option == "0")
            system("cls");
        else{
            system("cls");
            cout<<"Error: Invalid Entry! Try Again\n\n";
        }
    }while(option != "0");
}

void consultMenu(){
    string option;
    system("cls");

    do{
        consultMenuCout();
        cin >> option;

        if (option == "1")
            cout<<"1. Consult the monthly consumption of the any device 'X' in a locality 'Y'."<<endl;
        else if (option == "2")
            cout<<"2. Consult most used Energy Source in a locality."<<endl;
        else if (option == "3")
            cout<<"3. Consult in a home, who is the most consumer person."<<endl;
        else if (option == "0")
            system("cls");
        else{
            system("cls");
            cout<<"Error: Invalid Entry! Try Again\n\n";
        }
    }while(option != "0");
}

void insertMenu(){
    string option;
    system("cls");
    do{
        insertMenuCout();
        cin >> option;

        if (option == "1")
            cout<<"Locality."<<endl;
        else if (option == "2")
            cout<<"Home."<<endl;
        else if (option == "3")
            cout<<"Person."<<endl;
        else if (option == "4")
            cout<<"Sector."<<endl;
        else if (option == "5")
            cout<<"Electrical Devices."<<endl;
        else if (option == "6")
            cout<<"6. Insert Energy."<<endl;
        else if (option == "0")
            system("cls");
        else{
            system("cls");
            cout<<"Error: Invalid Entry, Try Again!\n\n";
        }
    }while(option != "0");
}

void mainMenu(){
    string option;
    system("cls");
    do {
        mainMenuCout();

        cin>>option;

        if(option == "1")
                insertMenu();
        else if (option == "2")
            cout<<"2. Edit Electrical Devices."<<endl;
        else if (option == "3")
            cout<<"3. Delete Persons."<<endl;
        else if (option == "4")
            consultMenu();
        else if (option == "5")
            reportMenu();
        else if (option == "0")
            system("cls");
        else{
            system("cls");
            cout<<"Error: Invalid Entry, Try Again!\n\n";
        }
    }while(option != "0");
    cout<<"Thank You! Byeee!!!";
    return;
}

int main(){
    mainMenu();
=======

    cout<<"\n\n";
    printPersons();
>>>>>>> origin/master
    return 0;
}
