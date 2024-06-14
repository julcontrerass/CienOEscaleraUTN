#include <iostream>
#include <ctime>

using namespace std;
#include "misFunciones.h"

int main()
{
    int opcion;
    // INICIAMOS EL JUEGO CON UNA BIENVENIDA Y CON OPCIONES DE INICIO DE JUEGOS
    cout << "-----------------------------------------" << endl;
    cout << "-- BIENVENIDO AL JUEGO CIEN O ESCALERA --" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    cout << " 1- EMPEZAR NUEVO JUEGO DE UN JUGADOR" << endl;
    cout << " 2- EMPEZAR NUEVO JUEGO DE DOS JUGADORES" << endl;
    cout << " 3- PUNTUACION MAS ALTA" << endl;
    cout << " 4- SIMULACION" << endl;
    cout << " 0- FINALIZAR JUEGO" << endl;
    cout << endl;
    cout << "INGRESE SU OPCION: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system ("cls");
        modoUnJugador();
        break;
    case 2:
        system ("cls");
//        ModoDosJugadores();
        break;
    case 3:
        system ("cls");
        cout << " ESTAMOS EN EL MENU MOSTRANDO LA PUNTUACION";
        break;
    case 4:
        system ("cls");
//        Simulacion();
        break;
    case 0:
        return 0;
    }
    return 0;
}
