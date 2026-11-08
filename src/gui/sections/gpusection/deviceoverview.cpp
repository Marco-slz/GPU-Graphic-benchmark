// Builds the GPU overview panel from a title, image, and labeled fields.
#include "deviceoverview.h"

DeviceOverview::DeviceOverview()
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
    // Lay out placeholder values beside the core GPU specification labels.
    QFormLayout *formLayout = new QFormLayout(this);
    formLayout->setAlignment(Qt::AlignTop);
    formLayout->addRow(tr("&Make:"), new QLabel(""));
    formLayout->addRow(tr("&Model:"), new QLabel(""));
    formLayout->addRow(tr("&VRAM:"), new QLabel(""));
    formLayout->addRow(tr("&Base Clock:"), new QLabel(""));

    mainLayout->addWidget(titleLabel, 1, Qt::AlignTop);
    mainLayout->addWidget(gpuImage, 20, Qt::AlignTop);
    mainLayout->addLayout(formLayout, 100);
    mainLayout->setAlignment(formLayout, Qt::AlignTop);
    this->setStyleSheet("#titleLabel { font-size: 20px}");
}
