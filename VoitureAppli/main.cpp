#include <QCoreApplication>
#include <QDebug>
#include"voiture.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << " Welcome to Voiture Application. ";
    Voiture oldCar ("Renault Scenic", 160000, 500);
    oldCar.rouler(10);
    qDebug() << " My car is: " <<oldCar.modele();
    return a.exec();
}
