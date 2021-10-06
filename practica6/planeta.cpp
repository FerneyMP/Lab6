#include "planeta.h"

planeta::planeta()
{
    QPixmap j(":/new/prefix1/resource/saturno.jpg");
    //h = heigth;
    //w = width;
    setPixmap(j.scaled(w,h));
}

void planeta::crear_txt(string name)
{
    fstream text(name, fstream::out);
    text.close();
}


void planeta::escribir_txt(string nombre, vector<int> valores)
{

    fstream text (nombre, fstream::out);
    string estructura = "Masa       Radio        PosIniX      PosIniY       VelIniX       VelIniY\n";
    string tabulador  = "       ";
    text << estructura;
    for(vector<int>::iterator i=valores.begin(); i<valores.end(); i++){
        text << *i;
        text << "    " << tabulador;
    }
    text << "\n";
    valores.clear();
    text.close();
}
