#include "gpu_selector.h"

GpuSelector::GpuSelector(Backend &backend, QWidget *parent)
    : QWidget(parent), backend(backend)
{
    innerArea = new QWidget(this);
    innerAreaLayout = new QHBoxLayout(innerArea);
    auto *scanButton = addButton("Scan");

    auto *scrollArea = new QScrollArea();
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(innerArea);

    layout = new QHBoxLayout(this);
    layout->addWidget(scanButton);
    layout->addWidget(scrollArea, 10);

    connect(scanButton, &QPushButton::clicked, this,
            [this]() {
                this->backend.scanGpus();
                updateValues(this->backend.getAvailableGpus());
            });
}
    void GpuSelector::updateValues(const std::vector<Gpu> &labels)
    {
        for (size_t i = 0; i < availableGpus.size(); i++)
        {
            innerAreaLayout->removeWidget(availableGpus[i]);
            availableGpus[i]->deleteLater();
        }
        availableGpus.clear();
        for (size_t i = 0; i < labels.size(); i++)
        {
            auto *button =
                addButton(QString::fromStdString(labels[i].get_model()));
            availableGpus.push_back(button);
            connect(button, &QPushButton::clicked, this, [this, i]() {
                emit gpuRequested(static_cast<int>(i));
            });
        }
    }

    QPushButton *GpuSelector::addButton(const QString label)
    {
        // Create an icon-only button and use its tooltip as its accessible
        // label.
        auto *button = new QPushButton(label, this);
        button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        button->setStyleSheet("background-color: #6dbdd5");
        innerAreaLayout->addWidget(button);
        return button;
    }
