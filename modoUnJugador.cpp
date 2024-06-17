#include <iostream>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include "misFunciones.h"
using namespace std;
int puntajeMayor =0;
string nombreDelMayorPuntaje;
void modoUnJugador()
{
    string nombre; //habr  variable con ingreso de letras
    int puntajeTotal = 0,Dados[6], ronda=1,maximoDeLaRonda =0,opcion; //habr  variables enteras
    ponerCero(Dados, 3); //pone en 0 el valor de los dados
    cout << "------------------------------------" << endl;
    cout << "----- MODO DE JUEGO UN JUGADOR -----" << endl;
    cout << "------------------------------------" << endl;
    cout << " INGRESE EL NOMBRE DEL JUGADOR PARA INCIAR" << endl;
    cin.ignore();
    getline(cin,nombre);
    if(nombre=="")
    {
        system("cls");
        cout << "Ingrese un nombre o volver al menu principal..." << endl;
        getline(cin,nombre);
        if(nombre=="")
        {
            system("cls");
            main();
        }
    }

    while(puntajeTotal<=100) //mientras puntaje total sea menor a 100
    {
        int puntajeTiradas[3];
        ponerCero(puntajeTiradas, 3);
        system("cls");
        srand(time (0)); // tira random pero no se que cosa
        rlutil::saveDefaultColor(); // deja el color negro ya que es color por defecto
        for (int i=0 ; i<3; i++)
        {

            system("cls");
            cout << "JUGADOR: " << nombre ;
            cout << " | RONDA: " << ronda;
            cout << " | PUNTAJE TOTAL: " << puntajeTotal << endl; //muestra el puntaje total
            cout << "------------------------------------ " << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRonda << endl;
            cout << "LANZAMIENTO NUMERO " << i +1 << endl; //indica en qu‚ tirada va (est  en 0+1, o sea arranca en 1)
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " <<  puntajeTiradas[2] << endl; //cada dado[i] muestra el valor de su tirada
            cout << endl;
            cout << "EL MEJOR JUGADOR ES: " << nombreDelMayorPuntaje <<  " CON " << puntajeMayor << " PUNTOS" << endl;
            cout << "Presionar espacio para lanzar los dados " << endl;

            rlutil::anykey(); // es como un system pause

            for (int j=0; j<6; j++)
            {
                Dados[j] = tirar((j + 1) *10,rand()% 10 +6); //muestra el valor ALEATORIO de cada dado
            }
//            cargarVector(Dados , 6);

            puntajeTiradas[i] = puntaje(Dados);

            rlutil::resetColor(); //resetea el color al negro
            rlutil::anykey(); // es como un system pause
            ponerCero(Dados, 3);

        }
        int ubiCero = minimoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubiCero] == 0 )
        {
            puntajeTotal = 0;
        }
        else
        {
            int ubi = maximoVector(puntajeTiradas, 3);
            maximoDeLaRonda = puntajeTiradas[ubi];
            puntajeTotal += puntajeTiradas[ubi];//al total se le acumula una de esas 3 tiradas(el valor mayor de las 3 tiradas)
        }
        ronda++;

    }
    if (puntajeTotal>puntajeMayor)
    {
        puntajeMayor=puntajeTotal;
        nombreDelMayorPuntaje=nombre;
    }
    system("cls");
    cout << endl;
    cout << "FELICIDADES. GANASTE EL JUEGO. LLEGASTE A " << puntajeTotal << " puntos" << endl;
    cout << endl;
    cout << "===============================" << endl;
    cout << " 1- EMPEZAR EL JUEGO DE NUEVO" << endl;
    cout << " 2- PUNTUACION MAS ALTA" << endl;
    cout << " 3- SIMULACION" << endl;
    cout << " 0- FINALIZAR JUEGO" << endl;
    cout << "===============================" << endl;
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
//      puntuacion mas alta
        break;
    case 3:
        system ("cls");
        cout << " ESTAMOS EN EL MENU MOSTRANDO LA PUNTUACION";
        break;
    case 0:
        main();
    }
    rlutil::resetColor();


}

//opcion de ir a todas las puntuaciones
//corregir la ubi de los dados cuando lanzamos

