#include "ParameterWidget.hpp"

#include <QGridLayout>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>


ParameterWidget::ParameterWidget(QWidget* parent)
    : QWidget{ parent }
    , m_xSpinBox{ new QDoubleSpinBox{} }
    , m_ySpinBox{ new QDoubleSpinBox{} }
    , m_widthSpinBox{ new QDoubleSpinBox{} }
    , m_heightSpinBox{ new QDoubleSpinBox{} }
{
    auto* layout{ new QGridLayout{} };

    layout->addWidget(new QLabel{ tr("left") }, 0, 0);
    m_xSpinBox->setRange(-10.0, 10.0);
    m_xSpinBox->setValue(-2.5);
    connect(
        m_xSpinBox.get(),
        qOverload<double>(&QDoubleSpinBox::valueChanged),
        this,
        [this](double /* value */) { sendChangedEvent(); });
    layout->addWidget(m_xSpinBox, 0, 1);

    layout->addWidget(new QLabel{ tr("bottom") }, 1, 0);
    m_ySpinBox->setRange(-10.0, 10.0);
    m_ySpinBox->setValue(-1.0F);
    connect(
        m_ySpinBox.get(),
        qOverload<double>(&QDoubleSpinBox::valueChanged),
        this,
        [this](double /* value */) { sendChangedEvent(); });
    layout->addWidget(m_ySpinBox, 1, 1);

    layout->addWidget(new QLabel{ tr("width") }, 2, 0);
    m_widthSpinBox->setRange(-10.0, 10.0);
    m_widthSpinBox->setValue(3.5);
    connect(
        m_widthSpinBox.get(),
        qOverload<double>(&QDoubleSpinBox::valueChanged),
        this,
        [this](double /* value */) { sendChangedEvent(); });
    layout->addWidget(m_widthSpinBox, 2, 1);

    layout->addWidget(new QLabel{ tr("height") }, 3, 0);
    m_heightSpinBox->setRange(-10.0, 10.0);
    m_heightSpinBox->setValue(2.0);
    connect(
        m_heightSpinBox.get(),
        qOverload<double>(&QDoubleSpinBox::valueChanged),
        this,
        [this](double /* value */) { sendChangedEvent(); });
    layout->addWidget(m_heightSpinBox, 3, 1);

    auto* groupBox{ new QGroupBox{ tr("Parameters") } };
    groupBox->setLayout(layout);
    auto* centralLayout{ new QVBoxLayout{} };
    centralLayout->addWidget(groupBox);
    auto* resetButton{ new QPushButton{tr("Reset")}};
    connect(resetButton, &QPushButton::clicked, this, [this]() {
        m_xSpinBox->setValue(-2.5);
        m_ySpinBox->setValue(-1.0F);
        m_widthSpinBox->setValue(3.5);
        m_heightSpinBox->setValue(2.0);

        sendChangedEvent();
    });

    centralLayout->addWidget(resetButton);

    setLayout(centralLayout);
}


void ParameterWidget::sendChangedEvent()
{
    QRectF region;
    region.setX(m_xSpinBox->value());
    region.setY(m_ySpinBox->value());
    region.setWidth(m_widthSpinBox->value());
    region.setHeight(m_heightSpinBox->value());

    emit regionChanged(region);
}
