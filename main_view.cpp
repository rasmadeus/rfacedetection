#include "file_src.h"
#include "main_view.h"

#include <QFileDialog>

MainView::MainView(QWidget* parent)
    : QMainWindow{ parent }
{
    _ui.setupUi(this);    
    connect(_ui.actionLoad, &QAction::triggered, this, &MainView::loadVideo);
}

void MainView::loadVideo()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load video..."));
    if (!fileName.isEmpty())
    {
        auto fileSrc = std::make_unique<FileSrc>(fileName.toLocal8Bit().constData());
        _paintListener = std::make_shared<PaintListener>(*_ui.cvMatPlayer, 1000.0 / fileSrc->fps());
        _frameSrcExecutor = std::make_unique<FrameSrcExecutor>(std::move(fileSrc));
        _frameSrcExecutor->add(_paintListener);
    }
}
