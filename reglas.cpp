#include <iostream>


using namespace std;
#include "funciones.h"
#include "rlutil.h"
#include "misFunciones.h"
void reglas(int puntajeMayor[3], string nombreDelMayorPuntaje[3])
{
    int opcion;
    rlutil::locate(48,2);
    cout << "REGLAS CIEN O ESCALER" << endl;
    for (int j=0; j<6; j++)
    {
        tirarAEleccion ( j+1, (j + 3) *10,4,0);
    }
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(1,9);
    cout << "El objetivo del juego es obtener al menos 100 puntos en la menor cantidad posible de  rondas, o sacar una escalera en un lanzamiento " ;
    rlutil::locate(1,12);
    cout << "El puntaje de un lanzamiento esta determinado por una serie de reglas que figuran en la sección Combinaciones con puntos " ;
    rlutil::locate(1,14);
    cout << "Una ronda esta compuesta por 3 lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje " ;
    rlutil::locate(1,17);
    cout << "El puntaje final de la ronda sera el valor maximo de los puntos obtenidos en los 3 lanzamientos (no la suma de los tres, sino el mas alto), con las siguientes excepciones: ";
    rlutil::locate(1,19);
    cout << "-Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento";
    rlutil::locate(1,20);
    cout << "-Si en un lanzamiento se obtiene una combinacion de 6 dados con valor 6, el puntaje total de la persona se resetea a 0" << endl ;
    rlutil::locate(1,22);
    cout << "Para el caso de la opciOn para 2 jugadores, cada jugador debe completar una ronda (3 lanzamientos) alternativamente " << endl ;
    rlutil::locate(46,25);
    cout << "COMBINACIONES CON PUNTOS";
    rlutil::locate(1,27);
    cout << "-Suma de dados" << endl ;
    rlutil::locate(1,28);
    cout << " Suma de los valores de todos los dados Para el ejemplo sería 6+5+5+2+2+1=21" << endl ;
    rlutil::locate(1,30);
    cout << "-Sexteto X (X es el numero del dado)" << endl ;
    rlutil::locate(1,31);
    cout << " 6 dados iguales (menos para el nUmero 6) X*10 puntos " << endl ;
    rlutil::locate(1,33);
    cout << "-Escalera " << endl ;
    rlutil::locate(1,34);
    cout << " Gana la partida en esa ronda " << endl ;
    rlutil::locate(1,36);
    cout << "-Sexteto6 " << endl ;
    rlutil::locate(1,37);
    cout << " Seis 6, Resetea el puntaje total a 0  " ;
    rlutil::locate(45, 40);
    cout << " ==============================" << endl;
    rlutil::locate(45, 41);
    cout << "| 1- MENU                       |" << endl;
    rlutil::locate(45, 42);
    cout << "| 0- FINALIZAR JUEGO            |" << endl;
    rlutil::locate(45, 43);
    cout << " ==============================" << endl;
    rlutil::locate(52, 44);
    cout << "INGRESE SU OPCION: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system("cls");
        menu(puntajeMayor,nombreDelMayorPuntaje);
        break;
    case 0:
        system ("cls");
        return;
    }
}


