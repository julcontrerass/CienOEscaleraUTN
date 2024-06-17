#include <iostream>
#include <ctime>

using namespace std;

#include "misFunciones.h"
#include "funciones.h"
#include "rlutil.h"


void Simulacion()
{
    string nombre; //habr  variable con ingreso de letras
    int puntajeTotal = 0,Dados[6], ronda=1,maximoDeLaRonda =0,opcion; //habr  variables enteras
    ponerCero(Dados, 3); //pone en 0 el valor de los dados
    cout << "------------------------------------" << endl;
    cout << "--------- MODO SIMULACION ----------" << endl;
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

    while(puntajeTotal<100) //mientras puntaje total sea menor a 100
    {
        int puntajeTiradas[3],dados [5];
        ponerCero(puntajeTiradas, 3);
        srand(time (0)); // tira random pero no se que cosa
        rlutil::saveDefaultColor(); // deja el color negro ya que es color por defecto
        system("cls");
        cout << "------------------------------------" << endl;
        cout << "--------- MODO SIMULACION ----------" << endl;
        cout << "------------------------------------" << endl;
        cout << "INGRESA 6 NUMEROS DE DADOS " <<endl;
        for (int i=0; i<6 ; i++)
        {
            cout << "DADO " << i + 1<< " ";
            cin >> dados [i];
        }
        for (int i=0 ; i<3; i++)
        {
            rlutil::anykey();
            system("cls");
            cout << "JUGADOR: " << nombre ;
            cout << " | RONDA: " << ronda;
            cout << " | PUNTAJE TOTAL: " << puntajeTotal << endl; //muestra el puntaje total
            cout << "------------------------------------ " << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRonda << endl;
            cout << "LANZAMIENTO NUMERO " << i +1 << endl; //indica en qu‚ tirada va (est  en 0+1, o sea arranca en 1)
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " <<  puntajeTiradas[2] << endl; //cada dado[i] muestra el valor de su tirada
            cout << endl;
            cout << "Presionar espacio para lanzar los dados " << endl;

            for (int j=0; j<6; j++)
            {
                Dados[j] = tirarAEleccion (dados[j], (j + 1) *10,12); //muestra el valor ALEATORIO de cada dado
            }

            puntajeTiradas[i] = puntaje(Dados);

            rlutil::resetColor(); //resetea el color al negro
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
        rlutil::anykey();
        ronda++;

    }
    system("cls");
    cout << endl;
    cout << " ==============================" << endl;
    cout << "| 1- IR AL MENU PRINCIPAL       |" << endl;
    cout << "| 2- REINICIAR SIMULACION       |" << endl;
    cout << "| 0- FINALIZAR JUEGO            |" << endl;
    cout << " ==============================" << endl;

    cout << " SELECCIONE UNA OPCION: " ;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system ("cls");
        main();
        break;
    case 2:
        system("cls");
        Simulacion();
        break;
    case 0:
        system ("cls");
        return;
    }
}
