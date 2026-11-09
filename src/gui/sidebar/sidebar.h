// Declares the sidebar navigation widget and its section selection signal.
#pragma once

#include "sections.h"
#include <QtWidgets>
// Compact icon navigation that asks the main content to show a section.
class Sidebar : public QWidget
{
    Q_OBJECT
  public:
    Sidebar(QWidget *parent = nullptr);
  signals:
    void sectionRequested(int index);
    void exitRequested();

  private:
    int width = 60;
    std::string color = "gray";
    QPushButton *addButtons(const QString address, const QString label);
};
