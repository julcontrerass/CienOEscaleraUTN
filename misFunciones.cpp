#include <iostream>

using namespace std;

#include "funciones.h"
#include "rlutil.h"
#include "misFunciones.h"

/// CREAMOS UNA COPA PARA EL RANKING
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

/// UNA SONRISA PARA EL QUE HAGA ESCALERA O GANE
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

/// UNA SONRISA TRISTE PARA EL QUE EL TOQUE SEXTETO DE 6
void triste (int x, int y){
    rlutil::hidecursor();
    rlutil::locate(x,y+2);
    cout<< (char)220<< endl;
    rlutil::locate(x+1,y+2);
    cout<< (char)223;
    rlutil::locate(x+2,y+1);
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

    rlutil::locate(x+10,y+1);
    cout<< (char)220 ;
    rlutil::locate(x+11,y+2);
    cout<< (char)223 ;
    rlutil::locate(x+12,y+2);
    cout<< (char)220;
    cout << endl;
}

/// OJOS PARA LA SONRISA O EL TRISTE
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

/// CORONA PARA EL GANADOR DE LA PARTIDA
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
        }
        else
        {
            rlutil::locate(x+i,y);
            cout<< (char)220;
        }
    }
}

