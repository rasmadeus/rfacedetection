#include "main_view.h"

#include <QFileDialog>

MainView::MainView(QWidget* parent)
    : QMainWindow{ parent }
{
    _ui.setupUi(this);
    connect(_ui.actionLoad, &QAction::triggered, this, &MainView::loadVideo);
    connect(&_faceSrc, &FaceSrc::ready, &_frameSrc, &FrameSrc::push);
    connect(&_frameSrc, &FrameSrc::ready, _ui.cvMatPlayer, &CvMatPlayer::setFrame);
}

void MainView::loadVideo()
{
    const QString fileName = QFileDialog::getOpenFileName(this, tr("Load video..."));
    if (!fileName.isEmpty())
    {
        const double fps = _faceSrc.start(fileName);
        _frameSrc.start(fps);
    }
}
