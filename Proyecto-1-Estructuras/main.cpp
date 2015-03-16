#include <iostream>

using namespace std;
///---------------------------------------------INFORMACION-----------------------------------------------------///
/*Fecha de inicio: 09 de marzo
*/
///------------------------------------------------------------------------------------------------------------///

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
};

struct electricalDevices{
    double kilowhatts;
    struct electricalDevices *next;
    electricalDevices(double k){
        kilowhatts = k;
        next = NULL;
    }
};

struct localitySector{

};

struct localityHome{

};

struct personConsumption{

};

int main()
{

    return 0;
}
