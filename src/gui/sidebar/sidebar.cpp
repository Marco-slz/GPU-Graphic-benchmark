// Creates sidebar buttons and emits page requests in response to selections.
#include "sidebar.h"

Sidebar::Sidebar(QWidget *parent) : QWidget(parent)
{
    // Enable stylesheet backgrounds and build the fixed-width navigation rail.
    setAttribute(Qt::WA_StyledBackground, true);

    setFixedWidth(64);
    // Create icon buttons and arrange them vertically.
    auto *button1 = addButtons(":/icons/statistics", "Statistics");
    auto *button2 = addButtons(":/icons/settings", "Settings");
    auto *button3 = addButtons(":/icons/gpu", "GPUs");
    // handle layout
    auto *layout = new QVBoxLayout(this);
    layout->setObjectName("sidebarButtons");
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);

    // Convert button clicks into requests for the corresponding content page.
    connect(button1, &QPushButton::clicked, this,
            [this]() { emit sectionRequested(0); });
    connect(button2, &QPushButton::clicked, this,
            [this]() { emit sectionRequested(1); });
}

QPushButton *Sidebar::addButtons(const QString address, const QString label)
{
    // Create an icon-only button and use its tooltip as its accessible label.
    auto *button = new QPushButton(QIcon(address), "", this);
    button->setToolTip(label);
    return button;
}
