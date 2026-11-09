// Creates sidebar buttons and emits page requests in response to selections.
#include "sidebar.h"

Sidebar::Sidebar(QWidget *parent) : QWidget(parent)
{
    // Enable stylesheet backgrounds and build the fixed-width navigation rail.
    setAttribute(Qt::WA_StyledBackground, true);

    setFixedWidth(76);
    // Create icon buttons and arrange them vertically.
    auto *gpu_button = addButtons(":/icons/gpu", "GPUs");
    auto *settings_button = addButtons(":/icons/settings", "Settings");
    auto *statistics_button = addButtons(":/icons/statistics", "Statistics");
    auto *exit_button = addButtons(":/icons/exit", "Exit");
    auto *layout = new QVBoxLayout(this);
    layout->setObjectName("sidebarButtons");
    layout->addStretch();
    layout->addStretch();
    layout->addWidget(gpu_button);
    layout->addStretch();
    layout->addWidget(settings_button);
    layout->addStretch();
    layout->addWidget(statistics_button);
    layout->addStretch();
    layout->addStretch();
    layout->addWidget(exit_button);

    // Convert button clicks into requests for the corresponding content page.
    connect(gpu_button, &QPushButton::clicked, this,
            [this]() { emit sectionRequested(0); });
    connect(settings_button, &QPushButton::clicked, this,
            [this]() { emit sectionRequested(1); });
    connect(exit_button, &QPushButton::clicked, this,
            [this]() { emit exitRequested(); });
}

QPushButton *Sidebar::addButtons(const QString address, const QString label)
{
    // Create an icon-only button and use its tooltip as its accessible label.
    auto *button = new QPushButton(QIcon(address), "", this);
    button->setStyleSheet("background-color: #6dbdd5");
    button->setIconSize(QSize(54, 54));
    button->setToolTip(label);
    return button;
}
