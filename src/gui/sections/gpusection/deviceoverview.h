// Declares the panel that presents a GPU image and basic device fields.
#pragma once

#include "imagelabel.h"
#include <QPixmap>
#include <QtWidgets>

// Overview widget for a GPU's identifying and specification information.
class DeviceOverview : public QWidget
{
    Q_OBJECT
  public:
    DeviceOverview();

  private:
    const QString m_title = "GPU Overview";
    const QString m_gpuImage = ":/images/gpuImage";
};
