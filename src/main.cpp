
#include "mainwindow.h"
#include "gpuscanner.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    // a.setStyle("Fusion");
    // qApp->setStyleSheet(
    //     "* {border-radius: 4px}"
    //     "QWidget#central { background-image: url(:/images/background) }"
    //     "Sidebar#sidebar {background-color: rgba(58, 60, 63, 0.56)}"
    //     "Sidebar QPushButton {background-color: rgb(169, 171, 173)}"
    //     "QLabel{color : rgb(241, 245, 249)}");
    // MainWindow w;
    // w.show();


    // return a.exec();

    gpuScanner();
}
