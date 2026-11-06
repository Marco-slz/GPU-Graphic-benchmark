#pragma once

#include<QtWidgets>


class Header : public QWiddget{
    public:
        Header();
    private:
        QString m_title;
        QString description;
        QString gpu_name;
        QString vendorLogo;
        QString sectionIcon;
}
