#pragma once
#include<QtWidgets>
#include <QPixmap>
#include "sectionheader.h"
class GpuSection : public QWidget{
    public:
        GpuSection(QWidget *parent = nullptr);
    private:
        Header *header;
        QLabel *centralImage;
        QVBoxLayout *mainLayout;

};