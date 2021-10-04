#ifndef PLANETA_H
#define PLANETA_H

#include <QObject>
#include <QGraphicsPixmapItem>

class planeta : public QObject, public QGraphicsPixmapItem
{
public:
    planeta();
    void escribir_txt();
private:

};

#endif // PLANETA_H
