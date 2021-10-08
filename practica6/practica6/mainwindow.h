#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "planeta.h"
#include <QTimer>
#include <vector>
#include <math.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//#define T 0.4
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setup_scene();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *Timer;
    planeta *Planetas;
    float Xo,VoX,Yo,VoY,Radio,Masa,NumPlanet;
    float G = 1;
    int T = 1; //Periodo en milisegundos
    unsigned long long n = 0;
    //int contador_planetas = 0;

    vector<int> values;

private slots:
    void simulacion();
    void on_AgregarDatos_clicked();
    void on_iniciar_clicked();
    void on_parar_clicked();
    float sum_masas();
    float posi_posk_x();
    float posi_posk_y();
    //float get_velX();
    //float get_velY();
};
#endif // MAINWINDOW_H
