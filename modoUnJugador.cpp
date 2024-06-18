#include <iostream>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include "misFunciones.h"
using namespace std;

int puntajeMayor[3] {0,0,0};
string nombreDelMayorPuntaje[3];
void actualizarRanking(int puntaje, string nombre);

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

    while(puntajeTotal<100) //mientras puntaje total sea menor a 100
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
            cout << "-------------------------------------------- " << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRonda << endl;
            cout << "LANZAMIENTO NUMERO " << i +1 << endl; //indica en qu‚ tirada va (est  en 0+1, o sea arranca en 1)
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " <<  puntajeTiradas[2] << endl; //cada dado[i] muestra el valor de su tirada
            cout << endl;
            cout << "Presionar espacio para lanzar los dados " << endl;

            rlutil::anykey(); // es como un system pause

            for (int j=0; j<6; j++)
            {
                Dados[j] = tirar((j + 1) *10,12); //muestra el valor ALEATORIO de cada dado
            }

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

    actualizarRanking(puntajeTotal, nombre);

    system("cls");
    cout << endl;
    cout << "FELICIDADES. GANASTE EL JUEGO. LLEGASTE A " << puntajeTotal << " PUNTOS" << endl;
    cout << endl;
    cout << " ==============================" << endl;
    cout << "| 1- EMPEZAR EL JUEGO DE NUEVO  |" << endl;
    cout << "| 2- PUNTUACION MAS ALTA        |" << endl;
    cout << "| 3- SIMULACION                 |" << endl;
    cout << "| 0- FINALIZAR JUEGO            |" << endl;
    cout << " ==============================" << endl;
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
        Puntuacion();
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

void actualizarRanking(int puntaje, string nombre)
{
    for (int i = 0; i < 3; i++)
    {
        if (puntaje > puntajeMayor[i])
        {
            // Desplazar los elementos hacia abajo
            for (int j = 2; j > i; j--)
            {
                puntajeMayor[j] = puntajeMayor[j - 1];
                nombreDelMayorPuntaje[j] = nombreDelMayorPuntaje[j - 1];
            }
            // Insertar el nuevo puntaje y nombre
            puntajeMayor[i] = puntaje;
            nombreDelMayorPuntaje[i] = nombre;
            break;
        }
    }
}

void Puntuacion()
{
    int opcion;

    system("cls");
    cout << "=================================" << endl;
    cout << "-------------RANKING-------------" << endl;
    cout << "=================================" << endl;
    cout << endl;
    cout << "PRIMER PUESTO: " << nombreDelMayorPuntaje[0] << " CON " << puntajeMayor[0] << " PUNTOS " << endl;
    cout << "SEGUNDO PUESTO: " << nombreDelMayorPuntaje[1] << " CON " << puntajeMayor[1] << " PUNTOS " << endl;
    cout << "TERCER PUESTO: " << nombreDelMayorPuntaje[2] << " CON " << puntajeMayor[2] << " PUNTOS " << endl;
    cout << endl;
    cout << " ==============================" << endl;
    cout << "| 1- VOLVER A MENU              |" << endl;
    cout << "| 0- FINALIZAR JUEGO            |" << endl;
    cout << " ==============================" << endl;
    cout << endl;
    cout << "INGRESE SU OPCION: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system ("cls");
        main();
        break;
    case 0:
        return;
        break;
    }

}


//opcion de ir a todas las puntuaciones



