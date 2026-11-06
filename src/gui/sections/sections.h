#pragma once
#include<QtWidgets>
#include "gpusection.h"

class Sections : public QWidget{
    Q_OBJECT
    public:
        Sections(QWidget * parent = nullptr);
        void changeSection(int section);
    private:
        QStackedWidget* sections;
        GpuSection* gpu;
};