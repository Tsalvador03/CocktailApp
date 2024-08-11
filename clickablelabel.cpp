#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget *parent)
    : QLabel(parent) {}

void ClickableLabel::setRecipeName(const std::string& name) {
    recipeName = name;
}

/*
void ClickableLabel::mousePressEvent(QMouseEvent *event) {
    emit clicked(recipeName);
}
*/
