#ifndef RECIPE_H
#define RECIPE_H

#include <QCoreApplication>
#include "alcool.h"
#include <dilluant.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Recipe
{
    private:
        std::vector<Alcool> alcools;
        std::vector<Dilluant> dilluants;
        std::vector<std::string> nomsAlcools;
        std::vector<std::string> nomsDilluants;
        std::vector<std::string> tout;
        std::string name;
        double price;
        std::string difficulty;
        std::string instructions;
        QString imageName;
        QImage image;
    public:
        Recipe() = default;
        Recipe(std::vector<Alcool>,std::vector<Dilluant>,std::string,double,std::string,std::string, QString imageName, QImage image);
        void listAlcools();
        void listDilluants();
        void listTout();
        void afficheAlcools();
        void afficheDilluants();
        void initialiser();
        inline std::vector<Alcool> getAlcools() const {return alcools;}
        inline std::vector<Dilluant> getDilluants() const {return dilluants;}
        inline std::vector<std::string> getTout() const {return tout;}
        inline std::string getName() const {return name;}
        inline double getPrix() const {return price;}
        inline std::string getDifficulty() const {return difficulty;}
        inline std::string getInstructions() const {return instructions;}
        inline QString getImageName() const {return imageName;}
        inline QImage getImage() const {return image;}
};

#endif // RECIPE_H
