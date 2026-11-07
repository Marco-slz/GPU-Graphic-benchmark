#include "sectionheader.h"


Header::Header(QString gpuName , QString vendorLogo)
: m_gpuName{gpuName}, m_vendorLogo{vendorLogo}{
    setAttribute(Qt::WA_StyledBackground, true);

    auto* mainLayout = new QHBoxLayout(this);
    
    auto* rightLayout = new QVBoxLayout();
    auto* leftLayout = new QVBoxLayout();
    
    auto *titleLabel = new QLabel(m_title);
    titleLabel->setObjectName("titleLabel");
    auto *descriptionLabel = new QLabel(m_description);
    descriptionLabel->setObjectName("descriptionLabel");
    auto *gpuNameLabel = new QLabel(m_gpuName);
    gpuNameLabel->setObjectName("gpuNameLabel");
    auto *sectionIcon = new ImageLabel(this);
    sectionIcon->setImagePixmap(QPixmap(m_sectionIcon));
    sectionIcon->setSizePolicy(
    QSizePolicy::Minimum,
    QSizePolicy::Minimum
    );
    auto *vendorLogoLabel = new ImageLabel();
    vendorLogoLabel->setImagePixmap(QPixmap(m_vendorLogo));

    mainLayout->addWidget(sectionIcon, 1  );
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