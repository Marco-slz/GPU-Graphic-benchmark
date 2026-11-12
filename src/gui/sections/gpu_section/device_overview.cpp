// Builds the GPU overview panel from a title, image, and labeled fields.
#include "device_overview.h"

DeviceOverview::DeviceOverview(Backend &backend, QWidget *parent)
    : QWidget(parent), backend(backend)
{
    // Enable stylesheet backgrounds for this custom widget.
    setAttribute(Qt::WA_StyledBackground, true);

    auto *mainLayout = new QVBoxLayout(this);

    // Prepare the panel title and illustrative GPU image.
    auto *titleLabel = new QLabel(m_title);
    titleLabel->setObjectName("titleLabel");
    auto *gpuImage = new ImageLabel();
    gpuImage->setImagePixmap(QPixmap(m_gpuImage));
    gpuImage->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    model = new QLabel("");
    vendor = new QLabel("");
    vram = new QLabel("");
    baseClock = new QLabel("");
    // Lay out placeholder values beside the core GPU specification labels.
    QFormLayout *formLayout = new QFormLayout(this);
    formLayout->setAlignment(Qt::AlignTop);
    formLayout->addRow(tr("&Vendor:"), vendor);
    formLayout->addRow(tr("&Model:"), model);
    formLayout->addRow(tr("&VRAM:"), vram);
    formLayout->addRow(tr("&Base Clock:"), baseClock);

    mainLayout->addWidget(titleLabel, 1, Qt::AlignTop);
    mainLayout->addWidget(gpuImage, 20, Qt::AlignTop);
    mainLayout->addLayout(formLayout, 100);
    mainLayout->setAlignment(formLayout, Qt::AlignTop);
    this->setStyleSheet("#titleLabel { font-size: 20px}");
}

void DeviceOverview::updateValues(int gpuPosition){
    std::vector<Gpu> AvailableGpus = backend.getAvailableGpus();
    vendor->setText(QString::fromStdString(AvailableGpus[gpuPosition].get_vendor()));
    model->setText(QString::fromStdString(AvailableGpus[gpuPosition].get_model()));
}
