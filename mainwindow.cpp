#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    r.initialiser();
    r.listTout();
    listRecipes();

    //Initialisations
    centralWidget = new QWidget(this);
    mainLayout = new QVBoxLayout();


    //Section du haut
    sepHaut = new QHBoxLayout();
    logo = new QImage();
    logoLabel = new QLabel();
    barreRecherche = new QLineEdit();
    enregistre = new QPushButton();

    //Section titre
    sepVide = new QHBoxLayout();
    texte = new QLabel();

    //Section selection
    sepSelection = new QGridLayout();
    rowSelection = 0;
    columnSelection = 0;
    scrollSelection = new QScrollArea();
    rechercheBouton = new QPushButton();


    //Section central
    sepCentral = new QGridLayout();
    row = 0;
    col = 0;
    scrollArea = new QScrollArea();


    //Section Bas
    sepBas = new QHBoxLayout();
    about = new QLabel();
    credits = new QLabel();
    contact = new QLabel();

    //Section Filtrage
    filtre = new QLineEdit();
    ajouter = new QPushButton();
    sepFiltre = new QHBoxLayout();

    //Sections générales
    barreHaut = new QWidget();
    barreTitre = new QWidget();
    barreFiltrage = new QWidget();
    selection = new QWidget();
    espaceCentral = new QWidget();
    barreBas = new QWidget();

    /*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    //Section du haut
    QString appDir = QCoreApplication::applicationDirPath();
    std::string spath = appDir.toStdString();
    QAction *loupeAction = new QAction(QIcon(appDir+"/singe.jpg"), "", barreRecherche);
    barreRecherche->addAction(loupeAction, QLineEdit::LeadingPosition);
    QObject::connect(loupeAction, &QAction::triggered, this, &MainWindow::onSearchButtonClicked);
    barreRecherche->setPlaceholderText(" | Je cherche un cocktail, un alcool, un diluant");
    barreRecherche->setFixedWidth(700);
    barreRecherche->setFixedHeight(40);
    barreRecherche->setStyleSheet("QWidget {background-color:white; border-radius:20px;}");

    QStringList list;
    std::vector<std::string> vecTout = r.getTout();
    for(std::string s : vecTout){
        list.append(QString::fromStdString(s));
    }
    QStringListModel *model = new QStringListModel(list);
    QCompleter *completer = new QCompleter(model);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    barreRecherche->setCompleter(completer);

    QString imagePath = appDir+"/images/logo.jpg";
    if (logo->load(imagePath)) {
        QImage scaledImage = logo->scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        int x = (scaledImage.width() - 100) / 2;
        int y = (scaledImage.height() - 100) / 2;
        QImage croppedImage = scaledImage.copy(x, y, 100, 100);
        logoLabel->setPixmap(QPixmap::fromImage(croppedImage));
    }
    /*
    enregistre->setText("Recettes enregistrées");
    enregistre->setStyleSheet("QWidget {background-color:white; border-radius : 20px;}");
    enregistre->setFixedHeight(40);
    enregistre->setFixedWidth(180);*/

    sepHaut->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    sepHaut->addWidget(logoLabel);
    sepHaut->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    sepHaut->addWidget(barreRecherche);
    sepHaut->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    sepHaut->addWidget(enregistre);
    sepHaut->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    barreHaut->setLayout(sepHaut);
    barreHaut->setMaximumHeight(100);
    barreHaut->setStyleSheet("QWidget {background-color : black;}");


    //Section titre
    texte->setText("Test");
    texte->setStyleSheet("QLabel { color : white;}");
    sepVide->addWidget(texte);
    sepVide->setAlignment(texte, Qt::AlignCenter);
    barreTitre->setLayout(sepVide);
    barreTitre->setMaximumHeight(40);
    barreTitre->setStyleSheet("QWidget{background-color : black;}");


    //Section filtrage
    QIcon croix(appDir+"/images/plus.jpg");
    filtre->setPlaceholderText("Ajouter un alcool, un diluant");
    filtre->setFixedWidth(500);
    filtre->setFixedHeight(40);
    barreFiltrage->setStyleSheet("QWidget { border-radius:20px;}");

    QStringList list2;
    for(std::string s : vecTout){
        list2.append(QString::fromStdString(s));
    }
    QStringListModel *model2 = new QStringListModel(list2);
    QCompleter *completer2 = new QCompleter(model2);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    filtre->setCompleter(completer2);

    ajouter->setFixedWidth(40);
    ajouter->setFixedHeight(40);
    ajouter->setIcon(croix);
    ajouter->setIconSize(QSize(40, 40));
    ajouter->setStyleSheet("QPushButton {border : none;}");
    sepFiltre->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    sepFiltre->addWidget(filtre);
    sepFiltre->addWidget(ajouter);
    sepFiltre->addWidget(rechercheBouton);
    sepFiltre->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    barreFiltrage->setMaximumHeight(100);
    rechercheBouton->setIconSize(QSize(40,40));

    barreFiltrage->setLayout(sepFiltre);

    QObject::connect(ajouter, &QPushButton::clicked, this, &MainWindow::onAjouterClicked);

    //Section sélection


    selection->setLayout(sepSelection);

    scrollSelection->setWidget(selection);
    scrollSelection->setWidgetResizable(true);
    scrollSelection->setMaximumHeight(100);
    for (int i = 0; i < 10; ++i) {
        sepSelection->setColumnStretch(i, 0);
    }
    sepSelection->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    connect(rechercheBouton, &QPushButton::clicked, this, &MainWindow::rechercheAvecFiltre);
    rechercheBouton->setIcon(croix);

    //Espace Central
    espaceCentral->setLayout(sepCentral);
    sepCentral->setAlignment(Qt::AlignTop);
    sepCentral->setContentsMargins(0, 0, 0, 0);
    sepCentral->setSpacing(10);
    scrollArea->setWidget(espaceCentral);
    scrollArea->setWidgetResizable(true);

    //Section Bas

    about->setText("App Web  | ");
    about->setStyleSheet("QLabel{color : white;}");
    credits->setText("©2024 - Thomas  | ");
    credits->setStyleSheet("QLabel{color : white;}");
    contact->setText("✉️ : ...@gmail.com | @....");
    contact->setStyleSheet("QLabel{color : white;}");
    sepBas->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    sepBas->addWidget(about);
    sepBas->addWidget(credits);
    sepBas->addWidget(contact);
    sepBas->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    barreBas->setLayout(sepBas);
    barreBas->setMaximumHeight(100);
    barreBas->setStyleSheet("QWidget{background-color : black;}");

    //Section Frame
    frameHaut = new QFrame();
    frameHaut->setFrameStyle(QFrame::HLine | QFrame::Plain);
    frameHaut->setStyleSheet("QFrame { border: 1px white; background-color: white; }");
    frameHaut->setLineWidth(1);

    frameTitre = new QFrame();
    frameTitre->setFrameStyle(QFrame::HLine | QFrame::Plain);
    frameTitre->setStyleSheet("QFrame { border: 1px white ; background-color: white; }");
    frameTitre->setLineWidth(1);

    /*------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Mise en page générale
    mainLayout->addWidget(barreHaut);
    mainLayout->addWidget(frameHaut);
    mainLayout->addWidget(barreTitre);
    mainLayout->addWidget(frameTitre);
    mainLayout->addWidget(barreFiltrage);
    mainLayout->addWidget(scrollSelection);
    mainLayout->addWidget(scrollArea);
    mainLayout->addWidget(barreBas);

    //
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    initialisation();
}



void MainWindow::clearWidget(QWidget *widget){
    QLayout *layout = widget->layout();
    if (layout) {
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr) {
            if (child->widget()) {
                delete child->widget();
            }
            delete child;
        }
    }
}

bool compareAlcoolByName(const Alcool& alcool, const std::string& name) {
    return alcool.getName() == name;
}

bool compareDilluantByName(const Dilluant& dilluant, const std::string& name) {
    return dilluant.getName() == name;
}

void MainWindow::onSearchButtonClicked() {
    QString mot = barreRecherche->text();
    std::string smot = mot.toStdString();
    if(smot==""){
        initialisation();
        return;}
    clearWidget(espaceCentral);
    filtre->clear();


    bool isAlcool = false;

    for (const auto& recipe : recipes) {
        std::vector<Alcool> alcools = recipe.getAlcools();
        if (std::find_if(alcools.begin(), alcools.end(), [&smot](const Alcool& alcool) {
                return compareAlcoolByName(alcool, smot);
            }) != alcools.end()) {
            isAlcool = true;
            break;
        }
    }

    if (isAlcool) {
        int row = 0;
        int col = 0;
        int maxWidth = 100;
        int maxHeight = 100;

        for (const auto& recipe : recipes) {
            std::vector<Alcool> alcools = recipe.getAlcools();
            for (const auto& alcool : alcools) {
                if (compareAlcoolByName(alcool, smot)) {
                    QWidget *temp = new QWidget();
                    QVBoxLayout *sepTemp = new QVBoxLayout();

                    QString imageName = recipe.getImageName();
                    QImage image(imageName);
                    image = image.scaled(maxWidth, maxHeight, Qt::IgnoreAspectRatio);

                    QPixmap pixmap = QPixmap::fromImage(image);
                    ClickableLabel *imageLabel = new ClickableLabel();
                    imageLabel->setPixmap(pixmap);
                    imageLabel->setFixedSize(maxWidth, maxHeight);
                    imageLabel->setScaledContents(true);
                    imageLabel->setRecipeName(recipe.getName());

                    connect(imageLabel, &ClickableLabel::clicked, this, &MainWindow::onImageClicked);

                    QString recipeName = QString::fromStdString(recipe.getName());
                    QLabel *nomLabel = new QLabel(recipeName);
                    nomLabel->setAlignment(Qt::AlignCenter);

                    sepTemp->addWidget(imageLabel);
                    sepTemp->addWidget(nomLabel);
                    sepTemp->setContentsMargins(5, 5, 5, 5);
                    sepTemp->setSpacing(5);

                    temp->setLayout(sepTemp);
                    temp->setFixedSize(maxWidth + 20, maxHeight + 40);
                    sepCentral->addWidget(temp, row, col);

                    col++;
                    if (col == 14) {
                        col = 0;
                        row++;
                    }
                }
            }
        }
    } else {
        int row = 0;
        int col = 0;
        int maxWidth = 100;
        int maxHeight = 100;

        for (const auto& recipe : recipes) {
            std::vector<Dilluant> dilluants = recipe.getDilluants();
            for (const auto& dilluant : dilluants) {
                if (compareDilluantByName(dilluant, smot)) {
                    QWidget *temp = new QWidget();
                    QVBoxLayout *sepTemp = new QVBoxLayout();

                    QString imageName = recipe.getImageName();
                    QImage image(imageName);
                    image = image.scaled(maxWidth, maxHeight, Qt::IgnoreAspectRatio);

                    QPixmap pixmap = QPixmap::fromImage(image);
                    ClickableLabel *imageLabel = new ClickableLabel();
                    imageLabel->setPixmap(pixmap);
                    imageLabel->setFixedSize(maxWidth, maxHeight);
                    imageLabel->setScaledContents(true);
                    imageLabel->setRecipeName(recipe.getName());

                    connect(imageLabel, &ClickableLabel::clicked, this, &MainWindow::onImageClicked);

                    QString recipeName = QString::fromStdString(recipe.getName());
                    QLabel *nomLabel = new QLabel(recipeName);
                    nomLabel->setAlignment(Qt::AlignCenter);

                    sepTemp->addWidget(imageLabel);
                    sepTemp->addWidget(nomLabel);
                    sepTemp->setContentsMargins(5, 5, 5, 5);
                    sepTemp->setSpacing(5);

                    temp->setLayout(sepTemp);
                    temp->setFixedSize(maxWidth + 20, maxHeight + 40);
                    sepCentral->addWidget(temp, row, col);

                    col++;
                    if (col == 14) {
                        col = 0;
                        row++;
                    }
                }
            }
        }
    }
}


void MainWindow::initialisation() {
    clearWidget(espaceCentral);
    clearFiltre();
    int row = 0;
    int col = 0;
    int maxWidth = 100;
    int maxHeight = 100;

    for (const auto& r : recipes) {
        QWidget *temp = new QWidget();
        QVBoxLayout *sepTemp = new QVBoxLayout();

        QString imageName = r.getImageName();
        QImage image(imageName);
        image = image.scaled(maxWidth, maxHeight, Qt::IgnoreAspectRatio);

        QPixmap pixmap = QPixmap::fromImage(image);
        ClickableLabel *imageLabel = new ClickableLabel();
        imageLabel->setPixmap(pixmap);
        imageLabel->setFixedSize(maxWidth, maxHeight);
        imageLabel->setScaledContents(true);
        imageLabel->setRecipeName(r.getName());

        connect(imageLabel, &ClickableLabel::clicked, this, &MainWindow::onImageClicked);

        std::string nom = r.getName();
        QString snom = QString::fromStdString(nom);
        QLabel *nomLabel = new QLabel(snom);
        nomLabel->setAlignment(Qt::AlignCenter);

        sepTemp->addWidget(imageLabel);
        sepTemp->addWidget(nomLabel);
        sepTemp->setContentsMargins(5, 5, 5, 5);
        sepTemp->setSpacing(5);

        temp->setLayout(sepTemp);
        temp->setFixedSize(maxWidth + 20, maxHeight + 40);
        sepCentral->addWidget(temp, row, col);

        col++;
        if (col == 14) {
            col = 0;
            row++;
        }
    }
}

void MainWindow::onImageClicked(const std::string& name) {
    for (const auto& r : recipes) {
        if (r.getName() == name) {
            QDialog *dialog = new QDialog(this);
            dialog->setWindowTitle("Recipe Details");
            QVBoxLayout *layout = new QVBoxLayout(dialog);

            QLabel *nameLabel = new QLabel(QString::fromStdString(r.getName()), dialog);
            layout->addWidget(nameLabel);

            QLabel *priceLabel = new QLabel("Price: " + QString::number(r.getPrix()) + "€", dialog);
            layout->addWidget(priceLabel);

            QLabel *instructionsLabel = new QLabel("Instructions: " + QString::fromStdString(r.getInstructions()), dialog);
            layout->addWidget(instructionsLabel);

            QLabel *difficultyLabel = new QLabel("Difficulty: " + QString::fromStdString(r.getDifficulty()), dialog);
            layout->addWidget(difficultyLabel);

            QLabel *imageLabel = new QLabel(dialog);
            QPixmap recipePixmap = QPixmap::fromImage(r.getImage());

            QPixmap scaledPixmap = recipePixmap.scaled(200, 200, Qt::KeepAspectRatio);

            imageLabel->setPixmap(scaledPixmap);
            imageLabel->setFixedSize(200, 200);
            layout->addWidget(imageLabel);

            QLabel *alcoholsLabel = new QLabel("Alcools:", dialog);
            layout->addWidget(alcoholsLabel);

            for (const auto& alcool : r.getAlcools()) {
                QHBoxLayout *alcoholLayout = new QHBoxLayout();

                QLabel *alcoholNameLabel = new QLabel(QString::fromStdString(alcool.getName()), dialog);
                alcoholLayout->addWidget(alcoholNameLabel);

                QLabel *alcoholQuantityLabel = new QLabel(QString("Quantity: %1 cl").arg(alcool.getQuantity()), dialog);
                alcoholLayout->addWidget(alcoholQuantityLabel);

                QLabel *alcoholImageLabel = new QLabel(dialog);
                QPixmap alcoholPixmap = QPixmap::fromImage(alcool.getImage());
                alcoholImageLabel->setPixmap(alcoholPixmap);
                alcoholLayout->addWidget(alcoholImageLabel);

                layout->addLayout(alcoholLayout);
            }

            QLabel *dilluantsLabel = new QLabel("Dilluants:", dialog);
            layout->addWidget(dilluantsLabel);

            for (const auto& dilluant : r.getDilluants()) {
                QHBoxLayout *dilluantLayout = new QHBoxLayout();

                QLabel *dilluantNameLabel = new QLabel(QString::fromStdString(dilluant.getName()), dialog);
                dilluantLayout->addWidget(dilluantNameLabel);

                QLabel *dilluantQuantityLabel = new QLabel(QString("Quantity: %1 cl").arg(dilluant.getQuantity()), dialog);

                dilluantLayout->addWidget(dilluantQuantityLabel);

                QLabel *dilluantImageLabel = new QLabel(dialog);
                QPixmap dilluantPixmap = QPixmap::fromImage(dilluant.getImage());
                dilluantImageLabel->setPixmap(dilluantPixmap);
                dilluantLayout->addWidget(dilluantImageLabel);

                layout->addLayout(dilluantLayout);
            }

            dialog->setLayout(layout);

            dialog->exec();
            break;
        }
    }

}



void MainWindow::reorganizeWidgets(QWidget* widgetToRemove) {
    // Trouver la position du widget à supprimer
    int rowToRemove = -1;
    int columnToRemove = -1;
    for (int i = 0; i < sepSelection->rowCount(); ++i) {
        for (int j = 0; j < sepSelection->columnCount(); ++j) {
            QLayoutItem* item = sepSelection->itemAtPosition(i, j);
            if (item && item->widget() == widgetToRemove) {
                rowToRemove = i;
                columnToRemove = j;
                sepSelection->removeWidget(widgetToRemove);
                break;
            }
        }
        if (rowToRemove != -1) {
            break;
        }
    }

    if (rowToRemove == -1 || columnToRemove == -1) {
        return; // Widget not found
    }

    // Collecter tous les widgets dans un vecteur
    std::vector<QWidget*> widgets;
    for (int i = 0; i < sepSelection->rowCount(); ++i) {
        for (int j = 0; j < sepSelection->columnCount(); ++j) {
            QLayoutItem* item = sepSelection->itemAtPosition(i, j);
            if (item) {
                QWidget* widget = item->widget();
                if (widget) {
                    widgets.push_back(widget);
                }
            }
        }
    }

    // Effacer tous les widgets du layout
    for (int i = 0; i < sepSelection->rowCount(); ++i) {
        for (int j = 0; j < sepSelection->columnCount(); ++j) {
            QLayoutItem* item = sepSelection->itemAtPosition(i, j);
            if (item) {
                sepSelection->removeItem(item);
                delete item;
            }
        }
    }

    // Réajouter les widgets dans le layout en les alignant à gauche
    int row = 0;
    int column = 0;
    for (QWidget* widget : widgets) {
        sepSelection->addWidget(widget, row, column);

        // Mettre à jour la position pour la prochaine insertion
        if (column < 9) {
            ++column;
        } else {
            column = 0;
            ++row;
        }
    }

    // Réinitialiser les positions de sélection
    rowSelection = row;
    columnSelection = column;
}


void MainWindow::onAjouterClicked() {
    QString mot = filtre->text();
    std::string smot = mot.toStdString();

    if (smot.empty()) {
        initialisation();
        return;
    }

    std::vector<Alcool> alcools = r.getAlcools();
    std::vector<Dilluant> dilluants = r.getDilluants();
    bool foundInAlcools = std::any_of(alcools.begin(), alcools.end(), [&smot](const Alcool& alcool) {
        return compareAlcoolByName(alcool, smot);
    });

    bool foundInDilluants = std::any_of(dilluants.begin(), dilluants.end(), [&smot](const Dilluant& dilluant) {
        return compareDilluantByName(dilluant, smot);
    });

    if (foundInAlcools || foundInDilluants) {
        if (ajoutedItems.contains(QString::fromStdString(smot))) {
            return;
        }

        filtre->clear();
        barreRecherche->clear();

        QWidget *itemWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(itemWidget);
        QLabel *nomLabel = new QLabel(QString::fromStdString(smot), this);
        QPushButton *deleteButton = new QPushButton("❌", this);
        deleteButton->setFixedSize(20, 20);
        layout->addWidget(nomLabel);
        layout->addWidget(deleteButton);

        QFontMetrics fontMetrics(nomLabel->font());
        int textWidth = fontMetrics.horizontalAdvance(nomLabel->text());
        int widgetWidth = textWidth + 50;
        int widgetHeight = 40;
        itemWidget->setFixedSize(widgetWidth, widgetHeight);
        ajoutedItems.insert(QString::fromStdString(smot)); // Ajouter au QSet
        connect(deleteButton, &QPushButton::clicked, [itemWidget, smot, this]() {
            // Supprimer le widget du layout
            sepSelection->removeWidget(itemWidget);
            itemWidget->deleteLater();

            // Supprimer le widget du QSet
            ajoutedItems.remove(QString::fromStdString(smot));

            // Réorganiser les widgets restants
            reorganizeWidgets(itemWidget);
        });

        int row = rowSelection;
        int column = columnSelection;

        sepSelection->addWidget(itemWidget, row, column);
        if (column < 9)
            columnSelection++;
        else {
            columnSelection = 0;
            rowSelection++;
        }
    }
}

void MainWindow::rechercheAvecFiltre() {
    // Collecter les sélections de l'utilisateur
    QSet<QString> selectedItems = ajoutedItems;
    // Filtrer les recettes en fonction des sélections
    std::vector<Recipe> filteredRecipes;
    std::vector<Alcool> alcools = r.getAlcools();
    std::vector<Dilluant> dilluants = r.getDilluants();
    for (const Recipe& recipe : recipes) {
        bool containsAll = true;
        std::vector<Alcool> alcools = recipe.getAlcools();
        std::vector<Dilluant> dilluants = recipe.getDilluants();
        for (const QString& item : selectedItems) {
            bool foundInAlcools = std::any_of(alcools.begin(), alcools.end(), [&item](const Alcool& alcool) {
                return compareAlcoolByName(alcool, item.toStdString());
            });
            bool foundInDilluants = std::any_of(dilluants.begin(), dilluants.end(), [&item](const Dilluant& dilluant) {
                return compareDilluantByName(dilluant, item.toStdString());
            });
            if (!foundInAlcools && !foundInDilluants) {
                containsAll = false;
                break;
            }
        }
        if (containsAll) {
            filteredRecipes.push_back(recipe);
        }
    }

    // Afficher les recettes filtrées
    clearWidget(espaceCentral);
    filtre->clear();

    int row = 0;
    int col = 0;
    int maxWidth = 100;
    int maxHeight = 100;

    for (const auto& recipe : filteredRecipes) {
        QWidget *temp = new QWidget();
        QVBoxLayout *sepTemp = new QVBoxLayout();

        QString imageName = recipe.getImageName();
        QImage image(imageName);
        image = image.scaled(maxWidth, maxHeight, Qt::IgnoreAspectRatio);

        QPixmap pixmap = QPixmap::fromImage(image);
        ClickableLabel *imageLabel = new ClickableLabel();
        imageLabel->setPixmap(pixmap);
        imageLabel->setFixedSize(maxWidth, maxHeight);
        imageLabel->setScaledContents(true);
        imageLabel->setRecipeName(recipe.getName());

        connect(imageLabel, &ClickableLabel::clicked, this, &MainWindow::onImageClicked);

        QString recipeName = QString::fromStdString(recipe.getName());
        QLabel *nomLabel = new QLabel(recipeName);
        nomLabel->setAlignment(Qt::AlignCenter);

        sepTemp->addWidget(imageLabel);
        sepTemp->addWidget(nomLabel);
        sepTemp->setContentsMargins(5, 5, 5, 5);
        sepTemp->setSpacing(5);

        temp->setLayout(sepTemp);
        temp->setFixedSize(maxWidth + 20, maxHeight + 40);
        sepCentral->addWidget(temp, row, col);

        col++;
        if (col == 14) {
            col = 0;
            row++;
        }
    }
    selectedItems.clear();
}

void MainWindow::clearFiltre(){
    ajoutedItems.clear();
    clearWidget(selection);
}


MainWindow::~MainWindow()
{
    delete ui;
}
