#pragma once

#include <QLabel>
#include <QMainWindow>

#include <gsl/pointers>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void refresh();

private:
    void initLayout();
    void initActions();

    gsl::not_null<QLabel*> m_pixmapLabel;
};
