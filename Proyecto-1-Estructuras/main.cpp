#include <iostream>

using namespace std;
///---------------------------------------------INFORMACION-----------------------------------------------------///
/*
Fecha de inicio: 09 de marzo
Creadores: Raquel Mora Rojas
           Andrés García Salas

Hora de inicio: 4:30 pm
*/
///------------------------------------------------------------------------------------------------------------///

struct Persona {
    string nombre;
    int cedula;
    string apellidos;
    struct Persona *sig;
    Persona(string nombre, int cedula, string apellidos){
        nombre = n;
        cedula = c;
        apellidos = a;
        sig = NULL;
    }
}*primeroP;



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
