#ifndef ALCOOL_H
#define ALCOOL_H

#include <string>
#include <QString>
#include <QImage>

class Alcool
{
    private:
        std::string name;
        double price;
        double quantity;
        QString imageName;
        QImage image;
    public:
        Alcool();
        Alcool(std::string name, double price,double quantity, QString imageName, QImage image);
        Alcool(std::string name,double price, double quantity);
        ~Alcool();
        inline std::string getName() const {return name;}
        inline double getPrice() const {return price;}
        inline double getQuantity() const {return quantity;}
        inline QString getImageName() const {return imageName;}
        inline QImage getImage() const {return image;}
        inline void setName(std::string _name) {name = _name;}
        inline void setPrice(double _price) {price = _price;}
        inline void setQuantity(double _quantity) {quantity = _quantity;}
        inline void setImageName(QString _imageName) {imageName = _imageName;}
        inline void setImage(QImage _image) {image = _image;}
};

#endif // ALCOOL_H
