#include <iostream>
#include "funciones.h"
#include "rlutil.h"
using namespace std;
int puntaje (int vNumDados[])
{
    int puntajeAux=0, vContDados[6];
    bool sexTeto=true;

    ponerCero(vContDados, 6);
    for (int i = 0; i < 6; i++)
    {
        switch (vNumDados[i])
        {
        case 1:
            vContDados[0]++;
            break;
        case 2:
            vContDados[1]++;
            break;
        case 3:
            vContDados[2]++;
            break;
        case 4:
            vContDados[3]++;
            break;
        case 5:
            vContDados[4]++;
            break;
        case 6:
            vContDados[5]++;
            break;
        }
    }
    if (vContDados[5] == 6)
    {
        puntajeAux = 0;
        sexTeto=false;

    }

    for (int i = 0; i < 5; i++)
    {
        if (vContDados[i] == 6)
        {
            puntajeAux = vNumDados[i] * 10;
        }
    }

    if (puntajeAux == 0 && sexTeto==true)
    {
        puntajeAux += sumarVector(vNumDados, 6 );
    }


    ordenarVector(vNumDados, 6 );
    bool escalera=false;
    for (int i=0 ; i<6 ; i++)
    {
        if (vNumDados[5] == 6)
        {
            escalera=true;
        }
        else
        {
            escalera=false;
        }
    }
    // CORROBORAMOS SI HAY UNA ESCALERA
    if (escalera == true   )
    {
        system("cls");
        rlutil::hidecursor();
        rlutil::locate(44,12);
        cout << "------------------------------------" << endl;
        rlutil::locate(44,13);

        cout << "------- HICISTE UNA ESCALERA -------" << endl;
        rlutil::locate(44,14);

        cout << "------------------------------------" << endl;
        puntajeAux = 100;
    }

    return puntajeAux;
}
