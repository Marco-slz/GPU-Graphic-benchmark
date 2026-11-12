// Declares the panel that presents a GPU image and basic device fields.
#pragma once

#include "backend.h"
#include "image_label.h"
#include <QPixmap>
#include <QtWidgets>

// Overview widget for a GPU's identifying and specification information.
class DeviceOverview : public QWidget
{
    Q_OBJECT
  public:
    DeviceOverview(Backend &backend, QWidget *parent = nullptr);
    void updateValues(int gpuPosition);
  private:
    Backend &backend;
    const QString m_title = "GPU Overview";
    const QString m_gpuImage = ":/images/gpuImage";
    QLabel* model;
    QLabel* vendor;
    QLabel* vram;
    QLabel* baseClock;
};
