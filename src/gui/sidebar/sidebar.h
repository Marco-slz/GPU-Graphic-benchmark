#pragma once

#include <QtWidgets>
#include "sections.h"
class Sidebar : public QWidget
{
  Q_OBJECT
  public:
    Sidebar(QWidget *parent = nullptr);
  signals:
    void sectionRequested(int index);
  private:
    int width = 60;
    std::string color = "gray";
    QPushButton *addButtons(const QString address, const QString label);
};