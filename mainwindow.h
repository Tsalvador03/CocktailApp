#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "recipe.h"
#include <clickablelabel.h>

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFrame>
#include <QIcon>
#include <QCompleter>
#include <QStringListModel>
#include <QMessageBox>
#include <algorithm>
#include <QGridLayout>
#include <QScrollArea>
#include <QFontMetrics>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Recipe r;
    std::vector<Recipe> recipes;


    QWidget *centralWidget;
    QVBoxLayout *mainLayout;

    //Section du haut
    QHBoxLayout *sepHaut;
    QImage *logo;
    QLabel *logoLabel;
    QLineEdit *barreRecherche;
    QPushButton *enregistre;

    //Section titre
    QHBoxLayout *sepVide;
    QLabel *texte;

    //Section Filtrage
    QHBoxLayout *sepFiltre;
    QLineEdit *filtre;
    QPushButton *ajouter;
    QGridLayout *sepSelection;
    QSet<QString> ajoutedItems;
    QScrollArea *scrollSelection;
    int rowSelection; int columnSelection;
    std::vector<QWidget*> widgetVector;
    QPushButton *rechercheBouton;

    //Espace central
    QGridLayout *sepCentral;
    int row; int col;
    QScrollArea *scrollArea;

    //Section Bas
    QHBoxLayout *sepBas;
    QLabel *about;
    QLabel *credits;
    QLabel *contact;

    //Frame
    QFrame* frameHaut;
    QFrame* frameTitre;


    //Sections générales
    QWidget *barreHaut;
    QWidget *barreTitre;
    QWidget *barreFiltrage;
    QWidget *selection;
    QWidget *espaceCentral;
    QWidget *barreBas;

private slots:
    double calculePrix(std::vector<Alcool>,std::vector<Dilluant>);
    void listRecipes();
    void onSearchButtonClicked();
    void clearWidget(QWidget *widget);
    void initialisation();
    void onImageClicked(const std::string& recipeName);
    void onAjouterClicked();
    void reorganizeWidgets(QWidget* widgetToRemove);
    void rechercheAvecFiltre();
    void clearFiltre();
};

#endif // MAINWINDOW_H
