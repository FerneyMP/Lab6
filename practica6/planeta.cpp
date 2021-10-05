#include "planeta.h"

planeta::planeta()
{

}

void planeta::crear_txt(string name)
{
    fstream text(name, fstream::out);
    text.close();
}


void planeta::escribir_txt(string nombre, vector<int> valores)
{

    fstream text (nombre, fstream::out);
    string estructura = "Masa       Radio      PosInicialX    PosInicialY     VelInicialX      VelInicialY\n";
    string tabulador  = "    ";
    for(vector<int>::iterator i=valores.begin(); i<valores.end(); i++){
        //valores.at(i);
        text >> *i;
        text >> tabulador;
    }
    valores.clear();
    text.close();
}
