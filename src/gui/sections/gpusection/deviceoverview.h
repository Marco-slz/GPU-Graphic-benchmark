#pragma once

#include<QtWidgets>
#include <QPixmap>
#include "imagelabel.h"

class DeviceOverview : public QWidget{
    Q_OBJECT
    public:
        DeviceOverview();
    private:
        const QString m_title = "GPU Overview";
        const QString m_gpuImage = ":/images/gpuImage";
        
};