#include "main_view.h"

#include <QFileDialog>

MainView::MainView(QWidget* parent)
    : QMainWindow{ parent }
{
    _ui.setupUi(this);

    connect(_ui.actionLoad, &QAction::triggered, this, &MainView::loadVideo);
    connect(&_reader, &CvMatReader::readyRead, _ui.cvMatPlayer, &CvMatPlayer::setFrame);
}

void MainView::loadVideo()
{
    const QString fileName = QFileDialog::getOpenFileName(this, tr("Load video..."));
    if (!fileName.isEmpty())
        _reader.start(fileName);
}
