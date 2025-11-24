#include <iostream>
/// USAMOS PARA GENERAR UNA SEMILLA
#include <ctime>

#include "menu.cpp"
#include "struct.h"

using namespace std;

int main() {

    /// GENERO LA SEMILLA
    srand(time(0));
    
    const int hs_cant = 5;
    score highscores[hs_cant];

    for(int i = 0 ; i < hs_cant ; i++ ){
        highscores[i].nombre = "vacio";
        highscores[i].puntaje = 0;
    }

    
    menu(highscores, hs_cant);


    //cout << endl << endl << highscores[0].nombre << endl << endl ;
    //int dados[] = {5,2,1,4,3};
    //int puntaje = calcularPuntaje(dados , 5);
    //cout << endl << endl << "puntaje: " << puntaje << endl << endl;

    return 0;
}

