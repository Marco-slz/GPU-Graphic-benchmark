#include "sections.h"

Sections::Sections(QWidget* parent)
: QWidget{parent}
{

    sections = new QStackedWidget(this);

    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(sections);

    gpu = new GpuSection();
    QLabel* blank = new QLabel("this asodfasdjhfasdhkasdfkjasdhkuhadskhfasalsdhfaks");
    sections->addWidget(gpu);
    sections->addWidget(blank);
}

void Sections::changeSection(int section){
    sections->setCurrentIndex(section);
}
