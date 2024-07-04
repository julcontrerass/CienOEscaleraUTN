#include <iostream>

using namespace std;

#include "funciones.h"
#include "rlutil.h"
#include "misFunciones.h"


int puntaje (int vNumDados[])
{
    int puntajeAux=0, vContDados[6], contRepetidos=0;
    bool sexTeto=false;
    for (int i = 0; i < 6; i++)
    {
        contRepetidos = contarNumerosRepetidos(vNumDados, i+1, 6); /// VEMOS SI TENEMOS ALGUN NUMERO REPEDIDO
        if (contRepetidos == 6) /// EN EL CASO DE QUE HAYA SALIDO UN NUMERO REPETIDO 6 VECES
        {
            if (vNumDados[0] != 6) /// SI ESE NUMERO REPETIDO ES DIFERENTE A 6 ENTONCES HACE LA CUENTA CORRESPONDIENTE
            {
                puntajeAux = vNumDados[0] * 10;
            }
            else /// Y SI NO TENEMOS EL SEXTETO DE 6 POR ENDE VAMOS A TENER UN PUNTAJE DE 6
            {
                puntajeAux = 0;
                sexTeto = true;
                system("cls");
                rlutil::hidecursor();
                rlutil::locate(37,10);
                cout << "-----------------------------------------------------" << endl;
                rlutil::locate(37,11);
                cout << "- HICISTE SEXTETO DE 6, TU PUNTAJE SE REINICIA A 0  -" << endl;
                rlutil::locate(37,12);
                cout << "-----------------------------------------------------" << endl;
                ojos(56, 15);
                triste (55, 19);
            }
            break;
        }
    }
    if (puntajeAux == 0 && sexTeto == false) /// SI NO SE CUMPLIO NINGUNA DE LAS ANTERIORES CONDICIONES VAMOS A HACER LA CUENTA Y LO REEMPLAZAMOS EN NUESTRO PUNTAJE
    {
        puntajeAux = sumarVector(vNumDados, 6);
    }

    ordenarVector(vNumDados, 6);

    bool escalera = true;
    for (int i = 0; i < 6; i++)  /// VERIFICAMOS SI TENEMOS UNA ESCALERA ORDENANDO EL ARRAY
    {
        if (vNumDados[i] != i + 1)
        {
            escalera = false;
            break;
        }
    }

    // CORROBORAMOS SI HAY UNA ESCALERA
    if (escalera == true ) /// SI HAY ESCALERA ENTONCENCES EL PUNTAJE
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

