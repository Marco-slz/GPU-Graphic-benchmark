#pragma once
#include <QtWidgets>
#include<vector>
#include "gpu.h"
#include "backend.h"


class GpuSelector : public QWidget{
    Q_OBJECT
    public:
        GpuSelector(Backend &backend, QWidget *parent = nullptr);
        void updateValues( const std::vector <Gpu>& labels);
    signals:
        void gpuRequested(int index);
    private:
        Backend &backend;
        QPushButton* addButton(const QString label);
        std::vector <QPushButton*> availableGpus;
        QHBoxLayout *layout;
        QWidget* innerArea;
        QHBoxLayout *innerAreaLayout;
};
