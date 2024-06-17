#include <iostream>
#include "funciones.h"

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
    if (vContDados[5] == 6) {
        puntajeAux = 0;
        sexTeto=false;

    }
    for (int i = 0; i < 5; i++) {
        if (vContDados[i] == 6) {
            puntajeAux = vNumDados[i] * 10;
        }
    }
    if (puntajeAux == 0 && sexTeto==true){
        puntajeAux += sumarVector(vNumDados, 6 );
    }


    ordenarVector(vNumDados, 6 );

    //VEMOS SI HAY ESCALERA
    bool hay1=false,hay2=false,hay3=false,hay4=false,hay5=false,hay6=false;

    if(vNumDados[0] == 1)
    {
        hay1=true;
    }
    if(vNumDados[1] == 2)
    {
        hay2=true;
    }
    if(vNumDados[2] == 3)
    {
        hay3=true;
    }
    if(vNumDados[3] == 4)
    {
        hay4=true;
    }
    if(vNumDados[4] == 5)
    {
        hay5=true;
    }
    if(vNumDados[5] == 6)
    {
        hay6=true;
    }

    // CORROBORAMOS SI HAY UNA ESCALERA
    if (hay1 == true && hay2 == true &&hay3 == true &&hay4 == true && hay5 == true && hay6 == true  )
    {
        system("cls");
        cout << "------------------------------------" << endl;
        cout << "------- HICISTE UNA ESCALERA -------" << endl;
        cout << "------------------------------------" << endl;
        puntajeAux = 100;
    }

    return puntajeAux;
}
