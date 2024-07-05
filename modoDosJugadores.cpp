#include <iostream>
#include <ctime>

using namespace std;

#include "rlutil.h"
#include "funciones.h"
#include "misFunciones.h"


void modoDosJugadores(int puntajeMayor[], string nombreDelMayorPuntaje[])
{
    string nombre1, nombre2,opcionRondas;
    int  puntajeTotalJ1 = 0,puntajeTotalJ2 =0,Dados[6], ronda=0,maximoDeLaRondaJ1 =0,maximoDeLaRondaJ2=0,opcion,  tiradasJ1=0,tiradasJ2=0,limRondas, tirada =0;
    bool finaliza=false;
    ponerCero(Dados, 3);

    rlutil::locate (41,6);
    cout << "-------------------------------------" << endl;
    rlutil::locate (41,7);
    cout << "----- MODO DE JUEGO DOS JUGADOR -----" << endl;
    rlutil::locate (41,8);
    cout << "-------------------------------------" << endl;
    rlutil::locate (41,10);
    cout << " INGRESE EL NOMBRE DEL PRIMER JUGADOR" << endl;
    rlutil::locate (55,12);
    cout << "- ";
    cin.ignore();
    getline(cin,nombre1);
    rlutil::locate (41,14);
    cout << " INGRESE EL NOMBRE DEL SEGUNDO JUGADOR" << endl;
    rlutil::locate (55,16);
    cout << "- ";
    getline(cin,nombre2);
    if(nombre1=="" || nombre2 == "") /// EL USUARIO DEBE DE INGRESAR SI O SI AMBOS NOMBRES
    {
        system("cls");
        rlutil::locate(38, 10);
        cout << "INGRESE AMBOS NOMBRES SINO VOLVERA AL MENU ..." << endl;
        rlutil::locate(43, 12);
        cout << "INGRESE EL NOMBRE DEL PRIMER JUGADOR: ";
        rlutil::locate(58, 14);
        getline(cin,nombre1);
        rlutil::locate(43, 16);
        cout << "INGRESE EL NOMBRE DEL SEGUNDO JUGADOR: " << endl;
        rlutil::locate(58, 18);
        getline(cin,nombre2);
        if(nombre1=="" || nombre2 == "" )
        {
            system("cls");
            menu (puntajeMayor,nombreDelMayorPuntaje);
        }
    }
    system("cls");
    /// DEJAMOS QUE EL USARIO DECIDA SI QUIERE PONER LIMITES DE RONDA O NO
    cout << endl;
    rlutil::locate (42,10);
    cout << " QUIERE INGRESAR UN LIMITE DE RONDAS? " <<endl;
    cout << endl;
    rlutil::locate (54,12);
    cout << " [ S / N ]" <<endl;
    rlutil::locate (59,14);
    cin >> opcionRondas;

    if (opcionRondas == "n" || opcionRondas == "N")
    {
        finaliza = false;
    }
    else if (opcionRondas == "s" || opcionRondas == "S")
    {
        system("cls");
        rlutil::locate (42,10);
        cout<< " INGRESE EL LIMITE DE RONDAS QUE DESEA JUGAR "<<endl;
        rlutil::locate (55,12);
        cin>>limRondas;
    }

    while(finaliza == false)
    {
        int puntajeTiradas[3];
        bool  sexteto = false;
        tiradasJ1=0;
        tiradasJ2=0;
        ronda++;
        ponerCero(puntajeTiradas, 3);
        system("cls");
        srand(time (0));
        rlutil::saveDefaultColor();

        /// CREAMOS CARTELES PARA QUE ENTRE LOS TURNOS SE VEA A QUIEN LE TOCA Y CUANTOS PUNTOS TIENE CADA UNO
        if (puntajeTotalJ1 >0)
        {
            rlutil::locate (44,8);
            cout << "============================= " <<endl;
            rlutil::locate (55,9);
            cout << "RONDA " << ronda << endl;
            rlutil::locate (51,10);
            cout << "TURNO DE " << nombre1<<endl;
            rlutil::locate (46,12);
            cout << "PUNTAJE "<< nombre1 << " " << puntajeTotalJ1 <<endl;
            rlutil::locate (46,13);
            cout << "PUNTAJE "<< nombre2 << " " << puntajeTotalJ2 <<endl;
            rlutil::locate (44,14);
            cout << "============================= " <<endl;
            rlutil::anykey();
        }
        while(tiradasJ1 <= 2) /// LE DAMOS LA MISMA CONDICION QUE EN MODO UN JUGADOR
        {
            system("cls");
            rlutil::locate(36, 2);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(41, 3);
            cout << "JUGADOR: " << nombre1 ;
            rlutil::locate(41, 4);
            cout << "RONDA: " << ronda ;
            rlutil::locate(41, 5);
            cout << "PUNTAJE TOTAL: " << puntajeTotalJ1 << endl;
            rlutil::locate(36, 6);
            cout << "-------------------------------------------- " << endl;
            rlutil::locate(41, 7);
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRondaJ1 << endl;
            rlutil::locate(41, 8);
            cout << "LANZAMIENTO NUMERO " << tiradasJ1 +1 << endl;
            rlutil::locate(41, 9);
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " <<  puntajeTiradas[2] << endl;
            rlutil::locate(36, 10);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(38, 12);
            cout << "Presionar espacio para lanzar los dados " << endl;

            rlutil::anykey();

            for (int j=0; j<6; j++)
            {
                Dados[j] = tirar((j + 3) *10,16);
            }

            puntajeTiradas[tiradasJ1] = puntaje(Dados);

            if(puntajeTiradas[tiradasJ1]==0 || puntajeTiradas[tiradasJ1]==100)
            {
                tiradasJ1 = 3;
            }
            if(puntajeTiradas[tiradasJ1] == 0)
            {
                sexteto = true;
            }

            rlutil::resetColor();
            rlutil::anykey();
            ponerCero(Dados, 3);
            tiradasJ1 ++;
        }
        int ubi=maximoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubi] == 100)
        {
            puntajeTotalJ1 += 100;
        }
        else if (sexteto == true )
        {
            puntajeTotalJ1 = 0;
            maximoDeLaRondaJ1 = 0;
        }
        else
        {
            maximoDeLaRondaJ1 = puntajeTiradas[ubi];
            puntajeTotalJ1 += puntajeTiradas[ubi];
        }
        sexteto = false;
        ponerCero(puntajeTiradas, 3);
        system("cls");
        rlutil::locate (44,8);
        cout << "============================= " <<endl;
        rlutil::locate (55,9);
        cout << "RONDA " << ronda << endl;
        rlutil::locate (51,10);
        cout << "TURNO DE " << nombre2<<endl;
        rlutil::locate (46,12);
        cout << "PUNTAJE "<< nombre1 << " " << puntajeTotalJ1 <<endl;
        rlutil::locate (46,13);
        cout << "PUNTAJE "<< nombre2 << " " << puntajeTotalJ2 <<endl;
        rlutil::locate (44,14);
        cout << " ============================= " <<endl;

        rlutil::anykey();

        while(tiradasJ2 <= 2) /// MISMAS CONDICIONES 3 TIRADAS CADA UNO
        {
            system("cls");
            rlutil::locate(36, 2);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(41, 3);
            cout << "JUGADOR: " << nombre2;
            rlutil::locate(41, 4);
            cout << "RONDA: " << ronda;
            rlutil::locate(41, 5);
            cout << "PUNTAJE TOTAL: " << puntajeTotalJ2 << endl;
            rlutil::locate(36, 6);
            cout << "-------------------------------------------- " << endl;
            rlutil::locate(41, 7);
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRondaJ2 << endl;
            rlutil::locate(41, 8);
            cout << "LANZAMIENTO NUMERO " << tiradasJ2 +1 << endl;
            rlutil::locate(41, 9);
            cout << "TIRADA 1: " << puntajeTiradas[0] << " TIRADA 2: " << puntajeTiradas[1] << " TIRADA 3: " <<  puntajeTiradas[2] << endl;
            rlutil::locate(36, 10);
            cout << "----------------------------------------------- " << endl;
            rlutil::locate(38, 12);
            cout << "Presionar espacio para lanzar los dados " << endl;

            rlutil::anykey();
            for (int j=0; j<6; j++)
            {
                Dados[j] = tirar((j + 3) *10,16);
            }

            puntajeTiradas[tiradasJ2] = puntaje(Dados);

            if(puntajeTiradas[tiradasJ2]==0 || puntajeTiradas[tiradasJ2]==100)
            {
                tiradasJ2 = 3;
            }
            if(puntajeTiradas[tiradasJ2] == 0)
            {
                sexteto = true;
            }

            rlutil::resetColor();
            rlutil::anykey();
            ponerCero(Dados, 3);
            tiradasJ2++;
        }
        ubi=maximoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubi] == 100)
        {
            puntajeTotalJ2 += puntajeTiradas[ubi];
        }
        else if (sexteto == true )
        {
            puntajeTotalJ2 = 0;
            maximoDeLaRondaJ2 = 0;
        }
        else
        {
            maximoDeLaRondaJ2 = puntajeTiradas[ubi];
            puntajeTotalJ2 += puntajeTiradas[ubi];
        }
        if (puntajeTotalJ1>=100)
        {
            finaliza=true;
        }
        else if (puntajeTotalJ2>=100)
        {
            finaliza=true;
        }
        else if (ronda == limRondas)
        {
            finaliza=true;
        }

    }
    if (puntajeTotalJ1>=puntajeTotalJ2 &&  tiradasJ1 <= tiradasJ2) /// VEMOS QUIEN HIZO MAS PUNTOS ENTRE LOS DOS Y O QUIEN HIZO MENOS TIRADAS Y LE DECIMOS QUIEN GANO
    {
        actualizarRanking(puntajeTotalJ1, nombre1,puntajeMayor, nombreDelMayorPuntaje);
        rlutil::setBackgroundColor(rlutil::WHITE);
        system("cls");
        rlutil::setColor(rlutil::BLACK);
        corona(54,8);
        rlutil::locate(42,12);
        cout << "  FELICIDADES " << nombre1 << " GANASTE EL JUEGO!!!" <<endl;
        rlutil::anykey();
        rlutil::setBackgroundColor(rlutil::BLACK);
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(35, 3);
        cout << " ================================================================" << endl;
        rlutil::locate(40, 4);
        cout << nombre1 << " LLEGASTE A " << puntajeTotalJ1 << " PUNTOS EN LA RONDA " << ronda << endl ;
        rlutil::locate(35, 5);
        cout << " ================================================================" << endl;
    }
    else if (puntajeTotalJ2>=puntajeTotalJ1 && tiradasJ1 >= tiradasJ2)
    {
        actualizarRanking(puntajeTotalJ2, nombre2,puntajeMayor, nombreDelMayorPuntaje);
        rlutil::setBackgroundColor(rlutil::WHITE);
        system("cls");
        rlutil::setColor(rlutil::BLACK);
        corona(54,8);
        rlutil::locate(42,12);
        cout << "  FELICIDADES " << nombre2 << " GANASTE EL JUEGO!!!" <<endl;
        rlutil::anykey();
        rlutil::setBackgroundColor(rlutil::BLACK);
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(35, 3);
        cout << " ================================================================" << endl;
        rlutil::locate(40, 4);
        cout << nombre2 << " LLEGASTE A " << puntajeTotalJ2 << " PUNTOS EN LA RONDA " << ronda <<endl ;
        rlutil::locate(35, 5);
        cout << " ================================================================" << endl;
    }
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
        system ("cls");
        modoDosJugadores(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 2:
        system ("cls");
        ranking(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 3:
        menu(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 0:
        return;
    }
    rlutil::resetColor();
}






