#include <iostream>
#include "struct.h"
using namespace std;

void estadisticas(score highscores[], int cant){
    //system("cls");
    cout << "++++++++++++++++++" << endl;
    cout << "** DICE MASTERS **" << endl;
    cout << "++++++++++++++++++" << endl << endl;
    cout << "ESTADISTICAS DEL JUEGO" << endl;

for (int i = 0; i < cant; i++)
{
    cout << i+1 << " - " << highscores[i].nombre << " - " << highscores[i].puntaje << endl;
}
    


}