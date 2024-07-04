#include <iostream>
#include <ctime>

using namespace std;

#include "rlutil.h"
#include "funciones.h"
#include "misFunciones.h"

void modoUnJugador(int puntajeMayor[], string nombreDelMayorPuntaje[])
{
    string nombre;
    int puntajeTotal = 0, Dados[6], ronda = 1, maximoDeLaRonda = 0, opcion;
    bool finaliza = false, sexteto=false;

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
     /// SI EL USARIO NO INGRESA NOMBRE LE ARETAMOS QUE DEBE COMPLETARLO
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
            menu(puntajeMayor,nombreDelMayorPuntaje);
        }
    }

    while (finaliza == false)
    {
        int puntajeTiradas[3], tirada=0 ;
        ponerCero(puntajeTiradas, 3);
        system("cls");
        srand(time(0));
        rlutil::saveDefaultColor();

        /// CREAMOS UN WHILE PARA QUE SI EL USUARIO SACA ESCALERA O SEXTETO DE 6 FINALICE Y NO PUEDA SEGUIR TIRANDO EL RESTO
        while(tirada <= 2){
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
            cout << "LANZAMIENTO NUMERO " << tirada + 1 << endl;
            rlutil::locate(41, 9);
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " << puntajeTiradas[2] << endl;
            rlutil::locate(36, 10);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(38, 12);
            cout << "Presionar espacio para lanzar los dados " << endl;

            for (int j = 0; j<6; j++)
            {
                Dados[j] = tirar((j + 3) * 10, 16);/// LLAMAMOS A LA FUNCION TIRAR PARA QUE TIRE LOS DADOS Y CON EL ARRAY GUARDAMOS CADA UNO DE ELLOS
            }

            puntajeTiradas[tirada] = puntaje(Dados); /// CON LA FUNCION PUNTAJE VERIFICAMOS CUAL ES EL RESULTADO DEL PUNTAJE Y ESE RESULTADO LO GUARDAMOS EN CADA TIRADA

            if(puntajeTiradas[tirada] == 0 || puntajeTiradas[tirada] == 100){ /// SI EN LA TIRADA SALE SEXTETO DE 6 O ESCALERA ENTONCES FINALIZAMOS NUESTRO WHILE DE TIRADAS
                tirada = 3;
            }

            if(puntajeTiradas[tirada] == 0 ){
                sexteto = true;
            }
            rlutil::resetColor();
            rlutil::anykey();
            tirada++;
        }

        int ubi = maximoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubi] == 100)  /// CORROBORAMOS SI SALIO UN 100 ENTONCES TENEMOS UNA ESCALERA
        {
            puntajeTotal += 100;
        }
        else if (sexteto == true) /// SI HABIA SALIDO UN SEXTETO DE 6 ENTONCES REINICIAMOS EL PUNTAJE TOTAL EN 0
        {
            puntajeTotal = 0;
            maximoDeLaRonda = 0;
        }
        else
        {
            maximoDeLaRonda = puntajeTiradas[ubi];
            puntajeTotal += puntajeTiradas[ubi];
        }


        if (puntajeTotal >= 100)
        {
            finaliza = true;
        }
        ronda++;

    }

    actualizarRanking(puntajeTotal, nombre, puntajeMayor, nombreDelMayorPuntaje); /// CON LOS RESULTADOS DE LA PARTIDA LOS MANDAMOS A ACTUALIZARRANKING PARA ORDENAR EL ARRAY DE RANKING

    rlutil::setBackgroundColor(rlutil::WHITE);
    system("cls");
    rlutil::setColor(rlutil::BLACK);
    corona(54, 8);
    rlutil::locate(42, 12);
    cout << "  FELICIDADES GANASTE EL JUEGO!!!" << endl;
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
    cout << "| 2- RANKING                    |" << endl;
    rlutil::locate(45, 11);
    cout << "| 3- MENU                       |" << endl;
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
        ranking(puntajeMayor, nombreDelMayorPuntaje);
        break;
    case 3:
        system("cls");
        menu(puntajeMayor, nombreDelMayorPuntaje);
        break;
    case 0:
        return;
    }
    rlutil::resetColor();
}





