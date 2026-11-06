#pragma once

#include<QtWidgets>


class Header : public QWiddget{
    public:
        Header();
    private:
        const QString m_title = "GPU Details";
        const QString sectionIcon = "cpu";
        const QString description = "Properties, performance, and test results.";
        QString gpu_name;
        QString vendorLogo;
        
}
