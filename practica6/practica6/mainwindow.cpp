#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //scene->addItem()
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
    float aceleracionX, aceleracionY, velocidadX, velocidadY, posicionX, posicionY, magnitud;

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

    //Se tiene pensado hacer la sumatoria de las masas


    aceleracionX = (G*(sum_masas()))*(posi_posk_x())/((magnitud)*(magnitud)*(magnitud));
    velocidadX   = VoX + aceleracionX*T;
    posicionX    = Xo + velocidadX*T;

    aceleracionY = (G*(sum_masas()))*(posi_posk_y())/((magnitud)*(magnitud)*(magnitud));
    velocidadY   = VoY + aceleracionY*T;
    posicionY    = Yo + velocidadY*T;



    Planetas->setPos(int (posicionX),int (posicionY)); //posicionar ecuaciones
    //aumentar el contador:
    n++;

    //agregar boton #de planetas [planeta1....planetan]

    //Intentar:

    //agregar a escena
    //cantidad de pixeles a mover setPos(x,y)


    //solo 1 planeta, fórmulas solamente

    //varios planetas, for, aceleraciones dependen de los demás datos

    //ARREGLAR FOR DE CONDICIONAL

    //vector de flotantes o enteros

}

void MainWindow::on_AgregarDatos_clicked()
{
    //Función para recibir todos los datos
    NumPlanet = ui->numero_planetas->value();
    ui->iniciar->setEnabled(true); //inicia la simulación
    ui->AgregarDatos->setEnabled(false); //se desactiva la opción agregar datos
    for(int i=0; i<NumPlanet; i++)
    {
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

        Planetas->escribir_txt("Simulacion", values);

       if(i>4){
           ui->iniciar->setEnabled(false);
           ui->parar->setEnabled(false);
           ui->AgregarDatos->setEnabled(false);
       }

    }

    Planetas->setPos(Xo,Yo);// agregar posición x e y

    //Planetas->escribir_txt("Simulacion", values);
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
    //contador_planetas++;
    Timer->stop();
    //scene->removeItem(Planetas);
    n=0;
}

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


