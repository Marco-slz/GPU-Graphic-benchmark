// Declares the GPU section that combines its heading and device overview.
#pragma once
#include "deviceoverview.h"
#include "sectionheader.h"
#include <QPixmap>
#include <QtWidgets>
// Main content widget for the selected GPU section.
class GpuSection : public QWidget
{
  public:
    GpuSection(QWidget *parent = nullptr);

  private:
    Header *header;
    DeviceOverview *gpuOverview;
    QLabel *centralImage;
    QVBoxLayout *mainLayout;
};
