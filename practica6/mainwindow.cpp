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
    Planetas = new planeta;

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
    int aceleracionX, aceleracionY, velocidadX, velocidadY, posicionX, posicionY, magnitud;
    int sum = 0;
    magnitud = sqrt( ( (Xo)*(Xo) ) + ( (Yo)*(Yo) ));

    /* Ideas:
     For que reciba a i y la condición de terminación la cantidad de planetas ingresados
     es decir, un contador que se incremente cada vez que se de en agregar datos, de allí depende la terminación
     de mi ciclo for, luego agregar la fórmula de aceleración de los cuerpos
     *
     *
     *
     *
     *
    */
    //Ecuaciones necesarias para el generar la simulación
    for(int i=0; i<contador_planetas; i++){
        sum += Masa;
        aceleracionX = (G*(sum))/((magnitud)*(magnitud)*(magnitud));
        velocidadX   = VoX + aceleracionX*T;
        posicionX    = Xo + velocidadX*T;

        aceleracionY = (G*(sum))/((magnitud)*(magnitud)*(magnitud));
        velocidadY   = VoY + aceleracionY*T;
        posicionY    = Yo + velocidadY*T;
    }


    Planetas->setPos(int (posicionX),int (posicionY)); //posicionar ecuaciones
    //aumentar el contador:
    n++;
}

void MainWindow::on_AgregarDatos_clicked()
{
    //Función para recibir todos los datos
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

    ui->iniciar->setEnabled(true); //inicia la simulación
    ui->AgregarDatos->setEnabled(false); //se desactiva la opción agregar datos

    Planetas->setPos(int(0),int(0));

    Planetas->escribir_txt("Simulacion", values);
}

void MainWindow::on_iniciar_clicked()
{
    ui->parar->setEnabled(true);
    ui->iniciar->setEnabled(false);
    Planetas->setPos(int (Xo),int (ui->graphicsView->height()-Yo));
    scene->addItem(Planetas);
    Timer->start(T);


}

void MainWindow::on_parar_clicked()
{
    ui->parar->setEnabled(false);
    //Agregar una nueva simulación
    ui->AgregarDatos->setEnabled(true);
    contador_planetas++;
    Timer->stop();
    //scene->removeItem(Planetas);
}
