#include <mainwindow.h>


double MainWindow::calculePrix(std::vector<Alcool>_alcools,std::vector<Dilluant>_dilluants){
    double price = 0;
    std::vector<Alcool> alcools = r.getAlcools();
    std::vector<Dilluant> dilluants = r.getDilluants();
    for(Alcool a : _alcools){
        for(Alcool _a : alcools){
            if(a.getName() == _a.getName())
                price+=_a.getPrice();
        }
    }
    for(Dilluant d : _dilluants){
        for(Dilluant _d : dilluants){
            if(d.getName() == _d.getName())
                price+=_d.getPrice();
        }
    }
    return price;
}

void MainWindow::listRecipes(){
    std::vector<Alcool> a;
    std::vector<Dilluant> d;
    std::string name;
    double price;
    std::string difficulty;
    std::string instructions;
    std::string imageName;
    QString qimageName;
    QImage image;

    QString appPath = QCoreApplication::applicationDirPath();
    std::string spath = appPath.toStdString();
    name = "Vodka Red Bull";
    a = {Alcool("Vodka",15,5)};
    d = {Dilluant("Red Bull",1.1,15)};
    price = calculePrix(a,d);
    difficulty = "Simple";
    instructions = "Mélanger la vodka et le Red Bull dans un verre avec des glaçons.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));


    name = "Cuba Libre";
    a = {Alcool("Rhum",20,5)};
    d = {Dilluant("Coca",1.5,15),Dilluant("Citron",0.5,0.5)};
    price = calculePrix(a,d);
    difficulty = "Simple";
    instructions = "Mélanger le rhum, le coca et le jus de citron dans un verre avec des glaçons.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Mojito";
    a = {Alcool("Rhum",20,5)};
    d = {Dilluant("Menthe",0.5,0.5), Dilluant("Citron",0.5,0.5), Dilluant("Eau gazeuse",10,10)};
    price = calculePrix(a,d);
    difficulty = "Moyen";
    instructions = "Écraser les feuilles de menthe avec du sucre, ajouter le rhum, le jus de citron et l'eau gazeuse. Mélanger et servir avec des glaçons.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Margarita";
    a = {Alcool("Tequila",25,5),Alcool("Triple sec",15,5)};
    d = {Dilluant("Citron vert",0.5,0.5)};
    price = calculePrix(a,d);
    difficulty = "Moyen";
    instructions = "Mélanger la tequila, le triple sec et le jus de citron vert dans un shaker avec des glaçons. Secouer et servir.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Cosmopolitan";
    a = {Alcool("Vodka",15,5),Alcool("Triple sec",15,5)};
    d = {Dilluant("Jus de canneberge",10,10), Dilluant("Citron vert",0.5,0.5)};
    price = calculePrix(a,d);
    difficulty = "Moyen";
    instructions = "Mélanger la vodka, le triple sec, le jus de canneberge et le jus de citron vert dans un shaker avec des glaçons. Secouer et servir.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Piña Colada";
    a = {Alcool("Rhum",20,5)};
    d = {Dilluant("Jus d'ananas",10,10), Dilluant("Crème de coco",15,5)};
    price = calculePrix(a,d);
    difficulty = "Moyen";
    instructions = "Mélanger le rhum, le jus d'ananas et la crème de coco dans un blender avec des glaçons. Mixer et servir.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Sex on the Beach";
    a = {Alcool("Vodka",15,5)};
    d = {Dilluant("Jus d'orange",10,10), Dilluant("Jus de canneberge",10,10), Dilluant("Jus d'ananas",10,10), Dilluant("Schweppes",10,10)};
    price = calculePrix(a,d);
    difficulty = "Moyen";
    instructions = "Mélanger la vodka, le jus d'orange, le jus de canneberge, le jus d'ananas et le Schweppes dans un verre avec des glaçons.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Daiquiri";
    a = {Alcool("Rhum",20,5)};
    d = {Dilluant("Citron vert",0.5,0.5), Dilluant("Sucre",0.5,0.5)};
    price = calculePrix(a,d);
    difficulty = "Simple";
    instructions = "Mélanger le rhum, le jus de citron vert et le sucre dans un shaker avec des glaçons. Secouer et servir.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Tequila Sunrise";
    a = {Alcool("Tequila",25,5)};
    d = {Dilluant("Jus d'orange",10,10), Dilluant("Grenadine",0.5,0.5)};
    price = calculePrix(a,d);
    difficulty = "Simple";
    instructions = "Mélanger la tequila et le jus d'orange dans un verre avec des glaçons. Ajouter la grenadine et mélanger légèrement.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Long Island Iced Tea";
    a = {Alcool("Vodka",15,5), Alcool("Rhum",20,5), Alcool("Tequila",25,5), Alcool("Gin",20,5)};
    d = {Dilluant("Triple sec",15,5), Dilluant("Jus de citron",0.5,0.5), Dilluant("Coca",1.5,15)};
    price = calculePrix(a,d);
    difficulty = "Difficile";
    instructions = "Mélanger la vodka, le rhum, la tequila, le gin, le triple sec et le jus de citron dans un shaker avec des glaçons. Secouer et verser dans un verre avec du coca.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Bloody Mary";
    a = {Alcool("Vodka",15,5)};
    d = {Dilluant("Jus de tomate",10,10), Dilluant("Jus de citron",0.5,0.5), Dilluant("Sauce Worcestershire",0.5,0.5), Dilluant("Tabasco",0.1,0.1)};
    price = calculePrix(a,d);
    difficulty = "Moyen";
    instructions = "Mélanger la vodka, le jus de tomate, le jus de citron, la sauce Worcestershire et le Tabasco dans un shaker avec des glaçons. Secouer et servir.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Martini";
    a = {Alcool("Gin",20,5)};
    d = {Dilluant("Vermouth",15,5)};
    price = calculePrix(a,d);
    difficulty = "Simple";
    instructions = "Mélanger le gin et le vermouth dans un shaker avec des glaçons. Secouer et servir.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Manhattan";
    a = {Alcool("Whisky",25,5)};
    d = {Dilluant("Vermouth",15,5), Dilluant("Angostura",0.1,0.1)};
    price = calculePrix(a,d);
    difficulty = "Moyen";
    instructions = "Mélanger le whisky, le vermouth et l'angostura dans un shaker avec des glaçons. Secouer et servir.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Old Fashioned";
    a = {Alcool("Whisky",25,5)};
    d = {Dilluant("Sucre",0.5,0.5), Dilluant("Angostura",0.1,0.1), Dilluant("Eau gazeuse",10,10)};
    price = calculePrix(a,d);
    difficulty = "Moyen";
    instructions = "Écraser le sucre avec l'angostura, ajouter le whisky et l'eau gazeuse. Mélanger et servir.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Negroni";
    a = {Alcool("Gin",20,5)};
    d = {Dilluant("Vermouth",15,5), Dilluant("Campari",15,5)};
    price = calculePrix(a,d);
    difficulty = "Simple";
    instructions = "Mélanger le gin, le vermouth et le campari dans un shaker avec des glaçons. Secouer et servir.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Aperol Spritz";
    a = {Alcool("Aperol",15,5)};
    d = {Dilluant("Prosecco",15,5), Dilluant("Eau gazeuse",10,10)};
    price = calculePrix(a,d);
    difficulty = "Simple";
    instructions = "Mélanger l'aperol, le prosecco et l'eau gazeuse dans un verre avec des glaçons.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "White Russian";
    a = {Alcool("Vodka",15,5)};
    d = {Dilluant("Kahlua",15,5), Dilluant("Crème",10,10)};
    price = calculePrix(a,d);
    difficulty = "Simple";
    instructions = "Mélanger la vodka, le kahlua et la crème dans un verre avec des glaçons.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Mimosa";
    a = {Alcool("Champagne",20,5)};
    d = {Dilluant("Jus d'orange",10,10)};
    price = calculePrix(a,d);
    difficulty = "Simple";
    instructions = "Mélanger le champagne et le jus d'orange dans un verre.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));

    name = "Irish Coffee";
    a = {Alcool("Whisky",25,5)};
    d = {Dilluant("Café",10,10), Dilluant("Crème",10,10)};
    price = calculePrix(a,d);
    difficulty = "Moyen";
    instructions = "Mélanger le whisky et le café dans un verre. Ajouter la crème sur le dessus.";
    imageName = spath+"/images/"+name+".jpg";
    qimageName = QString::fromStdString(imageName);
    image= QImage(qimageName);
    recipes.push_back(Recipe(a,d,name,price,difficulty,instructions,qimageName,image));
}
