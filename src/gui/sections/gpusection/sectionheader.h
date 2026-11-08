// Declares the heading widget for GPU details, including vendor branding.
#pragma once

#include "imagelabel.h"
#include <QPixmap>
#include <QtWidgets>
// Presents the section title, description, GPU name, and vendor logo.
class Header : public QWidget
{
    Q_OBJECT
  public:
    Header(QString gpuName = "Graphics card 3000",
           QString vendorLogo = ":/images/nvidia");

  private:
    const QString m_title = "GPU Details";
    const QString m_sectionIcon = ":/icons/cpu";
    const QString m_description = "Properties, performance, and test results.";
    QString m_gpuName;
    QString m_vendorLogo;
};
