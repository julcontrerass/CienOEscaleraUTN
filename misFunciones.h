#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
using namespace std;
//NUESTRAS FUNCIONES
void lanzarDados();
void reglas(int puntajeMayor[3], string nombreDelMayorPuntaje[3]);
void menu(int puntajeMayor[3], string nombreDelMayorPuntaje[3]);
void modoUnJugador(int puntajeMayor[], string nombreDelMayorPuntaje[]);
void modoDosJugadores(int puntajeMayor[], string nombreDelMayorPuntaje[]);
int tirar (int posx, int posy);
int puntaje(int vNumDados[]);
int tirarAEleccion (int numero, int posx, int posy, int op);
void Simulacion(int puntajeMayor[3], string nombreDelMayorPuntaje[3]);
void ranking(int puntajeMayor[], string nombreDelMayorPuntaje[]);
void copa(int x, int y );
void actualizarRanking(int puntaje, string nombre, int puntajeMayor[], string nombreDelMayorPuntaje[]);
void sonrisa(int x, int y );
void ojos(int x, int y );
void corona(int x, int y );
void triste (int x, int y);

#endif // MISFUNCIONES_H_INCLUDED
