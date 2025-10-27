#include "menu.h"
#include "jugar.h"
#include <iostream>

using namespace std;

void menu()
{
    char opcion;
    do
    {
        /// MUESTRA LAS OPCIONES
        opciones();
        cout << "INGRESE UNA OPCION: ";
        cin >> opcion;
        cout << endl;
        
        switch(toupper(opcion))
        {
        case 'J':
            gamePlay();
            break;
        case 'E':
            cout << "ESTADISTICA" << endl;
            break;
        case 'S':
            cout << "SALIR DEL JUEGO" << endl;
            return;
            break;
        default:
            cout << "OPCION INVALIDA" << endl;
            break;
        }
        system("pause");
    }
    while(true);
}

void opciones()
{
    system("cls");
    cout << "J - JUGAR " << endl;
    cout << "E - ESTADISTICAS " << endl;
    cout << "S - SALIR " << endl;
}
