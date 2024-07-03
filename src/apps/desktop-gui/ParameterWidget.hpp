#pragma once

#include <QDoubleSpinBox>
#include <QRectF>
#include <QWidget>

#include <gsl/pointers>


class ParameterWidget : public QWidget
{
    Q_OBJECT

signals:
    void regionChanged(const QRectF&);

public:
    explicit ParameterWidget(QWidget* parent = nullptr);

private:
    void sendChangedEvent();

    gsl::not_null<QDoubleSpinBox*> m_xSpinBox;
    gsl::not_null<QDoubleSpinBox*> m_ySpinBox;
    gsl::not_null<QDoubleSpinBox*> m_widthSpinBox;
    gsl::not_null<QDoubleSpinBox*> m_heightSpinBox;
};
