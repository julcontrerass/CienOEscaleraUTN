#include <iostream>
#include <ctime>

using namespace std;

#include "funciones.h"
#include "rlutil.h"

int main()
{
    int opcion, punatateMax1=0, punatateMax2=0;
    // INICIAMOS EL JUEGO CON UNA BIENVENIDA Y CON OPCIONES DE INICIO DE JUEGOS
    rlutil::locate (40,6);
    cout << "-----------------------------------------" << endl;
    rlutil::locate (40,7);
    cout << "-- BIENVENIDO AL JUEGO CIEN O ESCALERA --" << endl;
    rlutil::locate (40,8);

    cout << "-----------------------------------------" << endl;

    cout << endl;
    rlutil::locate (40,10);

    cout << " 1- EMPEZAR NUEVO JUEGO DE UN JUGADOR" << endl;
    rlutil::locate (40,11);

    cout << " 2- EMPEZAR NUEVO JUEGO DE DOS JUGADORES" << endl;
    rlutil::locate (40,12);

    cout << " 3- RANKING MODO UN JUGADOR" << endl;
    rlutil::locate (40,13);

    cout << " 4- RANKING MODO DOS JUGADORES" << endl;
    rlutil::locate (40,14);

    cout << " 5- SIMULACION" << endl;
    rlutil::locate (40,15);

    cout << " 0- FINALIZAR JUEGO" << endl;
    cout << endl;
    rlutil::locate (41,17);
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
        modoDosJugadores();
        break;
    case 3:
        system ("cls");
        puntuacionUnJugador();
        break;
    case 4:
        system ("cls");
        puntuacionDosJugadores();
        break;
    case 5:
        system ("cls");
        Simulacion();
        break;
    case 0:
        return 0;
    }
    return 0;
}

