#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto *central = new QWidget(this);
    central->setObjectName("central");
    auto *layout = new QHBoxLayout(central);

    sidebar = new Sidebar(central);
    sidebar->setObjectName("sidebar");
    sections = new Sections(central);

    layout->addWidget(sidebar, 0);
    layout->addWidget(sections, 1);
    setCentralWidget(central);

    connect(sidebar, &Sidebar::sectionRequested, sections, &Sections::changeSection);

}

