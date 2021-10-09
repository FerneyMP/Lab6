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
    delete Planetas;
}


void MainWindow::setup_scene()
{
    scene = new QGraphicsScene;
    Timer = new QTimer;

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
    float posicionX, posicionY;

    for (int i =0; i<lista_planetas.size();i++){
        lista_planetas[i]->dinamica(lista_planetas,i);
        lista_planetas[i]->cinematica();

        //actualizar interfaz?
        Planetas->setPos(int (posicionX),int (posicionY)); //posicionar ecuaciones
        n++;

    }
}


void MainWindow::on_AgregarDatos_clicked()  //Función para recibir todos los datos
{
    NumPlanet = ui->numero_planetas->value();
    ui->iniciar->setEnabled(true); //inicia la simulación
    ui->AgregarDatos->setEnabled(false); //se desactiva la opción agregar datos
    ui->numero_planetas->setEnabled(false);

    Masa = ui->Masa->value();
    values.push_back(Masa);

    Radio = ui->Radio->value();
    values.push_back(Radio);

    Xo = ui->Xo->value();
    values.push_back(Xo);

    Yo = ui->Yo->value();
    values.push_back(Yo);

    VoX = ui->VoX->value();
    values.push_back(VoX);

    VoY = ui->VoY->value();
    values.push_back(VoY);

    Planetas = new planeta(Masa, Radio, Xo,Yo, VoX, VoY);
    lista_planetas[contador_L]=Planetas;
    contador_L++;

    //Planetas->setPos(Xo,Yo); // agregar posición x e y
    Planetas->setPos(int (Xo),int (ui->graphicsView->height()-Yo));
    scene->addItem(Planetas);

}


void MainWindow::on_iniciar_clicked()
{
    Planetas->escribir_txt("Simulacion", values);
    ui->parar->setEnabled(true);
    ui->iniciar->setDisabled(true); //aqui va true?
    Timer->start(T);

}


void MainWindow::on_parar_clicked()
{
    ui->parar->setEnabled(false);
    //Agregar una nueva simulación
    ui->AgregarDatos->setEnabled(true);
    Timer->stop();
    //scene->removeItem(Planetas);
    n=0;
}


/*

float MainWindow::sum_masas()
{
    int sum = 0;
    //i depende de la cantidad de planeta que hayan
    //j suma cada 6 valores que es cada información de cada planeta
    for(int i=0, j=0; sum<NumPlanet; i++,j+=6){
        sum += values[j];
    }
    return sum;
}

float MainWindow::posi_posk_x()
{
    int x = 0;
    for(int i=0, j=2; i<NumPlanet; i++,j+=6){
        x = (values[j]- values[j]);
    }
    return x;
}

float MainWindow::posi_posk_y()
{
    int y = 0;
    for(int i=0, j=3; i<NumPlanet; i++,j+=6){
        y = (values[j]- values[j]);
    }
    return y;
}


*/