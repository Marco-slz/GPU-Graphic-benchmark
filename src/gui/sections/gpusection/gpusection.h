#pragma once
#include<QtWidgets>
#include <QPixmap>
class GpuSection : public QWidget{
    public:
        GpuSection(QWidget *parent = nullptr); //TODO: Define constructor
    private:
        QLabel *title;
        QLabel *centralImage;
        QVBoxLayout *mainLayout;

};