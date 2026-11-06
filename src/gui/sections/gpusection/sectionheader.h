#pragma once

#include<QtWidgets>
#include <QPixmap>

class Header : public QWidget{
    public:
        Header(QString gpuName, QString vendorLogo);
    private:
        const QString m_title = "GPU Details";
        const QString m_sectionIcon = ":/icons/cpu";
        const QString m_description = "Properties, performance, and test results.";
        QString m_gpuName;
        QString m_vendorLogo;
        
};
