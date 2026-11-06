#include "sidebar.h"

Sidebar::Sidebar(QWidget *parent) 
: QWidget(parent){  
    setAttribute(Qt::WA_StyledBackground, true);
    

    setFixedWidth(64);
    //create buttons
    auto * button1 = addButtons(":/icons/statistics", "Statistics");
    auto * button2 = addButtons(":/icons/settings", "Settings");
    auto * button3 = addButtons(":/icons/gpu", "GPUs");
    //handle layout
    auto *layout = new QVBoxLayout(this);
    layout->setObjectName("sidebarButtons");
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    
    //handle clicked
    connect(button1, &QPushButton::clicked, this, [this](){
        emit sectionRequested(0);
    });
    connect(button2, &QPushButton::clicked, this, [this](){
        emit sectionRequested(1);
    });

}

QPushButton* Sidebar::addButtons(const QString address, const QString label){
    auto *button = new QPushButton(QIcon(address), "", this);
    button->setToolTip(label);
    return button;
}