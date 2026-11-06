#include "gpusection.h"

GpuSection::GpuSection(QWidget *parent)
: QWidget{parent}{

   
    title = new QLabel();
    title->setText("Title");


    centralImage = new QLabel();
    QPixmap gpuImage(":/images/gpuImage");
    centralImage->setScaledContents(true);

    centralImage->setPixmap(gpuImage);
    centralImage->setMaximumSize(500, 400);
    
    QLabel* leftBoard = new QLabel("TEXTO DE PRUEBA");
    QLabel* rightBoard = new QLabel("TEXTO DE PRUEBA");

    mainLayout = new QVBoxLayout(this);
    QHBoxLayout* contentLayout = new QHBoxLayout();
    mainLayout->addWidget(title);  
    mainLayout->addLayout(contentLayout, 1);


    contentLayout->addWidget(leftBoard,1);
    contentLayout->addWidget(centralImage,1);
    contentLayout->addWidget(rightBoard,1);
    contentLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setAlignment(Qt::AlignCenter);
    
}