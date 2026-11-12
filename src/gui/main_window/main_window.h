// Declares the top-level window and its navigation and content widgets.
#pragma once

#include "sections.h"
#include "sidebar.h"
#include <QtWidgets>

// Main application window that connects sidebar navigation to content pages.
class MainWindow : public QMainWindow
{
  public:
    explicit MainWindow(QWidget *parent = nullptr);
  private:
    Sidebar *sidebar;
    Sections *sections;
};
