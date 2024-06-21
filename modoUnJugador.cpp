#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "funciones.h"
using namespace std;



void modoUnJugador(int puntajeMayor[], string nombreDelMayorPuntaje[])
{
    string nombre;
    int puntajeTotal = 0, Dados[6], ronda = 1, maximoDeLaRonda = 0, opcion;
    bool finaliza = false;

    ponerCero(Dados, 3);
    rlutil::locate(43, 6);
    cout << "------------------------------------" << endl;
    rlutil::locate(43, 7);
    cout << "----- MODO DE JUEGO UN JUGADOR -----" << endl;
    rlutil::locate(43, 8);
    cout << "------------------------------------" << endl;
    rlutil::locate(40, 10);
    cout << " INGRESE EL NOMBRE DEL JUGADOR PARA INICIAR" << endl;
    rlutil::locate(55, 12);
    cout << "-";
    cin.ignore();
    getline(cin, nombre);

    if (nombre == "")
    {
        system("cls");
        rlutil::locate(40, 10);
        cout << "INGRESE UN NOMBRE O VOLVERA AL MENU..." << endl;
        rlutil::locate(55, 12);
        cout << "-";
        getline(cin, nombre);
        if (nombre == "")
        {
            system("cls");
            main();
        }
    }

    while (finaliza == false)
    {
        int puntajeTiradas[3];
        ponerCero(puntajeTiradas, 3);
        system("cls");
        srand(time(0));
        rlutil::saveDefaultColor();

        for (int i = 0; i < 3; i++)
        {
            system("cls");
            rlutil::locate(36, 2);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(41, 3);
            cout << "JUGADOR: " << nombre;
            rlutil::locate(41, 4);
            cout << "RONDA " << ronda;
            rlutil::locate(41, 5);
            cout << "PUNTAJE TOTAL: " << puntajeTotal << endl;
            rlutil::locate(36, 6);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(41, 7);
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRonda << endl;
            rlutil::locate(41, 8);
            cout << "LANZAMIENTO NUMERO " << i + 1 << endl;
            rlutil::locate(41, 9);
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " << puntajeTiradas[2] << endl;
            rlutil::locate(36, 10);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(38, 12);
            cout << "Presionar espacio para lanzar los dados " << endl;

            for (int j = 0; j<6; j++)
            {
                Dados[j] = tirar((j + 3) * 10, 16);
            }

            puntajeTiradas[i] = puntaje(Dados);
            rlutil::resetColor();
            rlutil::anykey();
            ponerCero(Dados, 3);
        }

        int ubi = maximoVector(puntajeTiradas, 3);

        if (puntajeTiradas[ubi] >= 100)
        {
            finaliza = true;
        }
        int ubiCero = minimoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubiCero] == 0)
        {
            puntajeTotal = 0;
        }
        else
        {
            ubi = maximoVector(puntajeTiradas, 3);
            maximoDeLaRonda = puntajeTiradas[ubi];
            puntajeTotal += puntajeTiradas[ubi];
        }
        if (puntajeTotal >= 100)
        {
            finaliza = true;
        }
        ronda++;
    }

    actualizarRanking(puntajeTotal, nombre, puntajeMayor, nombreDelMayorPuntaje);

    rlutil::setBackgroundColor(rlutil::WHITE);
    system("cls");
    rlutil::setColor(rlutil::BLACK);
    corona(54, 8);
    cout << endl;
    cout << endl;
    rlutil::locate(42, 12);
    cout << "  FELICIDADES GANASTE EL JUEGO!!!!!!" << endl;
    cout << endl;
    rlutil::anykey();
    rlutil::setBackgroundColor(rlutil::BLACK);
    system("cls");
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(35, 3);
    cout << " =====================================================" << endl;
    rlutil::locate(40, 4);
    cout << "   LLEGASTE A " << puntajeTotal << " PUNTOS" << " EN LA RONDA " << ronda << endl;
    rlutil::locate(35, 5);
    cout << " =====================================================" << endl;
    rlutil::locate(45, 8);
    cout << " ==============================" << endl;
    rlutil::locate(45, 9);

    cout << "| 1- EMPEZAR EL JUEGO DE NUEVO  |" << endl;
    rlutil::locate(45, 10);
    cout << "| 2- PUNTUACION MAS ALTA        |" << endl;
    rlutil::locate(45, 11);
    cout << "| 3- IR AL MENU                 |" << endl;
    rlutil::locate(45, 12);
    cout << "| 0- FINALIZAR JUEGO            |" << endl;
    rlutil::locate(45, 13);
    cout << " ==============================" << endl;
    rlutil::locate(52, 15);
    cout << "INGRESE SU OPCION: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        system("cls");
        modoUnJugador(puntajeMayor, nombreDelMayorPuntaje);
        break;
    case 2:
        system("cls");
        puntuacionUnJugador(puntajeMayor, nombreDelMayorPuntaje);
        break;
    case 3:
        system("cls");
        main();
        break;
    case 0:
        return;
    }
    rlutil::resetColor();
}

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

void puntuacionUnJugador(int puntajeMayor[], string nombreDelMayorPuntaje[])
{
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
    cout << " PRIMER PUESTO: " << nombreDelMayorPuntaje[0] << " CON " << puntajeMayor[0] << " PUNTOS " << endl;
    rlutil::locate (40,15);
    cout << " SEGUNDO PUESTO: " << nombreDelMayorPuntaje[1] << " CON " << puntajeMayor[1] << " PUNTOS " << endl;
    rlutil::locate (40,16);
    cout << " TERCER PUESTO: " << nombreDelMayorPuntaje[2] << " CON " << puntajeMayor[2] << " PUNTOS " << endl;
    rlutil::locate (41,18);
    cout << "  ===============================" << endl;
    rlutil::locate (41,19);
    cout << " |     1- VOLVER A MENU          |" << endl;
    rlutil::locate (41,20);
    cout << " |     0- FINALIZAR JUEGO        |" << endl;
    rlutil::locate (41,21);
    cout << "  ===============================" << endl;
    rlutil::locate (48,23);
    cout << " INGRESE SU OPCION ";
    int opcion;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system("cls");
        main();
        break;
    case 0:
        return;
    }
}
