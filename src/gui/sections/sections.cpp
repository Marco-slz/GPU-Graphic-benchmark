// Creates the available content pages and selects a page when requested.
#include "sections.h"

Sections::Sections(QWidget *parent) : QStackedWidget{parent}
{

    gpu = new GpuSection();
    // Register the GPU page and a temporary placeholder page in the stack.
    QLabel *blank =
        new QLabel("this asodfasdjhfasdhkasdfkjasdhkuhadskhfasalsdhfaks");
    this->addWidget(gpu);
    this->addWidget(blank);
}

void Sections::changeSection(int section)
{
    // Show the page at the requested stack index.
    this->setCurrentIndex(section);
}
