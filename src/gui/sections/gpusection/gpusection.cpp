#include "gpusection.h"

GpuSection::GpuSection(QWidget *parent)
: QWidget{parent}{

   
    header = new Header();
    header->setObjectName("header");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setFixedHeight(150);
    
    auto content = new QWidget();
    content->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(header, 1);  
    mainLayout->addWidget(content, 10);
    this->setStyleSheet(
    "Header#header{"
    "background-color: rgba(58, 60, 63, 0.56);"
    "border-width: 1px;"
    "border-style: solid;"
    "border-color: rgb(10, 81, 186);}");

}