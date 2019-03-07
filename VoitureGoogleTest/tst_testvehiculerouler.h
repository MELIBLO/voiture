#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "voiture.h"
#include <QDebug>

using namespace testing;

TEST(TestVehiculeRouler, OldCar)
{
    int kmStart = 160000;
    int jaugeStart = 1500;
    Voiture voiture ("Renault Scenic",kmStart,jaugeStart);
    int distance = 100;
    //when
    voiture.rouler(distance);
    EXPECT_EQ(voiture.kilometrage(),kmStart + distance) << "Kilometrage incorrect";
    EXPECT_EQ(voiture.jaugeCarburant(),jaugeStart - distance*10)<< "Jauge Carburant incorrecte";
    // ASSERT_THAT(0, Eq(0));
}

TEST(TestVehiculeRouler, RecentCar)
{
    int kmStart = 10000;
    int jaugeStart = 1500;
    Voiture voiture ("Renault Scenic",kmStart,jaugeStart);
    int distance = 100;
    //when
    voiture.rouler(distance);
    // on confronte une valeur a une liste de valeur
    EXPECT_THAT(voiture.kilometrage(),Eq(kmStart + distance)) << "Kilometrage incorrect";

    EXPECT_THAT(voiture.jaugeCarburant(),Eq(jaugeStart - distance*5))<< "Jauge Carburant incorrecte";
    // ASSERT_THAT(0, Eq(0));
}

TEST(TestVehiculeRouler, NoGaz)
{
    int kmStart = 160000;
    int jaugeStart = 1500;
    Voiture voiture ("Renault Scenic",kmStart,jaugeStart);
    int distance = 300;
    EXPECT_THROW(voiture.rouler(distance),std::invalid_argument);
}

class TestVehiculeRecenteRouler : public TestWithParam<int>
{};

TEST_P(TestVehiculeRecenteRouler, Range)
{
    int kmStart = GetParam();
    int jaugeStart = 1500;
    Voiture voiture ("Renault Scenic",kmStart,jaugeStart);
    int distance = 100;
    //when
    voiture.rouler(distance);
    // on confronte une valeur a une liste de valeur
    EXPECT_THAT(voiture.kilometrage(),Eq(kmStart + distance)) << "Kilometrage incorrect";

    EXPECT_THAT(voiture.jaugeCarburant(),Eq(jaugeStart - distance*5))<< "Jauge Carburant incorrecte";
    // ASSERT_THAT(0, Eq(0));
}
INSTANTIATE_TEST_SUITE_P(GroupVoitureRecente, TestVehiculeRecenteRouler, // test paramétré
                         //Values (0,10000,149999));
                         Range (0,150000,10000));

class TestOldvoitureRouler : public Test
{
protected :
    Voiture oldCar;
    int kmStart;
    int jaugeStart;

    void SetUp() override // vehicule par defaut c comme un new
    {
        kmStart = 160000;
        jaugeStart = 1500;
        oldCar.setKilometrage(kmStart);
        oldCar.setJaugeCarburant(jaugeStart);
        oldCar.setModele("Renault Scenic");
    }

    void TearDown() override // si allocation dynamique tear down permet de nettoyer et de liberer l'espace c comme le delete
    {
        qDebug() << "Do some cleaning";
    }

};

TEST_F(TestOldvoitureRouler, OK)
{
    /*int kmStart = 160000;
    int jaugeStart = 1500;
    Voiture oldCar ("Renault Scenic",kmStart,jaugeStart);
    int distance = 100;
    //when
    oldCar.rouler(distance);
    EXPECT_EQ(oldCar.kilometrage(),kmStart + distance) << "Kilometrage incorrect";
    EXPECT_EQ(oldCar.jaugeCarburant(),jaugeStart - distance*10)<< "Jauge Carburant incorrecte";
    // ASSERT_THAT(0, Eq(0));*/

    //given
    int distance = 100;
    //when /then
    EXPECT_THROW(oldCar.rouler(distance),std::invalid_argument);
    EXPECT_THAT(oldCar.kilometrage(),Eq(kmStart));
    EXPECT_THAT(oldCar.jaugeCarburant(),Eq(jaugeStart));
}
