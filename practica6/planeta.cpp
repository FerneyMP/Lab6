#include "planeta.h"

planeta::planeta(float Masa,float Radio, float Xo,float Yo,float VoX, float VoY)
{
    QPixmap j(":/new/prefix1/resource/p.jpg");
    setPixmap(j.scaled(w,h));
    x=Xo;
    y= Yo;
    vx= VoX;
    vy= VoY;
    r=Radio;
    m=Masa;

}

void planeta::crear_txt(string name)
{
    fstream text(name, fstream::out);
    text.close();
}


void planeta::escribir_txt(string nombre, vector<float> valores)
{
    fstream text (nombre, fstream::out);
    string estructura = "Masa       Radio        PosIniX      PosIniY       VelIniX       VelIniY\n";
    string tabulador  = "       ";
    text << estructura;
    for(vector<float>::iterator i=valores.begin(); i<valores.end(); i++){
        text << *i;
        text << "    " << tabulador;
    }
    text << "\n";
    valores.clear();
    text.close();
}

                         //Ecuaciones necesarias para el generar la simulación

void planeta::cinematica() //cinematica
{
    vx  +=  ax*T;
    vy  +=  ay*T;
    x   +=  vx*T;
    y   +=  vy*T;
}

void planeta::dinamica(QList <planeta *> planet, int a) //aceleraciones
{
    ax=0, ay=0;
    for (int i=0; i<planet.size(); i++){
        if (i!=a){
            r=sqrt(pow((x2-x),2)+pow((y2-y),2)); //distancia entre dos puntos
            ax = G*((m*(x2-x))/pow(r,3));
            ay = G*((m*(y2-y))/pow(r,3));
        }
    }
}
