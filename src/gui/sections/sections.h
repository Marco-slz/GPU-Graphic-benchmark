// Declares the stacked container used to switch between main content sections.
#pragma once
#include "gpu_section.h"
#include <QtWidgets>

// Manages section pages and exposes a method to select one by index.
class Sections : public QStackedWidget
{
    Q_OBJECT
  public:
    Sections(QWidget *parent = nullptr);
    void changeSection(int section);

  private:
    GpuSection *gpu;
};
