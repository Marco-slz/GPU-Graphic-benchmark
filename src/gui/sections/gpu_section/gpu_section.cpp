// Builds and styles the GPU section's header and overview panel.
#include "gpu_section.h"

GpuSection::GpuSection(Backend &backend, QWidget *parent)
    : QWidget{parent}, backend(backend)
{

    // Create child panels and assign names used by the section stylesheet.
    header = new Header();
    header->setObjectName("header");
    header->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    header->setFixedHeight(150);

    gpuOverview = new DeviceOverview(backend, this);
    gpuOverview->setObjectName("gpuOverview");
    gpuOverview->setFixedWidth(500);
    
    gpuSelector = new GpuSelector(backend, this);

    // Stack the header above the overview and define their visual boundaries.
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(gpuSelector);
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
    

    connect(gpuSelector, &GpuSelector::gpuRequested, gpuOverview, &DeviceOverview::updateValues);
}
