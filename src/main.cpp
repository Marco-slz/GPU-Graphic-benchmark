
// Application entry point: configure Qt, construct the main window, and run its
// event loop.
#include "gpu_scanner.h"
#include "main_window.h"
#include "database_management.h"
#include <QtWidgets>
#include<iostream>

int main(int argc, char *argv[])
{
    
    // Create the GUI application and apply the shared visual theme.
    QApplication a(argc, argv);
    a.setStyle("Fusion");
    qApp->setStyleSheet(
        "* {border-radius: 4px}"
        "QWidget#central { background-image: url(:/images/background) }"
        "Sidebar#sidebar {background-color: rgba(58, 60, 63, 0.56)}"
        "Sidebar QPushButton {background-color: rgb(169, 171, 173)}"
        "QLabel{color : rgb(241, 245, 249)}"
        "*{"
        "background-color: rgba(58, 60, 63, 0.56);"
        "border-width: 1px;"
        "border-style: solid;"
        "border-color: rgb(10, 81, 186);}"
    );
    // Display the application window and hand control to Qt's event loop.
    MainWindow w;
    w.showFullScreen();
    w.show();

    return a.exec();
}



