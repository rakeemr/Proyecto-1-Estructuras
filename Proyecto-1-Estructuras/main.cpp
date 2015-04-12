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
        firstH = NULL;
    }
}*firstL;

struct Home{
    int code;
    string address;
    struct Home * next;
    struct Intake * firstI;
    struct homePersons * linkHP;
    Home(int c, string ad){
        code = c;
        address = ad;
        next = NULL;
        firstI = NULL;
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
    struct personsIntake * linkPI;
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
    int id;
    string month;
    int intakeEnergy;
    struct Intake * next;
    struct electricalDevices * firstED;
    struct intakeEnergySector * linkIES;
    Intake(int i, string m, int iE){
        id = i;
        month = m;
        intakeEnergy = iE;
        next = NULL;
        firstED = NULL;
    }
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
    int id;
    string name;
    double kilowatts;
    int intakeEnergyPerHour;
    struct electricalDevices *next;
    electricalDevices(int i, string n, double k, int iEPH){
        id = i;
        name = n;
        kilowatts = k;
        intakeEnergyPerHour = iEPH;
        next = NULL;
    }
};

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

///------------------------ Declaration of Sublist's Structures ---------------------///

struct homePersons{
    struct Persons * linkP;
    struct homePersons * next;
};

struct personsIntake{
    struct Intake * linkI;
    struct personsIntake * next;
};

struct localitySector{
    struct Sector * linkS;
    struct localitySector * next;
};

struct intakeEnergySector{
    struct Energy * linkE;
    struct Sector * linkS;
    struct intakeEnergySector * next;
};

///-------------------------------- End of Structures ------------------------------///

///------------------------ Declaration of Apparence's Methods----------------------///

void insertMenu();
void insertMenuCout();
void reportMenu();
void reportMenuCout();
void consultMenu();
void consultMenuCout();
void mainMenuCout();
void mainMenu();

///------------------------------- End of Declaration -----------------------------///

///--------------------------------- Searches -------------------------------------///

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

struct  Home * searchH (int idLocality, int searchCode){
    struct Locality * tempL = searchL(idLocality);

    if (tempL  == NULL)
        return NULL;
    else{
        struct Home * temp = tempL -> firstH;

        if (temp  != NULL){
            for (;temp != NULL; temp = temp -> next){
                if(temp -> code == searchCode)
                    return temp;
            }
        }
    }
    return NULL;
};

struct  Intake * searchI (int idLocality, int searchCode, int idIntake){
    struct Home * tempH = searchH(idLocality, searchCode);

    if (tempH  == NULL)
        return NULL;
    else{
        struct Intake * temp = tempH -> firstI;

        if (temp  != NULL){
            for (;temp != NULL; temp = temp -> next){
                if(temp -> id == idIntake)
                    return temp;
            }
        }
    }
    return NULL;
};

struct  electricalDevices * searchED (int idLocality, int searchCode, int idIntake, int idElectricalDevice){
    struct Intake * tempI = searchI(idLocality, searchCode, idIntake);

