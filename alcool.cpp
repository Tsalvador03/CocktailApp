#include "alcool.h"

Alcool::Alcool()
    : name(""), price(0.0), imageName(""), image() {}

Alcool::Alcool(std::string _name, double _price,double _quantity, QString _imageName, QImage _image)
    :name(_name),price (_price),quantity(_quantity), imageName(_imageName), image(_image){}

Alcool::Alcool(std::string _name,double _price, double _quantity)
    :name(_name),price(_price),quantity(_quantity){}
Alcool::~Alcool() {}
