#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
using namespace std;
//NUESTRAS FUNCIONES

void reglas(int puntajeMayor[], string nombreDelMayorPuntaje[]); /// PAGINA CON LA REGLAMENTACION
void menu(int puntajeMayor[], string nombreDelMayorPuntaje[]); /// PAGINA DE MENU
void modoUnJugador(int puntajeMayor[], string nombreDelMayorPuntaje[]); /// MODO DE UN JUGADOR
void modoDosJugadores(int puntajeMayor[], string nombreDelMayorPuntaje[]);  /// MODO DOS JUGADORES
int tirar (int posx, int posy); /// FUNCION PARA TIRAR LOS DADOS DE A UNO
int puntaje(int vNumDados[]); /// FUNCION PARA VER QUE PUNTAJE OBTUVIMOS EN LOS TRES LANZAMIENTOS
int tirarAEleccion (int numero, int posx, int posy, int op); /// FUNCION PARA QUE UNO PUEDA ELEGIR QUE NUMERO DE DADO QUIERA QUE SALGA
void Simulacion(int puntajeMayor[], string nombreDelMayorPuntaje[]);  /// PAGINA DE SIMULACION
void ranking(int puntajeMayor[], string nombreDelMayorPuntaje[]);  /// PAGINA DE RANKING
void copa(int x, int y );
void actualizarRanking(int puntaje, string nombre, int puntajeMayor[], string nombreDelMayorPuntaje[]); /// FUNCION PARA ACTUALIZAR EL RANKING GENERAL
void sonrisa(int x, int y );
void ojos(int x, int y );
void corona(int x, int y );
void triste (int x, int y);

#endif // MISFUNCIONES_H_INCLUDED