    if (tempI  == NULL)
        return NULL;
    else{
        struct electricalDevices * temp = tempI -> firstED;

        if (temp  != NULL){
            do{
                if(temp -> id == idElectricalDevice)
                    return temp;
                temp = temp -> next;
            }while(temp != tempI -> firstED);
        }
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

///------------------------------- End of Searches ---------------------------------///

///---------------- Methods to shorten a few lines of repeated code ---------------///

bool localityDoesntExist(int localityToRoam){
    struct Locality * localNode = searchL(localityToRoam);
    if (localNode == NULL){
        cout<<"\nThe Locality doesn't exist...\n";
        return true;
    }
    return false;
}

bool homeDoesntExist(int localityToRoam, int codeToRoam){
    struct Home * homNode = searchH(localityToRoam, codeToRoam);
    if (homNode == NULL){
        cout<<"\nThe Home doesn't exist...\n";
        return true;
    }
    return false;
}

///-------------------------- End of shortening methods -----------------------------///

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
    struct Locality * localSearch = searchL(nn -> id);

    if (localSearch != NULL){
        cout<<"This locality already exists!\n";
        return;
    }

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
    cout<<"Data Insert Correctly!\n";
}

void insertHome(int idLocality ,int code, string address){
    struct Home * nn = new Home(code, address);
    struct Locality * tempL = searchL(idLocality);

    if (tempL == NULL){
        cout<<"The Locality doesn't exist!\n";
        return ;
    }else{
        struct Home * homSearch = searchH(idLocality, nn -> code);

        if (homSearch != NULL){
            cout<<"This home already exists!\n";
            return;
        }

        if (tempL -> firstH == NULL)
            tempL -> firstH = nn;
        else{
            struct Home * temp = tempL -> firstH;

            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = nn;
        }
        cout<<"Data Insert Correctly!\n";
    }
}

void insertPerson(int id, string name, string lastName, int age, char intakeStandar){
    struct Persons * nn = new Persons(id, name, lastName, age, intakeStandar);
    struct Persons * persoSearch = searchP(nn -> id);

    if (persoSearch != NULL){
        cout<<"This person already exists!\n";
        return;
    }

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
    cout<<"Data Insert Correctly!\n";
}

void insertSector(int id, string type, string name,int percent){
    struct Sector * nn = new Sector(id, type, name, percent);
    struct Sector * secSearch = searchS(nn -> id);

    if (secSearch != NULL){
        cout<<"This sector already exists!\n";
        return;
    }

    if(firstS == NULL)
        firstS = nn;
    else{
        struct Sector * temp = firstS;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = nn;
    }
    cout<<"Data Insert Correctly!\n";
}

void insertEnergy(int id, string name, int usagePercentage){
    struct Energy * nn = new Energy(id, name, usagePercentage);
    struct Energy * eneSearch = searchE(nn -> id);

    if (eneSearch != NULL){
        cout<<"This energy source already exists!\n";
        return;
    }

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

void insertIntake(int idLocality, int searchCode, int id, string month, int intakeEnergy){
    struct Intake * nn = new Intake(id, month, intakeEnergy);

    if (localityDoesntExist(idLocality))
        return ;

    struct Home * tempH = searchH(idLocality, searchCode);
    if (tempH == NULL){
        cout<<"The Home doesn't exist!\n";
        return ;
    }else{
        struct Intake * intakeSearch = searchI(idLocality, searchCode, nn -> id);

        if (intakeSearch != NULL){
            cout<<"This Intake already exists!\n";
            return;
        }

        if (tempH -> firstI == NULL)
            tempH -> firstI = nn;
        else{
            struct Intake * temp = tempH -> firstI;

            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = nn;
        }
        cout<<"Data Insert Correctly!\n";
    }
}

void insertElectricalDevices(int idLocality, int searchCode, int idIntake, int id, string name, double killowats, int intakeEnergyPerHour){
    struct electricalDevices * nn = new electricalDevices(id, name, killowats, intakeEnergyPerHour);

    if (localityDoesntExist(idLocality)||(homeDoesntExist(idLocality, searchCode)))
        return ;

    struct Intake * tempI = searchI(idLocality, searchCode, idIntake);
    if (tempI == NULL){
        cout<<"The Intake doesn't exist!\n";
        return ;
    }else{
        struct electricalDevices * eDSearch = searchED(idLocality, searchCode, idIntake, nn -> id);
        if (eDSearch != NULL){
            cout<<"This electrical device already exists!\n";
            return;
        }

        if (tempI -> firstED == NULL){
            tempI -> firstED = nn;
            nn -> next = nn;
        }else{
            nn -> next = tempI -> firstED;
            struct electricalDevices * temp = tempI -> firstED;
            do{
                temp = temp -> next;
            }while(temp -> next != tempI -> firstED);

            temp -> next = nn;
        }
        cout<<"Data Insert Correctly!\n";
    }
}

///----------------------------- End of Insert Methods ----------------------------///

///------------ Data modification methods of electrical devices -------------------///

void editElectricalDevice(int idLocality, int searchCode, int idIntake, int id, string name, double killowats, int intakeEnergyPerHour){
    if (localityDoesntExist(idLocality)||(homeDoesntExist(idLocality, searchCode)))
        return ;

    struct Intake * tempI = searchI(idLocality, searchCode, idIntake);
    if (tempI == NULL){
        cout<<"The Intake doesn't exist!\n";
        return ;
    }else{
        struct electricalDevices * eDSearch = searchED(idLocality, searchCode, idIntake, id);
        if (eDSearch != NULL){
            eDSearch -> name = name;
            eDSearch -> kilowatts = killowats;
            eDSearch -> intakeEnergyPerHour = intakeEnergyPerHour;
            cout<<"Modifications Completed!\n";
            return;
        }else
            cout<<"The electrical device doesn't exist!\n";
    }
}

///------------------------- End of Modification methods -------------------------///

///------------------------------- Delete Methods --------------------------------///

void deletePersons(int idPerson){
    struct Persons * delPerson = searchP(idPerson);
    if (delPerson == NULL){
		cout<<"The person does not exist, therefore can not be deleted!.\n";
		return ;
    }

    struct Persons * delPersonBef = delPerson -> bef;
    struct Persons * delPersonNext = delPerson -> next;

    if (delPersonBef == NULL){    // if it is the first
        firstP = delPersonNext;
        delPersonNext -> bef = NULL;
	}else if ((delPersonBef != NULL)&&(delPersonNext != NULL)){     // if in the middle
        delPersonBef -> next = delPersonNext;
        delPersonNext -> bef = delPersonBef;
	}else if (delPersonNext == NULL){       // if in the end
        delPersonBef -> next = NULL;
	}
	delete delPerson;   // releases the memory
}

///------------------------------- End of Delete Methods ---------------- - ------///

///------------------------------- Relation Methods ------------------------------///

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

    struct localitySector * nn = new localitySector();
    nn -> linkS = sect;
    nn -> next = local -> linkLS;
    local -> linkLS = nn;
}

void homePersonRelation(int idLocality ,int codeHome, int idPerson){
    struct Home * hom = searchH(idLocality ,codeHome);
    struct Persons * person = searchP(idPerson);

    if (hom == NULL){
        cout<<"Home doesn't found!";
        return;
    }else if (person == NULL){
        cout<<"Person doesn't found!";
        return;
    }

    struct homePersons * nn = new homePersons();
    nn -> linkP = person;
    nn -> next = hom -> linkHP;
    hom -> linkHP = nn;
}

void personIntakeRelation(int idPerson, int idLocality ,int codeHome, int idIntake){
    struct Persons * person = searchP(idPerson);
    struct Intake * intak = searchI(idLocality, codeHome, idIntake);

    if (person == NULL){
        cout<<"Person doesn't found!";
        return;
    }else if (intak == NULL){
        cout<<"Intake doesn't found!";
        return;
    }

    struct personsIntake * nn = new personsIntake();
    nn -> linkI = intak;
    nn -> next = person -> linkPI;
    person -> linkPI = nn;
}

void intakeEnergySectorRelation(int idLocality ,int codeHome, int idIntake, int idEnergy, int idSector){
    struct Intake * intak = searchI(idLocality, codeHome, idIntake);
    struct Energy * ener = searchE(idEnergy);
    struct Sector * sect = searchS(idSector);

    if (intak == NULL){
        cout<<"Intake doesn't found!";
        return;
    }else if (ener == NULL){
        cout<<"Energy doesn't found!";
        return;
    }else if (sect == NULL){
        cout<<"Sector doesn't found!";
        return;
    }

    struct intakeEnergySector * nn = new intakeEnergySector();
    nn -> linkE = ener;
    nn -> linkS = sect;
    nn -> next = intak -> linkIES;
    intak -> linkIES = nn;
}

///--------------------------- End Relation Methods ----------------------///

///------------------------------- Output Methods ------------------------///

void printLocality(){
	struct Locality * temp = firstL;

	if(temp==NULL)
		cout<<"\nThe list doesn't exist...\n";
	else{

		do{
            cout<< temp -> id <<", ";
			cout<< temp ->name <<". \n";
			temp = temp->next;
		}while(temp!=firstL);
	}
}

void printHomes(int localityToRoam){
    struct Locality * localNode = searchL(localityToRoam);
    if (localNode == NULL){
        cout<<"\nThe Locality doesn't exist...\n";
        return ;
    }

	struct Home * temp = localNode -> firstH;

	if(temp == NULL)
		cout<<"\nThe list doesn't exist...\n";
	else{
	    for(;temp != NULL; temp = temp->next){
                cout<< temp -> code <<", ";
            	cout<< temp -> address <<". \n";
	    }
	}
}

void printIntake(int localityToRoam, int codeToRoam){
    if (localityDoesntExist(localityToRoam))
        return;

    struct Home * homNode = searchH(localityToRoam, codeToRoam);
    if (homNode == NULL){
        cout<<"\nThe Home doesn't exist...\n";
        return ;
    }

	struct Intake * temp = homNode -> firstI;
	if(temp == NULL)
		cout<<"\nThe list doesn't exist...\n";
	else{
	    for(;temp != NULL; temp = temp->next){
                cout<< temp -> id <<", ";
                cout<< temp -> month <<", ";
            	cout<< temp -> intakeEnergy <<". \n";
	    }
	}
}

void printElectricalDevice(int localityToRoam, int codeToRoam, int intakeToRoam){
    if (localityDoesntExist(localityToRoam)||(homeDoesntExist(localityToRoam, codeToRoam)))
        return;

    struct Intake * intakeNode = searchI(localityToRoam, codeToRoam, intakeToRoam);
    if (intakeNode == NULL){
        cout<<"\nThe Intake doesn't exist...\n";
        return ;
    }

	struct electricalDevices * temp = intakeNode -> firstED;
	if(temp == NULL)
		cout<<"\nThe list doesn't exist...\n";
	else{
		do{
            cout<< temp -> id <<", ";
            cout<< temp -> name <<", ";
            cout<< temp -> kilowatts <<", ";
            cout<< temp -> intakeEnergyPerHour <<". \n";
			temp = temp->next;
		}while(temp != intakeNode -> firstED);
	}
}

void printPersons(){
	struct Persons * temp = firstP;

	if(temp==NULL)
		cout<<"\nThe list doesn't exist...\n";
	else{
	    for(;temp != NULL; temp = temp->next){
                cout<< temp -> id <<", ";
            	cout<< temp -> name <<", ";
                cout<< temp -> lastName <<", ";
            	cout<< temp -> age <<", ";
            	cout<< temp -> intakeStandar <<". \n";
	    }
	}
}

void printSector(){
	struct Sector * temp = firstS;

	if(temp==NULL)
		cout<<"\nThe list doesn't exist...\n";
	else{
	    for(;temp != NULL; temp = temp->next){
                cout<< temp -> id <<", ";
                cout<< temp -> type <<", ";
            	cout<< temp -> name <<", ";
            	cout<< temp -> percent <<". \n";
	    }
	}
}

void printEnergy(){
	struct Energy * temp = firstE;

	if(temp==NULL)
		cout<<"\nThe list doesn't exist...\n";
	else{
	    for(;temp != NULL; temp = temp->next){
                cout<< temp -> id <<", ";
            	cout<< temp -> name <<", ";
            	cout<< temp -> usagePercentage <<". \n";
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
    insertLocality(7,"asda La pancha", 5.0);
    insertLocality(10,"Aguas Zarcas", 5.0);

    cout<<"\n\n";
    printLocality();
    cout<<"\n\n";


    insertHome(1, 1, "Casa Random.");
    insertHome(5, 1, "Casa Random.");
    insertHome(5, 3, "Casa Random.");
    insertHome(5, 1, "Casa Random.");
    insertHome(8, 1, "Casa Random.");
    insertHome(7, 2, "Casa Random.");
    insertHome(14, 1, "Casa Random.");

    cout<<"\n\n";
    printHomes(5);
    printHomes(14);
    cout<<"\n\n";

    insertPerson(2014160007, "Andres", "Garcia", 20, 'A');
    insertPerson(2014160519, "Raquel", "Mora", 20, 'A');
    insertPerson(2014162433, "Yerlin", "Avila", 20, 'A');
    insertPerson(2013123407, "Leiver", "Rodriguez", 20, 'A');
    insertPerson(2012332313, "Mainor", "Gamboa", 20, 'A');
    insertPerson(2014160007, "Peluca", "Salas", 28, 'A');

    cout<<"\n\n";
    printPersons();
    cout<<"\n\n";

    deletePersons(20141624373);

    cout<<"\n\n";
    printPersons();
    cout<<"\n\n";

    insertSector(1, "Industria", "Automotriz", 10);
    insertSector(2, "Transporte", "Aereo", 10);
    insertSector(3, "Transporte", "Maritimo", 10);
    insertSector(4, "Industria", "Textil", 10);
    insertSector(5, "Servicios", "Comercio", 10);
    insertSector(6, "Servicios", "Hoteles", 10);
    insertSector(1, "Industria", "Automotriz", 10);

    cout<<"\n\n";
    printSector();
    cout<<"\n\n";

    insertIntake(5, 3, 1, "Enero", 80);
    insertIntake(5, 3, 2, "Febrero", 90);
    insertIntake(5, 3, 3, "Marzo", 69);
    insertIntake(5, 3, 1, "Agosto", 60); // equal
    insertIntake(14, 3, 1, "Enero", 80);
    insertIntake(1, 3, 1, "Enero", 60);
    insertIntake(1, 1, 1, "Enero", 80);

    cout<<"\n\n";
    printIntake(5, 3);
    printIntake(13, 3);
    printIntake(1, 3);
    printIntake(1, 1);
    cout<<"\n\n";

    //void insertElectricalDevices(int idLocality, int searchCode, int idIntake, int id, string name, double killowats, int intakeEnergyPerHour){

    insertElectricalDevices(5, 3, 1, 1, "Licuadora", 34.9, 45);
    insertElectricalDevices(5, 3, 1, 2, "Lavadora", 12.5, 1245);
    insertElectricalDevices(14, 3, 1, 3, "Refrigeradora", 21.2, 124);
    insertElectricalDevices(5, 2, 1, 4, "Horno Microndas", 57.1, 34);
    insertElectricalDevices(5, 3, 4, 5, "Televisor", 86.4, 43);
    insertElectricalDevices(5, 3, 1, 6, "Computador", 36.9, 67);

    cout<<"\n\n";
    printElectricalDevice(5, 3, 1);
    printElectricalDevice(14, 3, 1);
    printElectricalDevice(5, 2, 1);
    printElectricalDevice(5, 3, 4);
    cout<<"\n\n";

    editElectricalDevice(5, 3, 1, 1, "Licuadora Gollo", 34.9, 50);

    cout<<"\n\n";
    printElectricalDevice(5, 3, 1);
    cout<<"\n\n";

}

///-------------------------------- End Output Methods -----------------------------------///

///--------------------------------- Aparience Methods -----------------------------------///

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

///------------------------------ End of Aparience Methods -------------------------------///

int main(){
    loadData();
    //mainMenu();
    return 0;
}
