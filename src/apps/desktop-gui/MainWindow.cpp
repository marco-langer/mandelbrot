#include "MainWindow.hpp"

#include "ParameterWidget.hpp"

#include "Mandelbrot.hpp"

#include <QAction>
#include <QDebug>   // TODO
#include <QDockWidget>
#include <QMenuBar>
#include <QPixmap>

#include <gsl/narrow>


namespace {
QPixmap toPixMap(const PixelBuffer& pixelBuffer)
{
    QPixmap image{ gsl::narrow_cast<int>(pixelBuffer.width()),
                   gsl::narrow_cast<int>(pixelBuffer.height()) };
    image.fill(Qt::red);
    return image;
}

}   // namespace


MainWindow::MainWindow()
    : m_pixmapLabel{ new QLabel{ this } }
{
    initLayout();
    initActions();

    refresh();
}


void MainWindow::refresh()
{
    const Params params{ .size{ .width{ 800 }, .height{ 600 } },
                         .region{ .x{ -2.5F }, .y{ -1.0F }, .width{ 3.5F }, .height{ 2.0F } },
                         .maxIterations{ 100 },
                         .threshhold{ 1000.0F } };
    PixelBuffer pixelBuffer{ createMandelbrot(params) };
    QPixmap image{ toPixMap(pixelBuffer) };
    m_pixmapLabel->setPixmap(image);
}


void MainWindow::initLayout()
{
    auto* dockWidget{ new QDockWidget{ this } };
    dockWidget->setAllowedAreas(Qt::RightDockWidgetArea);
    auto* parameterWidget{ new ParameterWidget{ this } };
    connect(parameterWidget, &ParameterWidget::regionChanged, this, [](const QRectF& region) {
        qDebug() << region;
    });
    dockWidget->setWidget(parameterWidget);
    dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);

    addDockWidget(Qt::RightDockWidgetArea, dockWidget);

    setCentralWidget(m_pixmapLabel);
}


void MainWindow::initActions()
{
    gsl::not_null<QMenu*> fileMenu{ menuBar()->addMenu(tr("&File")) };

    auto* exitAction{ new QAction{ tr("Exit"), this } };
    exitAction->setShortcut(QKeySequence::Close);
    exitAction->setStatusTip(tr("Close mandelbrot"));
    connect(exitAction, &QAction::triggered, this, &QWidget::close);
    fileMenu->addAction(exitAction);
}
