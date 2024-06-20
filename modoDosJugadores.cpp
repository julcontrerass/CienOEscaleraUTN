#include <iostream>
#include <ctime>
using namespace std;
#include "rlutil.h"
#include "funciones.h"

int puntajeMayorDosJugadores[3] {0,0,0};
string nombreDelMayorPuntajeDosJugadores[3];

void modoDosJugadores()
{
    string nombre1, nombre2,opcionRondas; //habr  variable con ingreso de letras
    int  puntajeTotalJ1 = 0,puntajeTotalJ2 =0,Dados[6], ronda=0,maximoDeLaRondaJ1 =0,maximoDeLaRondaJ2=0,opcion,  tiradasJ1=0,tiradasJ2=0,limRondas; //habr  variables enteras
    bool finaliza=false;
    ponerCero(Dados, 3); //pone en 0 el valor de los dados
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
    if(nombre1=="" || nombre2 == "" )
    {
        cout << "Ingrese un nombre o volver al menu principal..." << endl;
        getline(cin,nombre1);
        cout << "INGRESE EL NOMBRE DEL SEGUNDO JUGADOR SINO VUELVE AL MENU ..." << endl;
        getline(cin,nombre2);
        if(nombre1=="" || nombre2 == "" )
        {
            system("cls");
            main();
        }
    }
    system("cls");
    //Dejamos que el usuario seleccione el limete de las rondas
    cout << endl;
    rlutil::locate (42,10);
    cout << " QUIERE INGRESAR UN LIMITE DE RONDAS? " <<endl;
    cout << endl;
    rlutil::locate (54,12);
    cout << " [ S / N  ]" <<endl;
    rlutil::locate (59,14);
    cin >> opcionRondas;

    if (opcionRondas == "n" || opcionRondas == "N")
    {
        finaliza = false;
    }
    else if (opcionRondas == "s" || opcionRondas == "S")
    {
        system("cls");
        cout << endl;
        cout<< " INGRESE EL LIMITE DE RONDAS QUE DESEA JUGAR "<<endl;
        cin>>limRondas;
    }


    while( finaliza == false  )
    {
        int puntajeTiradas[3];
        tiradasJ1=0;
        tiradasJ2=0;
        ronda++;
        ponerCero(puntajeTiradas, 3);
        system("cls");
        srand(time (0)); // tira random pero no se que cosa
        rlutil::saveDefaultColor(); // deja el color negro ya que es color por defecto
        cout << endl;
        if (puntajeTotalJ1 >0)
        {
            cout << " =========================== " <<endl;
            cout << "| RONDA  NUMERO: " << ronda << endl;
            cout << "| PROXIMO TURNO: " << nombre1<<endl;
            cout << "| PUNTAJE "<< nombre1 << " " << puntajeTotalJ1 <<endl;
            cout << "| PUNTAJE "<< nombre2 << " " << puntajeTotalJ2 <<endl;
            cout << " =========================== " <<endl;

            rlutil::anykey();
        }
        for (int i=0 ; i<3; i++)
        {
            tiradasJ1++;
            system("cls");
            cout << "JUGADOR: " << nombre1 ;
            cout << " | RONDA: " << ronda ;
            cout << " | PUNTAJE TOTAL: " << puntajeTotalJ1 << endl; //muestra el puntaje total
            cout << "-------------------------------------------- " << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRondaJ1 << endl;
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
        int ubi=maximoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubi] == 100)
        {
            puntajeTotalJ1 += puntajeTiradas[ubi];
            break;
        }
        int ubiCero = minimoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubiCero] == 0 )
        {
            puntajeTotalJ1 = 0;
        }
        else
        {
            ubi = maximoVector(puntajeTiradas, 3);
            maximoDeLaRondaJ1 = puntajeTiradas[ubi];
            puntajeTotalJ1 += puntajeTiradas[ubi];//al total se le acumula una de esas 3 tiradas(el valor mayor de las 3 tiradas)
        }
        ponerCero(puntajeTiradas, 3);
        system("cls");
        cout << " =========================== " <<endl;
        cout << "| RONDA  NUMERO: " << ronda << endl;
        cout << "| PROXIMO TURNO: " << nombre2<<endl;
        cout << "| PUNTAJE "<< nombre1 << " " << puntajeTotalJ1 <<endl;
        cout << "| PUNTAJE "<< nombre2 << " " << puntajeTotalJ2 <<endl;
        cout << " =========================== " <<endl;

        rlutil::anykey();

        for (int i=0 ; i<3; i++)
        {
            tiradasJ2++;

            system("cls");
            cout << "JUGADOR: " << nombre2 ;
            cout << " | RONDA: " << ronda;
            cout << " | PUNTAJE TOTAL: " << puntajeTotalJ2 << endl; //muestra el puntaje total
            cout << "-------------------------------------------- " << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA " << maximoDeLaRondaJ2 << endl;
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
        ubi=maximoVector(puntajeTiradas, 3);
        if (puntajeTiradas[ubi] == 100)
        {
            puntajeTotalJ2 += puntajeTiradas[ubi];
            break;
        }
        ubiCero = minimoVector(puntajeTiradas, 3);

        if (puntajeTiradas[ubiCero] == 0 )
        {
            puntajeTotalJ2 = 0;
        }
        else
        {
            ubi = maximoVector(puntajeTiradas, 3);
            maximoDeLaRondaJ2 = puntajeTiradas[ubi];
            puntajeTotalJ2 += puntajeTiradas[ubi];//al total se le acumula una de esas 3 tiradas(el valor mayor de las 3 tiradas)
        }
        //condiciones para que finalice el juego
        if (puntajeTotalJ1>=100)
        {
            finaliza=true;
        }
        else if (puntajeTotalJ2>=100)
        {
            finaliza=true;
        }
        else if (ronda == limRondas)   // comparamos si la cantidad de rondas en las que estamos es igual al que solicito el usuaio
        {
            finaliza=true; // en el caso de que sea verdadero lo modificamos a true para que salga del juego
        }

    }




    if (puntajeTotalJ1>=puntajeTotalJ2 &&  tiradasJ1 <= tiradasJ2)
    {
        actualizarRankingDosJugadores(puntajeTotalJ1, nombre1);
        rlutil::setBackgroundColor(rlutil::WHITE);
        system("cls");
        rlutil::setColor(rlutil::BLACK);
        corona(54,8);
        cout << endl;
        rlutil::locate(42,12);
        cout << "  FELICIDADES " << nombre1 << " GANASTE EL JUEGO!!!!!!" <<endl;
        cout << endl;
        rlutil::anykey();
        rlutil::setBackgroundColor(rlutil::BLACK);
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        cout << endl;
        cout << " ========================================================================" << endl;
        cout << endl;
        cout << "  LLEGASTE A " << puntajeTotalJ1 << " PUNTOS EN LA RONDA " << ronda << endl ;
        cout << endl;
        cout << " ========================================================================" << endl;
    }
    else if (puntajeTotalJ2>=puntajeTotalJ1 && tiradasJ1 >= tiradasJ2)
    {
        actualizarRankingDosJugadores(puntajeTotalJ2, nombre2);
        rlutil::setBackgroundColor(rlutil::WHITE);
        system("cls");
        rlutil::setColor(rlutil::BLACK);
        corona(54,8);
        cout << endl;
        rlutil::locate(42,12);
        cout << "  FELICIDADES " << nombre2 << " GANASTE EL JUEGO!!!!!!" <<endl;
        cout << endl;
        rlutil::anykey();
        rlutil::setBackgroundColor(rlutil::BLACK);
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        cout << endl;
        cout << " ========================================================================" << endl;
        cout << endl;
        cout << "  LLEGASTE A " << puntajeTotalJ2 << " PUNTOS EN LA RONDA " << ronda <<endl ;
        cout << endl;
        cout << " ========================================================================" << endl;

    }

    cout << endl;
    cout << endl;
    cout << " ==============================" << endl;
    cout << "| 1- EMPEZAR EL JUEGO DE NUEVO  |" << endl;
    cout << "| 2- PUNTUACION MAS ALTA        |" << endl;
    cout << "| 0- FINALIZAR JUEGO            |" << endl;
    cout << " ==============================" << endl;
    cout << endl;
    cout << "INGRESE SU OPCION: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system ("cls");
        modoDosJugadores();
        break;
    case 2:
        system ("cls");
        puntuacionDosJugadores();
        break;
    case 0:
        main();
    }
    rlutil::resetColor();
}


