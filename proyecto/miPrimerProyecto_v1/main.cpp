#include <iostream>
/// USAMOS PARA GENERAR UNA SEMILLA
#include <ctime>
//#include "menu.h"
#include "jugar.cpp"

using namespace std;

int main() {

    /// GENERO LA SEMILLA
    //srand(time(0));

    //menu();
    int dados[] = {5,2,1,4,3};
    int puntaje = calcularPuntaje(dados , 5);
    cout << endl << endl << "puntaje: " << puntaje << endl << endl;

    return 0;
}
