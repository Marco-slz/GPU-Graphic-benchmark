#pragma once
#include<QtWidgets>
#include "gpusection.h"

class Sections : public QStackedWidget{
    Q_OBJECT
    public:
        Sections(QWidget * parent = nullptr);
        void changeSection(int section);
    private:
        GpuSection* gpu;
};