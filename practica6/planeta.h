#ifndef PLANETA_H
#define PLANETA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

class planeta : public QObject, public QGraphicsPixmapItem
{

public:
    planeta(float Masa,float Radio, float Xo,float Yo,float VoX, float VoY);
    void cinematica();
    void dinamica(QList <planeta *> planet , int a);

    void crear_txt(string name);
    void escribir_txt(string nombre, vector<float> valores);

private:
    int w,h,G=1;
    float x,y,vx,vy,ax,ay,r,m, T;

};

#endif // PLANETA_H
