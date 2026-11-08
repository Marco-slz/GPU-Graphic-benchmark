#pragma once
#include<QtWidgets>
#include <QPixmap>
#include "sectionheader.h"
#include "deviceoverview.h"
class GpuSection : public QWidget{
    public:
        GpuSection(QWidget *parent = nullptr);
    private:
        Header *header;
        DeviceOverview * gpuOverview;
        QLabel *centralImage;
        QVBoxLayout *mainLayout;

};