// Declares the GPU section that combines its heading and device overview.
#pragma once
#include "device_overview.h"
#include "gpu_selector.h"
#include "section_header.h"
#include "backend.h"
#include <QPixmap>
#include <QtWidgets>

// Main content widget for the selected GPU section.
class GpuSection : public QWidget
{
  public:
    GpuSection(Backend &backend, QWidget *parent = nullptr);

  private:
    Backend &backend;
    Header *header;
    DeviceOverview *gpuOverview;
    QLabel *centralImage;
    QVBoxLayout *mainLayout;
    GpuSelector *gpuSelector;
};
