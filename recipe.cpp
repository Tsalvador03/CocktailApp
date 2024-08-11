#include "recipe.h"

Recipe::Recipe(std::vector<Alcool> _alcools, std::vector<Dilluant> _dilluants, std::string _name, double _price, std::string _difficulty,std::string _instructions, QString _imageName, QImage _image)
    :alcools(_alcools),dilluants(_dilluants),name(_name),price(_price),difficulty(_difficulty), instructions(_instructions), imageName(_imageName), image(_image){}

void Recipe::listAlcools() {
    QString appDir = QCoreApplication::applicationDirPath();
    std::string spath = appDir.toStdString();
    std::string fileName = spath+"/alcools.csv";
    std::ifstream fic(fileName);
    if (!fic.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << fileName << std::endl;
        return;
    }
    std::string line;
    std::string temp;
    while (std::getline(fic, line)) {
        Alcool a;
        std::stringstream ss(line);
        std::getline(ss, temp, ',');
        a.setName(temp);
        std::getline(ss, temp, ',');
        a.setPrice(std::stod(temp));
        std::getline(ss, temp, ',');
        QString path = appDir;
        QString qtemp = QString::fromStdString(temp);
        path += qtemp;
        a.setImageName(path);
        QImage pic(path);
        a.setImage(pic);
        alcools.push_back(a);
    }
    fic.close();
}

void Recipe::listDilluants() {
    QString appDir = QCoreApplication::applicationDirPath();
    std::string spath = appDir.toStdString();
    std::string fileName = spath+"/dilluants.csv";
    std::ifstream fic(fileName);
    if (!fic.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << fileName << std::endl;
        return;
    }
    std::string line;
    std::string temp;
    while (std::getline(fic, line)) {
        Dilluant d;
        std::stringstream ss(line);
        std::getline(ss, temp, ',');
        d.setName(temp);
        std::getline(ss, temp, ',');
        d.setPrice(std::stod(temp));
        std::getline(ss, temp, ',');
        QString path = appDir;
        QString qtemp = QString::fromStdString(temp);
        path += qtemp;
        d.setImageName(path);
        QImage pic(path);
        if (pic.isNull()) {
            std::cerr << "Erreur: Impossible de charger l'image " << temp << std::endl;
        }
        d.setImage(pic);
        dilluants.push_back(d);
    }
    fic.close();
}

void Recipe::listTout(){
    for(Alcool a : alcools){
        tout.push_back(a.getName());
    }
    for(Dilluant d : dilluants){
        tout.push_back(d.getName());
    }

}

void Recipe::afficheAlcools() {
    for (const Alcool &a : alcools) {
        std::string name = a.getName();
        double price = a.getPrice();
        std::string sprice = std::to_string(price);
        QString imageName = a.getImageName();
        std::string iName = imageName.toStdString();
        std::cout << "Nom : " << name << " , prix : " << sprice << " , path : " << iName << std::endl;
    }
}

void Recipe::afficheDilluants() {
    for (const Dilluant &d : dilluants) {
        std::string name = d.getName();
        double price = d.getPrice();
        std::string sprice = std::to_string(price);
        QString imageName = d.getImageName();
        std::string iName = imageName.toStdString();
        std::cout << "Nom : " << name << " , prix : " << sprice << " , path : " << iName << std::endl;
    }
}

void Recipe::initialiser() {
    listAlcools();
    listDilluants();
}
