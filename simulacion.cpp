#include <iostream>
#include <ctime>

using namespace std;

#include "funciones.h"
#include "rlutil.h"
#include "misFunciones.h"


void Simulacion(int puntajeMayor[3], string nombreDelMayorPuntaje[3])
{
    int puntajeTotal = 0,Dados[6], ronda=1,maximoDeLaRonda =0,opcion; //habr  variables enteras
    ponerCero(Dados, 3); //pone en 0 el valor de los dados

    while(puntajeTotal<100) //mientras puntaje total sea menor a 100
    {
        int puntajeTiradas[3],dados [5];
        ponerCero(puntajeTiradas, 3);
        srand(time (0)); // tira random pero no se que cosa
        rlutil::saveDefaultColor(); // deja el color negro ya que es color por defecto
        system("cls");
        rlutil::locate (43,6);
        cout << "------------------------------------" << endl;
        rlutil::locate (43,7);

        cout << "--------- MODO SIMULACION ----------" << endl;
        rlutil::locate (43,8);

        cout << "------------------------------------" << endl;

        rlutil::locate (48,10);
        cout << "INGRESA 6 NUMEROS DE DADOS " <<endl;
        rlutil::locate (48,12);

        for (int i=0; i<6 ; i++)
        {
            rlutil::locate (48,i+12);
            cout << "DADO " << i + 1<< " ";
            cin >> dados [i];
        }
        for (int i=0 ; i<3; i++)
        {
            system("cls");
            rlutil::locate(36, 2);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(41, 3);
            cout << "RONDA " << ronda;
            rlutil::locate(41, 4);
            cout << "PUNTAJE TOTAL: " << puntajeTotal << endl;
            rlutil::locate(36, 5);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(41, 6);
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRonda << endl;
            rlutil::locate(41, 7);
            cout << "LANZAMIENTO NUMERO " << i + 1 << endl;
            rlutil::locate(41, 8);
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " << puntajeTiradas[2] << endl;
            rlutil::locate(36, 9);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(38, 11);
            cout << "Presionar espacio para lanzar los dados " << endl;


            for (int j=0; j<6; j++)
            {
                Dados[j] = tirarAEleccion (dados[j], (j + 3) *10,16,1); //muestra el valor ALEATORIO de cada dado
            }

            puntajeTiradas[i] = puntaje(Dados);

            if(puntajeTiradas[i]==0 || puntajeTiradas[i]==100){
                i=3;
            }

            rlutil::resetColor(); //resetea el color al negro
            //ponerCero(Dados, 3);
            rlutil::anykey();

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
        rlutil::anykey();
        ronda++;
    }
    system("cls");
    rlutil::locate(45, 8);
    cout << " ==============================" << endl;
    rlutil::locate(45, 9);
    cout << "| 1- REINICIAR SIMULACION       |" << endl;
    rlutil::locate(45, 10);
    cout << "| 2- IR AL MENU                 |" << endl;
    rlutil::locate(45, 11);
    cout << "| 0- FINALIZAR JUEGO            |" << endl;
    rlutil::locate(45, 12);
    cout << " ==============================" << endl;
    rlutil::locate(52, 14);
    cout << "INGRESE SU OPCION: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system ("cls");
        Simulacion(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 2:
        system("cls");
        menu(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 0:
        system ("cls");
        return;
    }
}
