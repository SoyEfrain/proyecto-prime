#include <iostream>

#include "clear.h"
#include "struct.h"
using namespace std;

int obtenerDadoAleatorio(int caras)
{
    return (rand() % caras) + 1;
}

int encontrarIndice(int vec[], int tam, int valor)
{
    for (int i = 0; i < tam; i++)
    {
        if (vec[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

void opcionesJugar(){
    cout << "1 - Un jugador" << endl;
    cout << "2 - Dos jugadores" << endl;
    cout << "0 - Salir" << endl;
    
}

void relanzarUno(int vec[], int tam, int indice)
{
    vec[indice] = obtenerDadoAleatorio(6);
}

void lanzarTodos(int vec[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vec[i] = obtenerDadoAleatorio(6);
    }
}

void mostrarTirada(int vec[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << vec[i] << " ";
    }
}

int obtenerPuntos(int vec[], int tam)
{
    int sumaTotal = 0;
    for (int i = 0; i < tam; i++)
    {
        sumaTotal += vec[i];
    }
    return sumaTotal;
}


int calcularPuntaje(int dados[], int tam, string& tipoPuntaje)
{
    int puntaje = 0;

    int mayorDado = 0;
    const int puntajeDiceMaster = 50;
    const int puntajeCuadruple = 40;
    const int puntajeFull = 30;
    const int puntajeTrio = 20;
    const int puntajeEscaleraGrande = 60;
    const int puntajeEscaleraPequenia = 40;

    int repeticiones[6] = {0};
    for (int i = 0; i < tam; i++)
    {
        if (dados[i] > mayorDado)
        {
            mayorDado = dados[i];
        }

        repeticiones[dados[i] - 1]++;
    }

    puntaje = mayorDado;
    tipoPuntaje = "Chance";
    // puntajes por repetidos
    for (int i = 0; i < tam; i++)
    {
        if (repeticiones[i] == 5)
        {
            puntaje = puntajeDiceMaster; // dice master
            tipoPuntaje = "Dice Master";
            break;
        }
        else if (repeticiones[i] == 4)
        {
            puntaje = puntajeCuadruple; // cuadruple
            tipoPuntaje = "Cuadruple";
            break;
        }
        else if (repeticiones[i] == 3)
        {
            puntaje = puntajeTrio; // trio
            tipoPuntaje = "Trio";
            for (int j = 0; j < 6; j++)
            {
                if (repeticiones[j] == 2)
                {
                    puntaje = puntajeFull; // full
                    tipoPuntaje = "Full";
                    break;
                }
            }
            break;
        }
    }


    // puntajes por escalera
    bool escaleraGrande = true;
    bool escaleraPequenia = true;

    int escalera[] = {1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5};

    int comienzoEscalera;
    int cantidadSeguidos[5] = {0};
    bool encontroSiguiente;
    for (int i = 0; i < tam; i++)
    {
        comienzoEscalera = encontrarIndice(escalera, 6, dados[i]);

        for (int j = 0; j < tam; j++)
        {
            for (int p = 0; p < tam; p++)
            {
                encontroSiguiente = false;
                if (dados[p] == escalera[comienzoEscalera + cantidadSeguidos[i]])
                {
                    cantidadSeguidos[i]++;
                    encontroSiguiente = true;
                    break;
                }
            }
            if (!encontroSiguiente)
            {
                break;
            }
            
            
        }
        //cout << "Cantidad de Seguidos desde la pos " << i << ": " << cantidadSeguidos[i] << endl;
    }
    int maxSeguidos = 0;
    for (int i = 0; i < 5; i++)
    {
        if (cantidadSeguidos[i] > maxSeguidos)
        {
            maxSeguidos = cantidadSeguidos[i];
        }
    }
    //cout << "cantidad maxima de numeros seguidos: " << maxSeguidos << endl;

    if (maxSeguidos == 5)
    {
        puntaje = puntajeEscaleraGrande;
        tipoPuntaje = "Escalera Grande";
    }
    else if (maxSeguidos == 4 && puntaje < puntajeEscaleraPequenia)
    {
        puntaje = puntajeEscaleraPequenia;
        tipoPuntaje = "Escalera Chica";
    }

    return puntaje;
}

bool decidirRelanzar(int dados[], int tam){
    cout << "Desea relanzar algun dado? " << endl;
    cout << "U - relanzar uno" << endl;
    cout << "T - relanzar todos" << endl;
    cout << "N - no relanzar" << endl;
    cout << ": ";
    char eleccion;
    int dadoARelanzar;
    cin >> eleccion;
    switch (toupper(eleccion))
    {
    case 'U':
        cout << "dado a relanzar (1 - 5):";
        cin >> dadoARelanzar;
        relanzarUno(dados, tam, dadoARelanzar - 1);
        break;

    case 'T':
        lanzarTodos(dados, tam);
        break;

    case 'N':
        return false;
        break;
    
    default:
        break;
    }

    return true;
}

score turnoJuego(string nombreJugador){
    score nuevoScore;
    nuevoScore.nombre = nombreJugador;
    
    const int cantidadDados = 5;
    int dados[cantidadDados];
    string combinacion;

    lanzarTodos(dados, cantidadDados);
    mostrarTirada(dados, cantidadDados);
    cout << endl << "puntaje actual: " << calcularPuntaje(dados, cantidadDados, combinacion) << endl;
    cout << "Combinacion: " << combinacion << endl;

    if (decidirRelanzar(dados, cantidadDados))
    {
        cout << "Tirada despues de relanzar: ";
        mostrarTirada(dados, cantidadDados);
        cout << endl << "puntaje actual: " << calcularPuntaje(dados, cantidadDados, combinacion) << endl;
        cout << "Combinacion: " << combinacion << endl;

        if (decidirRelanzar(dados, cantidadDados))
        {
            cout << "Tirada despues de relanzar: ";
            mostrarTirada(dados, cantidadDados);
            cout << endl;
            //cout << endl << "puntaje actual: " << calcularPuntaje(dados, cantidadDados) << endl;
        }
    }
    cout << "Fin del turno" << endl << endl;
    nuevoScore.puntaje = calcularPuntaje(dados, cantidadDados, combinacion);
    cout << "puntaje final: " << nuevoScore.puntaje << endl;
    cout << "Combinacion: " << combinacion << endl << endl;
    
    return nuevoScore;
}

score unJugador(){
    //string nombre;
    score nuevoScore;
    string nombre;
    cout << "ingrese su nombre: ";
    cin >> nombre;

    nuevoScore = turnoJuego(nombre);

    cout << "puntaje: " << nuevoScore.puntaje << endl;
    return nuevoScore;
}

score dosJugadores(){
    string nombreJ1;
    cout << "ingrese el nombre del jugador 1: ";
    cin >> nombreJ1;

    string nombreJ2;
    cout << "ingrese el nombre del jugador 2: ";
    cin >> nombreJ2;
    
    cout << endl << "Turno de " << nombreJ1 << endl;
    score scoreJ1 = turnoJuego(nombreJ1);
    //cout << endl << "Puntaje de " << nombreJ1 << ": " << scoreJ1.puntaje << endl;

    cout << endl << "Turno de " << nombreJ2 << endl;
    score scoreJ2 = turnoJuego(nombreJ2);
    //cout << endl << "Puntaje de " << nombreJ2 << ": " << scoreJ2.puntaje << endl << endl;

    if (scoreJ1.puntaje > scoreJ2.puntaje)
    {
        cout << "Gana " << nombreJ1 << endl;
        return scoreJ1;
    }
    else if (scoreJ2.puntaje > scoreJ1.puntaje)
    {
        cout << "Gana " << nombreJ2 << endl;
        return scoreJ2;
    }
    else
    {
        cout << "Empate" << endl;
        return scoreJ1;
    }
}

void analizarPuntaje(score vec[], int tam, score scoreNuevo)
{
for (int i = 0; i < tam; i++)
{
    if (scoreNuevo.puntaje > vec[i].puntaje)
    {
        for (int j = tam - 1; j > i; j--)
        {
            vec[j] = vec[j - 1];
        }
        vec[i] = scoreNuevo;
        break;
    }
}
}

void menuJugar(score highscores[], int hs_cant){
    int eleccion;
    do
    {
        /// MUESTRA LAS OPCIONES
        //clear();
        cout << "++++++++++++++++++" << endl;
        cout << "** DICE MASTERS **" << endl;
        cout << "++++++++++++++++++" << endl;
        opcionesJugar();
        cout << ": ";
        cin >> eleccion;
        cout << endl;

        score nuevoScore;
        nuevoScore.puntaje = 0;
        nuevoScore.nombre = "vacio";

        switch(eleccion)
        {
            case 1:
                nuevoScore = unJugador();
                break;
            case 2:
                nuevoScore = dosJugadores();
                break;
            case 0:
                return;
                break;
            default:
                cout << "OPCION INVALIDA" << endl;
                system("pause");
                break;
        }
        analizarPuntaje(highscores, hs_cant, nuevoScore);
    }
    while(true);
}

