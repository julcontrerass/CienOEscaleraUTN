#include <iostream>
#include "rlutil.h"

using namespace std;

//CREAMOS EL FONDO DEL DADO
void Dados(int posx,int posy)
{
    rlutil::setColor(rlutil::WHITE);
    //SOLICITAMOS EL INGRESE DE LA X E Y QUE A MEDIDA QUE VA PASANDO EL FOR VA PINTANTO CADA PIXEL
    for (int x=posx ; x<=posx+6; x++)
    {
        for (int y=posy; y<=posy+2; y++)
        {
            rlutil::locate (x,y);
            cout << (char) 219;
        }
    }
}

//CREAMOS LOS NUMERO DE LOS DADOS
void NumDado (int numero, int posx, int posy)
{
    int valor;
    // LLAMAMOS A LA FUNCION DADO PARA YA TENER EL FONDO PINTADO
    Dados(posx,posy);
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
    //DECLARAMOS QUE POR CADA NUMERO SE PINTE EK DADO CORRESPONDIETE
    switch(numero)
    {
    case 1:
        // POR EJEMPLO EN LA POSICION DE X 4 Y Y 2 PINTAMOS UN CUADRADITO CON (char)254
        rlutil::locate(posx+3,posy+1);
        cout << (char)254;
        break;
    case 2:
        rlutil::locate(posx+1,posy);
        cout << (char) 220;
        rlutil::locate(posx+5,posy+2);
        cout << (char) 223;
        break;
    case 3:
        rlutil::locate(posx+1,posy);
        cout << (char) 220;
        rlutil::locate(posx+5,posy+2);
        cout << (char) 223;
        rlutil::locate(posx+3,posy+1);
        cout << (char)254;
        break;
    case 4:
        rlutil::locate(posx+1,posy);
        cout << (char) 220;
        rlutil::locate(posx+5,posy);
        cout << (char) 220;
        rlutil::locate(posx+1,posy+2);
        cout << (char) 223;
        rlutil::locate(posx+5,posy+2);
        cout << (char) 223;
        break;
    case 5:
        rlutil::locate(posx+1,posy);
        cout << (char) 220;
        rlutil::locate(posx+5,posy);
        cout << (char) 220;
        rlutil::locate(posx+3,posy+1);
        cout << (char)254;
        rlutil::locate(posx+1,posy+2);
        cout << (char) 223;
        rlutil::locate(posx+5,posy+2);
        cout << (char) 223;
        break;
    case 6:
        rlutil::locate(posx+1,posy);
        cout << (char) 220;
        rlutil::locate(posx+5,posy);
        cout << (char) 220;
        rlutil::locate(posx+1,posy+2);
        cout << (char) 223;
        rlutil::locate(posx+5,posy+2);
        cout << (char) 223;
        rlutil::locate(posx+3,posy);
        cout << (char) 220;
        rlutil::locate(posx+3,posy+2);
        cout << (char) 223;
        break;
    }
}

// CREAMOS LA FUNCION DE TIRAR QUE LLAMAMOS A LA FUNCION DE NumDado Y LE DAMOS UN VALOR RANDOM PARA QUE VAYAN APARECIENDO DIFERNTES NUMEROS DE DADOPARA QUE SEA UN DADO ALEATORIO

/// EL FOR INTERNO LO QUE NOS HACES ES DARNOS 20 NUMEROS ENTRE 1 Y 6 ALEATORIO Y LE PONEMOS UNA PAUSA PARA QUE HAGA EL EFECTO DE QUE PASAR VARIOS DADOS
int tirar (int posx, int posy)
{
    int dado = rand() %6 +1;

    for (int i=0; i<20; i++)
    {
        NumDado(rand()%6+1,posx,posy);
        rlutil::msleep(5);
    }
    NumDado(dado,posx,posy);
    return dado;
}

/// CREAMOS UNA FUNCION PARA EL USUARIO PUEDA ELEGIR LOS DADOS QUE QUIERA QUE SALGA DANDOLE EL VALOR EL
int tirarAEleccion (int numero, int posx, int posy, int op )/// OP ES PARA USAR EN EL CODIGO DE REGLA PARA QUE NO ME HAGA EFECTO DE TIRAR Y QUE ME QUEDEN FIJAS
{
    if(op == 1) /// SI PONGO UNO AL LLAMAR A LA FUNCION POR EJEMPLO EN MODO SIMULACION ENTONCES SI NOS HACE EL EFECTO
    {
        for (int i=0; i<20; i++)
        {
            NumDado(rand()%6+1,posx,posy);
            rlutil::msleep(5);
        }
    }
    NumDado(numero,posx,posy);
    return numero;
}


