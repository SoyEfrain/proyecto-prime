#include "jugar.h"
#include <iostream>
using namespace std;

void gamePlay()
{
    //system("cls");
    cout << "ARRANCA EL JUEGO" << endl;
    int puntosJugador1 = 0;
    int puntosJugador2 = 0;
    const int RONDAS = 3;

    const int TAM = 5;    /// TAM -> LA CANTIDAD DE DADOS
    int tiradaDados[TAM]; /// LA TIRADA DE 5 DADOS

    /// RONDAS
    for (int i = 1; i <= RONDAS; i++)
    {
        cout << "RONDA #" << i << endl;
        /// TURNOS
        for (int j = 1; j <= 2; j++)
        {
            /// TURNO DEL JUGADOR 1
            if (j == 1)
            {
                cout << "JUGADOR 1" << endl;
                generarTirada(tiradaDados, TAM);
                mostrarTirada(tiradaDados, TAM);
                puntosJugador1 += obtenerPuntos(tiradaDados, TAM);
            }
            /// TURNO DEL JUGADOR
            cout << endl;
            if (j == 2)
            {
                cout << "JUGADOR 2" << endl;
                generarTirada(tiradaDados, TAM);
                mostrarTirada(tiradaDados, TAM);
                puntosJugador2 += obtenerPuntos(tiradaDados, TAM);
            }
            cout << endl;
        }
    }

    cout << "PUNTOS JUGADOR 1: " << puntosJugador1 << endl;
    cout << "PUNTOS JUGADOR 2: " << puntosJugador2 << endl;
}

void generarTirada(int vec[], int tam)
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

int obtenerDadoAleatorio(int caras)
{
    return (rand() % caras) + 1;
}

int calcularPuntaje(int dados[], int tam)
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

    // puntajes por repetidos
    for (int i = 0; i < tam; i++)
    {
        if (repeticiones[i] == 5)
        {
            puntaje = puntajeDiceMaster; // dice master
            break;
        }
        else if (repeticiones[i] == 4)
        {
            puntaje = puntajeCuadruple; // cuadruple
            break;
        }
        else if (repeticiones[i] == 3)
        {
            puntaje = puntajeTrio; // trio
            for (int j = 0; j < 6; j++)
            {
                if (repeticiones[j] == 2)
                {
                    puntaje = puntajeFull; // full
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
        cout << "Cantidad de Seguidos desde la pos " << i << ": " << cantidadSeguidos[i] << endl;
    }
    int maxSeguidos = 0;
    for (int i = 0; i < 5; i++)
    {
        if (cantidadSeguidos[i] > maxSeguidos)
        {
            maxSeguidos = cantidadSeguidos[i];
        }
    }
    cout << "cantidad maxima de numeros seguidos: " << maxSeguidos << endl;

    if (maxSeguidos == 5)
    {
        puntaje = puntajeEscaleraGrande;
    }
    else if (maxSeguidos == 4 && puntaje < puntajeEscaleraPequenia)
    {
        puntaje = puntajeEscaleraPequenia;
    }

    return puntaje;
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