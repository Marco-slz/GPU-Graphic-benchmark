// Builds and styles the GPU section's header and overview panel.
#include "gpusection.h"

GpuSection::GpuSection(QWidget *parent) : QWidget{parent}
{

    // Create child panels and assign names used by the section stylesheet.
    header = new Header();
    header->setObjectName("header");
    gpuOverview = new DeviceOverview();
    gpuOverview->setObjectName("gpuOverview");
    gpuOverview->setFixedWidth(500);
    header->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    header->setFixedHeight(150);

    // Stack the header above the overview and define their visual boundaries.
    mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(header);
    mainLayout->addWidget(gpuOverview);
    this->setStyleSheet("Header#header{"
                        //"background-color: rgba(39, 118, 236, 0.56);"
                        "border-width: 1px;"
                        "border-style: solid;"
                        "border-color: rgb(10, 81, 186);}"
                        "DeviceOverview#gpuOverview{"
                        //"background-color: rgba(39, 118, 236, 0.56);"
                        "border-width: 1px;"
                        "border-style: solid;"
                        "border-color: rgb(10, 81, 186);}");
}
