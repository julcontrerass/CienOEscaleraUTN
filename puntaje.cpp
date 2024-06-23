#include <iostream>
#include "funciones.h"
#include "rlutil.h"
using namespace std;
int puntaje (int vNumDados[])
{
    int puntajeAux=0, vContDados[6], contRepetidos=0;
    bool sexTeto=false;
    for (int i = 0; i < 6; i++)
    {
        contRepetidos = contarNumerosRepetidos(vNumDados, i+1, 6);
        if (contRepetidos == 6)
        {
            if (vNumDados[0] != 6)
            {
                puntajeAux = vNumDados[0] * 10;
            }
            else
            {
                puntajeAux = 0;
                sexTeto = true;
            }
            break;
        }
    }

    if (puntajeAux == 0 && sexTeto == false)
    {
        puntajeAux += sumarVector(vNumDados, 6);
    }

    ordenarVector(vNumDados, 6);

    bool escalera = true;
    for (int i = 0; i < 6; i++)
    {
        if (vNumDados[i] != i + 1)
        {
            escalera = false;
            break;
        }
    }

    // CORROBORAMOS SI HAY UNA ESCALERA
    if (escalera == true )
    {
        system("cls");
        rlutil::hidecursor();
        rlutil::locate(42,12);
        cout << "------------------------------------" << endl;
        rlutil::locate(42,13);
        cout << "------- HICISTE UNA ESCALERA -------" << endl;
        rlutil::locate(42,14);
        cout << "------------------------------------" << endl;
        puntajeAux = 100;
        ojos(54,16);
        sonrisa(53,21);
    }
    return puntajeAux;
}
