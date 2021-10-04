#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_scene();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete Timer;
}

void MainWindow::setup_scene()
{
    scene = new QGraphicsScene;
    Timer = new QTimer;
    //planeta_ = new planeta;

    //botones inicar y parar, apagados por defecto
    ui->iniciar->setEnabled(false);
    ui->parar->setEnabled(false);

    connect(Timer,SIGNAL(timeout()),this,SLOT(simulacion()));

    //se definen las dimensiones de la escena
    scene->setSceneRect(0,0,ui->graphicsView->width()-2, ui->graphicsView->height()-2);

    ui->graphicsView->setScene(scene);
}

void MainWindow::simulacion()
{
    int aceleracion, velocidad, posicion;
    int sum = 0;
    //sum = (Masa*(Xo))/
    aceleracion = G*(sum);
    velocidad = VoX + aceleracion*T;
    //posicion =
    //Ecuaciones necesarias para el generar la simulación
    //int x,y;
    //ejemplo:
    //x =
    //planeta->setPos(int (x),int (ui->graphicsView->heoght()-y)); //posicionar ecuaciones
    // rotar sistema coordenado. y2=0 --> y1= h(graphicsView)
    //                           y2=h --> y1=0
    //                           y1=h-y2 ---> ui->graphicsView->heoght()-y

    //aumentar el contador:
    //n++;
}

void MainWindow::on_AgregarDatos_clicked()
{
    //Función para recibir todos los datos
    Masa = ui->Masa->value();
    Radio = ui->Radio->value();
    Xo = ui->Xo->value();
    Yo = ui->Yo->value();
    VoX = ui->VoX->value();
    VoY = ui->VoY->value();

    ui->iniciar->setEnabled(true); //inicia la simulación
    ui->AgregarDatos->setEnabled(false); //se desactiva la opción agregar datos
}

void MainWindow::on_iniciar_clicked()
{
    ui->parar->setEnabled(true);
    ui->iniciar->setEnabled(false);
    //planeta->setPos(int (Xo),int (ui->graphicsView->heoght()-Yo));
    //scene->addItem(planeta);
    Timer->start(T);


}

void MainWindow::on_parar_clicked()
{
    ui->parar->setEnabled(false);
    //Agregar una nueva simulación
    ui->AgregarDatos->setEnabled(true);
    Timer->stop();
    //scene->removeItem(planeta);
}
