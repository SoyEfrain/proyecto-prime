#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

/// DECLARACIONES DE LAS FUNCIONES
void gamePlay();
void generarTirada(int vec[], int tam);
///generarTirada(int *vec, int tam);
void mostrarTirada(int vec[], int tam);
int obtenerPuntos(int vec[], int tam);
int obtenerDadoAleatorio(int caras);
int encontrarIndice(int vec[], int tam, int valor);
int calcularPuntaje(int vec[] , int tam);
#endif // JUGAR_H_INCLUDED
