#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

using namespace std;

void lanzarDados();
int main();
void modoUnJugador();
int tirar (int posx, int posy);
int puntaje(int vNumDados[]);
int tirarAEleccion (int numero, int posx, int posy);
void Simulacion();
void Puntuacion();
void copa(int x , int y );
void actualizarRanking(int puntaje, string nombre);

#endif // MISFUNCIONES_H_INCLUDED
