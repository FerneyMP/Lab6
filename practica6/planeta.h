#ifndef PLANETA_H
#define PLANETA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class planeta : public QObject, public QGraphicsPixmapItem
{
public:
    planeta();
    void crear_txt(string name);
    void escribir_txt(string nombre, vector<int> valores);

private:
    int w,h;

};

#endif // PLANETA_H
