#include "proiectGUI.h"
#include "RepoTests.h"
#include "Ctrl1.h"
#include <QtWidgets/QApplication>
#include "mainWindow.h"

int runGui(int argc, char* argv[]){
    QApplication a(argc, argv);
    Repo* r = new Repo();
    Ctrl* c = new Ctrl(r);
    c->readFromFile();
    mainWindow w(*c);
    w.show();
    return a.exec();
    }

int main(int argc, char *argv[])
{
    RepoTests::runAllTests();
    return runGui(argc, argv);

   
   
}

