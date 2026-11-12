#include "gpu_selector.h"

GpuSelector::GpuSelector(QWidget *parent)
:QWidget(parent) {
    innerArea = new QWidget(this);
    innerAreaLayout = new QHBoxLayout(innerArea);
    auto *scanButton = addButton("Scan");



    auto *scrollArea = new QScrollArea();
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(innerArea);

    layout = new QHBoxLayout(this);
    layout->addWidget(scanButton);
    layout->addWidget(scrollArea);

}
void GpuSelector::updateValues(const std::vector <Gpu>& labels){
    availableGpus.clear();
    for(size_t i = 0; i < labels.size(); i++){
        availableGpus.push_back(addButton(QString::fromStdString(labels[i].get_model())));
    }
    
}

QPushButton *GpuSelector::addButton(const QString label)
{
    // Create an icon-only button and use its tooltip as its accessible label.
    auto *button = new QPushButton(label, this);
    button->setStyleSheet("background-color: #6dbdd5");
    innerAreaLayout->addWidget(button);
    return button;
}
