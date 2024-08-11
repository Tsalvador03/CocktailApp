#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <string>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = nullptr);
    void setRecipeName(const std::string& name);

signals:
    void clicked(const std::string& recipeName);

protected:
    //void mousePressEvent(QMouseEvent *event) override;

private:
    std::string recipeName;
};

#endif // CLICKABLELABEL_H
