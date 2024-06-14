#include <iostream>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include "misFunciones.h"
using namespace std;
void modoUnJugador()
{
    string nombre; //habr  variable con ingreso de letras
    int puntajeTotal = 0,  puntajeMaximo,Dados[3]; //habr  variables enteras
    ponerCero(Dados, 3); //pone en 0 el valor de los dados
    cout << "------------------------------------" << endl;
    cout << "----- MODO DE JUEGO UN JUGADOR -----" << endl;
    cout << "------------------------------------" << endl;
    cout << " INGRESE EL NOMBRE DEL JUGADOR PARA INCIAR" << endl;
    cin.ignore();
    getline(cin,nombre);
    if(nombre==""){
        system("cls");
        cout << "Ingrese un nombre o volver  al men£ principal..." << endl;
        getline(cin,nombre);
        if(nombre==""){
            system("cls");
            main();
        }
    }
    system("cls");
    cout << "------------------------------------" << endl;
    cout << "----- MODO DE JUEGO UN JUGADOR -----" << endl;
    cout << "------------------------------------" << endl;
    cout << "-- BIENVENIDO " << nombre << " --" << endl;
    cout << "Para iniciar el juego presione el espacio..." << endl;
    rlutil::anykey(); // es como un system pause
    while(puntajeTotal<=100) //mientras puntaje total sea menor a 100
    {
        puntajeMaximo = 0;
        system("cls");
        srand(time (0)); // tira random pero no se que cosa
        rlutil::saveDefaultColor(); // deja el color negro ya que es color por defecto
        for (int i=0 ; i<3; i++)
        {
            cout << "JUGADOR: " << nombre << endl;
            cout << "TIRADA " << i + 1 << endl; //indica en qu‚ tirada va (est  en 0+1, o sea arranca en 1)
            cout << "TIRADA 1: " << Dados[0] << " TIRADA 2: " << Dados[1] << " TIRADA 3: " <<  Dados [2] << endl; //cada dado[i] muestra el valor de su tirada
            cout << "puntaje total: " << puntajeTotal; //muestra el puntaje total
            for (int j=0; j<6; j++)
            {
                Dados[i] += tirar((j + 1) *10,rand()% 10 +6); //muestra el valor ALEATORIO de cada dado
            }
            rlutil::resetColor(); //resetea el color al negro
            rlutil::anykey(); // es como un system pause

            if (Dados[0] > puntajeMaximo ) //todo este if indica cu l de las 3 tiradas ser  la que tiene el valor maximo para quedarnos con esa tirada.
            {
                puntajeMaximo = Dados[0];
            }
            else if(Dados[1]>puntajeMaximo)
            {
                puntajeMaximo=Dados[1];
            }
            else if(Dados[2]>puntajeMaximo)
            {
                puntajeMaximo=Dados[2];
            }
            system("cls");
        }
        puntajeTotal += puntajeMaximo; //al total se le acumula una de esas 3 tiradas(el valor mayor de las 3 tiradas)
        ponerCero(Dados, 3); //vuelve a poner en 0 el valor de los dados
    }
    system("cls");
    cout << "FELICIDADES. GANASTE EL JUEGO. LLEGASTE A 100 PUNTOS.";
    rlutil::resetColor();
}
//falta: hacer jugadas (escalera, sexteto, etc)
//hacer cartel de "GANASTE"
//hacer opcion de jugar de nuevo
//ver puntuacion una vez que finaliza
//opcion de ir a todas las puntuaciones
//comparar mayor puntaje
