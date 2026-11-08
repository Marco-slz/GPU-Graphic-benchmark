// Builds the GPU details heading from labels, icons, and nested layouts.
#include "section_header.h"

Header::Header(QString gpuName, QString vendorLogo)
    : m_gpuName{gpuName}, m_vendorLogo{vendorLogo}
{
    // Permit the widget's background to be styled through Qt stylesheets.
    setAttribute(Qt::WA_StyledBackground, true);

    auto *mainLayout = new QHBoxLayout(this);

    auto *rightLayout = new QVBoxLayout();
    auto *leftLayout = new QVBoxLayout();

    // Create labels and image widgets for the heading's content.
    auto *titleLabel = new QLabel(m_title);
    titleLabel->setObjectName("titleLabel");
    auto *descriptionLabel = new QLabel(m_description);
    descriptionLabel->setObjectName("descriptionLabel");
    auto *gpuNameLabel = new QLabel(m_gpuName);
    gpuNameLabel->setObjectName("gpuNameLabel");
    auto *sectionIcon = new ImageLabel(this);
    sectionIcon->setImagePixmap(QPixmap(m_sectionIcon));
    sectionIcon->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    auto *vendorLogoLabel = new ImageLabel();
    vendorLogoLabel->setImagePixmap(QPixmap(m_vendorLogo));

    // Place the section icon beside left-aligned text and right-aligned
    // branding.
    mainLayout->addWidget(sectionIcon, 1);
    mainLayout->addLayout(leftLayout, 10);
    mainLayout->setAlignment(leftLayout, Qt::AlignLeft);
    mainLayout->addLayout(rightLayout, 1);
    mainLayout->setAlignment(rightLayout, Qt::AlignRight);

    leftLayout->addWidget(titleLabel, 1, Qt::AlignLeft | Qt::AlignTop);
    leftLayout->addWidget(descriptionLabel, 2, Qt::AlignLeft | Qt::AlignTop);

    rightLayout->addWidget(vendorLogoLabel, 1, Qt::AlignRight | Qt::AlignTop);
    rightLayout->addWidget(gpuNameLabel, 3, Qt::AlignRight | Qt::AlignTop);

    this->setStyleSheet("#titleLabel { font-size: 40px}"
                        "#gpuNameLabel {font-size: 20px}"
                        "#descriptionLabel {font-size: 15px}");
}
