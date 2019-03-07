#include "voiture.h"

Voiture::Voiture()
{

}

Voiture::Voiture(QString modele, int kilometrage, int jaugeCarburant): mModele(modele),mKilometrage(kilometrage),mJaugeCarburant(jaugeCarburant)
{

}

Voiture::~Voiture()
{

}

QString Voiture::modele() const
{
    return mModele;
}

void Voiture::setModele(const QString &modele)
{
    mModele = modele;
}

int Voiture::kilometrage() const
{
    return mKilometrage;
}

void Voiture::setKilometrage(int kilometrage)
{
    mKilometrage = kilometrage;
}

int Voiture::jaugeCarburant() const
{
    return mJaugeCarburant;
}

void Voiture::setJaugeCarburant(int jaugeCarburant)
{
    mJaugeCarburant = jaugeCarburant;
}

void Voiture::rouler(int kilometre)
{
// if précondition pa vérifiée
    throw  std::invalid_argument("pas assez d'essence");

}




