#include <iostream>

using namespace std;

#include "rlutil.h"
#include "funciones.h"
#include "misFunciones.h"

/// NOS ORDENA EL RANKING MOVIOENDO DE PUESTO DEPENDIENDO DEL VALOR DE CADA UNO
void actualizarRanking(int puntaje, string nombre, int puntajeMayor[], string nombreDelMayorPuntaje[])
{
    for (int i = 0; i < 3; i++)
    {
        if (puntaje > puntajeMayor[i])
        {
            for (int j = 2; j > i; j--)
            {
                puntajeMayor[j] = puntajeMayor[j - 1];
                nombreDelMayorPuntaje[j] = nombreDelMayorPuntaje[j - 1];
            }
            puntajeMayor[i] = puntaje;
            nombreDelMayorPuntaje[i] = nombre;
            break;
        }
    }
}

/// CREAMOS PAGINA DE RANKING
void ranking(int puntajeMayor[], string nombreDelMayorPuntaje[])
{
    int opcion;
    system("cls");
    rlutil::locate (40,3);
    cout << " =================================" << endl;
    rlutil::locate (40,6);
    cout << " --           RANKING           --";
    copa(45, 5);
    copa(63, 5);
    sonrisa(51, 9);
    rlutil::locate (40,12);
    cout << " =================================" << endl;
    rlutil::locate (40,14);
    cout << " PRIMER PUESTO: " << nombreDelMayorPuntaje[0] << " CON " << puntajeMayor[0] << " PUNTOS" << endl;
    rlutil::locate (40,15);
    cout << " SEGUNDO PUESTO: " << nombreDelMayorPuntaje[1] << " CON " << puntajeMayor[1] << " PUNTOS" << endl;
    rlutil::locate (40,16);
    cout << " TERCERO PUESTO: " << nombreDelMayorPuntaje[2] << " CON " << puntajeMayor[2] << " PUNTOS" << endl;
    rlutil::locate (41,18);
    cout << "  ===============================" << endl;
    rlutil::locate (41,19);
    cout << " | 1- MENU                       |" << endl;
    rlutil::locate (41,20);
    cout << " | 0- FINALIZAR JUEGO            |" << endl;
    rlutil::locate (41,21);
    cout << "  ===============================" << endl;
    rlutil::locate (48,23);
    cout << " INGRESE SU OPCION ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system("cls");
        menu(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 0:
        return;
    }
}
