// Declares the top-level window and its navigation and content widgets.
#pragma once

#include "sections.h"
#include "backend.h"
#include "sidebar.h"
#include <QtWidgets>

// Main application window that connects sidebar navigation to content pages.
class MainWindow : public QMainWindow
{
  public:
      MainWindow(Backend &backend, QWidget *parent = nullptr);
  private:
    Backend &backend;
    Sidebar *sidebar;
    Sections *sections;
};
