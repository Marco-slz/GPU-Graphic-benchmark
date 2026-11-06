#include "sections.h"

Sections::Sections(QWidget* parent)
: QStackedWidget{parent}
{



    gpu = new GpuSection();
    QLabel* blank = new QLabel("this asodfasdjhfasdhkasdfkjasdhkuhadskhfasalsdhfaks");
    this->addWidget(gpu);
    this->addWidget(blank);
}

void Sections::changeSection(int section){
    this->setCurrentIndex(section);
}
