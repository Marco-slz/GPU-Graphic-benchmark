#pragma once

#include <QtWidgets>
#include "sidebar.h"
#include "sections.h"

class MainWindow : public QMainWindow
{
    public:
        explicit MainWindow(QWidget *parent = nullptr);
    private:
        Sidebar* sidebar;
        Sections* sections;
        
};
