#pragma once
#include <QtWidgets>
#include<vector>
#include "gpu.h"


class GpuSelector : public QWidget{
    public:
        GpuSelector(QWidget *parent = nullptr);
        void updateValues( const std::vector <Gpu>& labels);

    private:
        QPushButton* addButton(const QString label);
        std::vector <QPushButton*> availableGpus;
        QHBoxLayout *layout;
        QWidget* innerArea;
        QHBoxLayout *innerAreaLayout;
};