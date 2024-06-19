#include <iostream>
#include "funciones.h"
#include "rlutil.h"
using namespace std;

//NUESTRAS FUNCIONES
void copa(int x, int y )
{
    rlutil::hidecursor();
    rlutil::locate(x,y);
    cout<< "("<< (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << ")" << endl;
    rlutil::locate(x,++y);
    cout<< " " << (char)223 << (char)219 << (char)219 << (char)219 << (char)223 << endl;
    rlutil::locate(x,++y);
    cout<< " " << (char)220 << (char)220 << (char)219 << (char)220 << (char)220 << endl;

}
void sonrisa(int x, int y )
{
    rlutil::hidecursor();
    rlutil::locate(x,y);
    cout<< (char)220<< endl;
    rlutil::locate(x+1,++y);
    cout<< (char)223;
    rlutil::locate(x+2,y);
    cout<< (char)220 << endl;
    rlutil::locate(x+3,y+1);
    cout<< (char)223 ;
    rlutil::locate(x+4,y+1);
    cout<< (char)223 ;
    rlutil::locate(x+5,y+1);
    cout<< (char)223 ;
    rlutil::locate(x+6,y+1);
    cout<< (char)223 ;
    rlutil::locate(x+7,y+1);
    cout<< (char)223 ;
    rlutil::locate(x+8,y+1);
    cout<< (char)223 ;
    rlutil::locate(x+9,y+1);
    cout<< (char)223 ;
    rlutil::locate(x+10,y);
    cout<< (char)220 ;
    rlutil::locate(x+11,y);
    cout<< (char)223 ;
    rlutil::locate(x+12,y-1);
    cout<< (char)220;
    cout << endl;
}
void ojos(int x, int y )
{
    rlutil::hidecursor();
    //lado izquierdo
    rlutil::locate(x,y);
    cout<< (char)223;
    rlutil::locate(x+1,y);
    cout<< (char)220<< endl;
    rlutil::locate(x+2,y+1);
    cout<< (char)223;
    rlutil::locate(x+3,y+1);
    cout<< (char)220<< endl;
    rlutil::locate(x+2,y+2);
    cout<< (char)223<< endl;
    rlutil::locate(x+1,y+2);
    cout<< (char)220<< endl;
    rlutil::locate(x,y+3);
    cout<< (char)223<< endl;
    //lado derecho

    rlutil::locate(x+10,y);
    cout<< (char)223;
    rlutil::locate(x+9,y);
    cout<< (char)220<< endl;
    rlutil::locate(x+8,y+1);
    cout<< (char)223;
    rlutil::locate(x+7,y+1);
    cout<< (char)220<< endl;
    rlutil::locate(x+8,y+2);
    cout<< (char)223<< endl;
    rlutil::locate(x+9,y+2);
    cout<< (char)220<< endl;
    rlutil::locate(x+10,y+3);
    cout<< (char)223<< endl;
}
void corona(int x, int y )
{
    rlutil::hidecursor();
    //lado izquierdo
    rlutil::locate(x,y);
    cout<< (char)219<< endl;
    rlutil::locate(x+1,y);
    cout<< (char)220<< endl;
    rlutil::locate(x,y+1);
    cout<< (char)219<< endl;
    rlutil::locate(x+2,y+1);
    cout<< (char)219;
    rlutil::locate(x+3,y+1);
    cout<< (char)220;
    rlutil::locate(x+4,y+1);
    cout<< (char)219;
    rlutil::locate(x+5,y);
    cout<< (char)220<< endl;
    rlutil::locate(x+6,y);
    cout<< (char)223<< endl;
    rlutil::locate(x+7,y);
    cout<< (char)220<< endl;
    rlutil::locate(x+8,y+1);
    cout<< (char)219<< endl;
    rlutil::locate(x+9,y+1);
    cout<< (char)220;
    rlutil::locate(x+10,y+1);
    cout<< (char)219;
    rlutil::locate(x+11,y);
    cout<< (char)220<< endl;
    rlutil::locate(x+12,y);
    cout<< (char)219<< endl;
    rlutil::locate(x+12,y+1);
    cout<< (char)219<< endl;
    rlutil::locate(x+12,y+2);
    cout<< (char)219<< endl;
    rlutil::locate(x,y++);
    cout<< (char)219<< endl;
    rlutil::locate(x,y++);
    cout<< (char)219;
    rlutil::locate(x,y);
    cout<< (char)220;
    rlutil::locate(x,y);
    cout<< (char)220;
    for (int i=0; i<12; i++)
    {
        if (i==0)
        {
            rlutil::locate(x,y);
            cout<< (char)219<< endl;
        }else {
        rlutil::locate(x+i,y);
        cout<< (char)220;
        }
    }



}

// FUNCIONES DEL PROFE
/// Desarrollo de funciones / Definiciones
int posicionNumeroEnVector(int v[],int tam, int numero)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(v[i]==numero) return i;
    }
    return -1;
}
int minimoVector(int v[], int tam)
{
    int i, posMin=0;
    for(i=1; i<tam; i++)
    {
        if(v[i]<v[posMin])
        {
            posMin=i;
        }
    }
    return posMin;
}
void ordenarVector(int v[], int tam )
{
    int i,j, posmin, aux;
    for(i=0; i<tam-1; i++)
    {
        posmin=i;
        for(j=i+1; j<tam; j++)
        {
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

int maximoVector(int v[], int tam)
{
    int i, posMax=0;
    for(i=1; i<tam; i++)
    {
        if(v[i]>v[posMax])
        {
            posMax=i;
        }
    }
    return posMax;
}

void cargarAleatorio(int v[], int tam, int limite)
{
    int i;
    srand(time(NULL));
    for( i=0; i<tam; i++ )
    {
        v[i]=(rand()%limite)+1;
    }
}

void mostrarVector(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cout<<v[i]<<"\t";
    }
}


int contarNumerosRepetidos(int v[], int numero, int tam)
{
    int i, cant=0;
    for(i=0; i<tam; i++)
    {
        if(v[i]==numero) cant++;
    }
    return cant;
}


void ponerCero(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        v[i]=0;
    }
}


int sumarVector(int v[], int tam )
{
    int i, suma=0;
    for(i=0; i<tam; i++)
    {
        suma+=v[i];
    }
    return suma;
}


void copiarVector(int v[], int v2[],int tam )
{
    int i;
    for(i=0; i<tam; i++)
    {
        v2[i]=v[i];
    }
}

bool compararVectores(int v[], int v2[],int tam )
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(v2[i]!=v[i]) return false;
    }
    return true;
}

void cargarVector(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cout<<"INGRESE NUMERO: ";
        cin>>v[i];
    }
}
