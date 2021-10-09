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
    planeta(float Xo,float Yo,float VoX, float VoY, float Masa,float Radio, int width, int height);
    void cinematica();
    void dinamica(QList <planeta *> planet , int a);

    void crear_txt(string name);
    void escribir_txt(string nombre, vector<float> valores);

     float x,y,vx,vy,ax,ay,r,m, T;

private:
    int w,h,G=1;


};

#endif // PLANETA_H
