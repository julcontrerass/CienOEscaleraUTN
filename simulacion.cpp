#include <iostream>
#include <ctime>

using namespace std;

#include "funciones.h"
#include "rlutil.h"
#include "misFunciones.h"


void Simulacion(int puntajeMayor[], string nombreDelMayorPuntaje[])
{
    int puntajeTotal = 0,Dados[6], ronda=1,maximoDeLaRonda =0,opcion;
    bool finaliza = false, sexteto = false;
    while(finaliza == false)
    {
        int puntajeTiradas[3],dados [5], tirada =0;
        ponerCero(puntajeTiradas, 3);
        srand(time (0));
        rlutil::saveDefaultColor();
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

        for (int i=0; i<6 ; i++) /// LE PEDIMOS QUE EL USUARIO INGRESE LOS NUMERO QUE DESEE
        {
            rlutil::locate (48,i+12);
            cout << "DADO " << i + 1<< ": ";
            cin >> dados [i];
            if (dados[i] > 6){
                rlutil::locate (42,i+12);
                cout << "DEBES INGRESAR UN NUMERO ENTRE 1 Y 6 : " ;
                cin >> dados [i];
            }
        }
        while (tirada <=2)
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
            cout << "LANZAMIENTO NUMERO " << tirada + 1 << endl;
            rlutil::locate(41, 8);
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " << puntajeTiradas[2] << endl;
            rlutil::locate(36, 9);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(38, 11);
            cout << "Presionar espacio para lanzar los dados " << endl;


            for (int j=0; j<6; j++)
            {
                Dados[j] = tirarAEleccion (dados[j], (j + 3) *10,16,1); /// AL LLAMAR A LA FUNCION PARA TIRAR LOS DADOS LE DAMOS LOS NUMERO QUE ELGIO EL USUARIO
            }

            puntajeTiradas[tirada] = puntaje(Dados);
            if(puntajeTiradas[tirada] == 0 || puntajeTiradas[tirada] == 100)
            {
                tirada = 3;
            }

            if(puntajeTiradas[tirada] == 0)
            {
                sexteto = true;
            }

            rlutil::resetColor(); //resetea el color al negro
            rlutil::anykey();
            tirada++;
        }

        int ubi = maximoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubi] == 100)
        {
            finaliza = true;
            puntajeTotal += 100;
        }
        else if (sexteto == true)
        {
            puntajeTotal = 0;
            maximoDeLaRonda = 0;
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
        rlutil::anykey();
        ronda++;
    }
    system("cls");
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(35, 3);
    cout << " =====================================================" << endl;
    rlutil::locate(40, 4);
    cout << "   LLEGASTE A " << puntajeTotal << " PUNTOS" << " EN LA RONDA " << ronda - 1 << endl;
    rlutil::locate(35, 5);
    cout << " =====================================================" << endl;
    rlutil::locate(45, 8);
    cout << " ==============================" << endl;
    rlutil::locate(45, 9);
    cout << "| 1- EMPEZAR SIMULACION DE NUEVO|" << endl;
    rlutil::locate(45, 10);
    cout << "| 2- MENU                       |" << endl;
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
