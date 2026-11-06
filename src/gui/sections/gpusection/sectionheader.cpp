#include "sectionheader.h"


Header::Header(QString gpuName, QString vendorLogo)
: m_gpuName{gpuName}, m_vendorLogo{vendorLogo}{

    auto* mainLayout = new QHBoxLayout(this);
    
    auto* rightLayout = new QVBoxLayout();
    
    auto* leftLayout = new QVBoxLayout();
    

    auto *titleLabel = new QLabel(m_title);
    auto *descriptionLabel = new QLabel(m_description);
    auto *gpuNameLabel = new QLabel(m_gpuName);

    auto *sectionIcon = new QLabel(this);
    QPixmap icon(m_sectionIcon);
    sectionIcon->setPixmap(icon);

    auto *vendorLogoLabel = new QLabel();
    QPixmap logo(m_vendorLogo);
    vendorLogoLabel->setPixmap(logo);

    mainLayout->addWidget(sectionIcon);
    mainLayout->addLayout(rightLayout);

    rightLayout->addWidget(titleLabel);
    rightLayout->addWidget(descriptionLabel);
    mainLayout->addLayout(leftLayout);

    leftLayout->addWidget(vendorLogoLabel);
    leftLayout->addWidget(gpuNameLabel);
}