// Composes the central layout and connects navigation signals to section
// changes.
#include "main_window.h"

MainWindow::MainWindow(Backend &backend, QWidget *parent)
    : QMainWindow(parent), backend(backend)
{
    // Create the central area and place navigation beside the stacked content.
    auto *central = new QWidget(this);
    central->setObjectName("central");
    auto *layout = new QHBoxLayout(central);

    sidebar = new Sidebar(central);
    sidebar->setObjectName("sidebar");
    sections = new Sections(backend, central);

    layout->addWidget(sidebar, 0);
    layout->addWidget(sections, 1);
    setCentralWidget(central);

    // Forward sidebar page requests to the stacked section container.
    connect(sidebar, &Sidebar::sectionRequested, sections, &Sections::changeSection);
    connect(sidebar, &Sidebar::exitRequested, this, &QWidget::close);
}
