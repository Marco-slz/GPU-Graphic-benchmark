// Creates the available content pages and selects a page when requested.
#include "sections.h"

Sections::Sections(Backend &backend, QWidget *parent)
    : QStackedWidget{parent}, backend(backend)
{

    gpu = new GpuSection(backend);
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
