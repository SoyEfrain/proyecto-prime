
#include "jugar.cpp"
//#include "clear.h"
#include "estadisticas.cpp"
#include "struct.h"
#include <iostream>

using namespace std;


void opciones()
{
    //clear();
    cout << "1 - JUGAR " << endl;
    cout << "2 - ESTADISTICAS " << endl;
    cout << "3 - CREDITOS " << endl;
    cout << "0 - SALIR " << endl;
}

void creditos(){
    //clear();
    cout << "++++++++++++++++++" << endl;
    cout << "** DICE MASTERS **" << endl;
    cout << "++++++++++++++++++" << endl << endl;
    cout << "DESARROLLADO POR: " << endl;
    cout << " Martin " << endl;
    cout << " Efrain " << endl;
    cout << " Juan Pablo " << endl;
    cout << " Nicanor " << endl;
}

void menu(score highscores[], int hs_cant)
{
    int eleccion;
    do
    {
        /// MUESTRA LAS OPCIONES
        //clear();
        cout << "++++++++++++++++++" << endl;
        cout << "** DICE MASTERS **" << endl;
        cout << "++++++++++++++++++" << endl;
        opciones();
        cout << ": ";
        cin >> eleccion;
        cout << endl;
        
        switch(eleccion)
        {
            case 1:
            menuJugar(highscores, hs_cant);
            break;
            case 2:
            estadisticas(highscores, hs_cant);
            //system("pause");
            break;
            case 3:
            creditos();
            //system("pause");
            break;
            case 0:
            cout << "SALIR DEL JUEGO" << endl;
            return;
            break;
            default:
            cout << "OPCION INVALIDA" << endl;
            //system("pause");
            break;
        }
    }
    while(true);
}


