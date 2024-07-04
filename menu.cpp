#include <iostream>

using namespace std;

#include "rlutil.h"
#include "misFunciones.h"


/// A MENU LE PEDIMOS LOS DOS DATOS ESTOS DE ARRAY PARA MOVERNOS CON EL RANKING
void menu (int puntajeMayor[3], string nombreDelMayorPuntaje[3])
{
    int opcion;
    rlutil::locate (40,6);
    cout << "-----------------------------------------" << endl;
    rlutil::locate (40,7);
    cout << "-- BIENVENIDO AL JUEGO CIEN O ESCALERA --" << endl;
    rlutil::locate (40,8);
    cout << "-----------------------------------------" << endl;
    rlutil::locate (40,10);
    cout << " 1- EMPEZAR NUEVO JUEGO DE UN JUGADOR" << endl;
    rlutil::locate (40,11);
    cout << " 2- EMPEZAR NUEVO JUEGO DE DOS JUGADORES" << endl;
    rlutil::locate (40,12);
    cout << " 3- RANKING " << endl;
    rlutil::locate (40,13);
    cout << " 4- REGLAS " << endl;
    rlutil::locate (40,14);
    cout << " 5- SIMULACION" << endl;
    rlutil::locate (40,15);
    cout << " 0- FINALIZAR JUEGO" << endl;
    rlutil::locate (41,17);
    cout << "INGRESE SU OPCION: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system ("cls");
        modoUnJugador(puntajeMayor, nombreDelMayorPuntaje);
        break;
    case 2:
        system ("cls");
        modoDosJugadores(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 3:
        system ("cls");
        ranking(puntajeMayor, nombreDelMayorPuntaje);
        break;
        case 4:
        system ("cls");
        reglas(puntajeMayor, nombreDelMayorPuntaje);
        break;
    case 5:
        system ("cls");
        Simulacion(puntajeMayor, nombreDelMayorPuntaje);
        break;
    case 0:
        return ;
    }
}