void actualizarRankingDosJugadores(int puntaje, string nombre)
{
    for (int i = 0; i < 3; i++)
    {
        if (puntaje > puntajeMayorDosJugadores[i])
        {
            // Desplazar los elementos hacia abajo
            for (int j = 2; j > i; j--)
            {
                puntajeMayorDosJugadores[j] = puntajeMayorDosJugadores[j - 1];
                nombreDelMayorPuntajeDosJugadores[j] = nombreDelMayorPuntajeDosJugadores[j - 1];
            }
            // Insertar el nuevo puntaje y nombre
            puntajeMayorDosJugadores[i] = puntaje;
            nombreDelMayorPuntajeDosJugadores[i] = nombre;
            break;
        }
    }
}

void puntuacionDosJugadores()
{
    int opcion;
    system("cls");
    cout << " =================================" << endl;
    cout << endl;
    cout << endl;
    cout << " --           RANKING           --";
    copa(6, 3 );
    copa(24, 3 );
    sonrisa(12,6);
    cout << endl;
    cout << endl;
    cout << " =================================" << endl;
    cout << endl;
    cout << " PRIMER PUESTO: " << nombreDelMayorPuntajeDosJugadores[0] << " CON " << puntajeMayorDosJugadores[0] << " PUNTOS " << endl;
    cout << " SEGUNDO PUESTO: " << nombreDelMayorPuntajeDosJugadores[1] << " CON " << puntajeMayorDosJugadores[1] << " PUNTOS " << endl;
    cout << " TERCER PUESTO: " << nombreDelMayorPuntajeDosJugadores[2] << " CON " << puntajeMayorDosJugadores[2] << " PUNTOS " << endl;
    cout << endl;
    cout << "  ==============================" << endl;
    cout << " |     1- VOLVER A MENU          |" << endl;
    cout << " |     0- FINALIZAR JUEGO        |" << endl;
    cout << "  ==============================" << endl;
    cout << endl;
    cout << " INGRESE SU OPCION: ";
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
