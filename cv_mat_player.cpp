#include "cv_mat_player.h"
#include "asm_open_cv.h"

#include <QPainter>
#include <QPaintEvent>

CvMatPlayer::CvMatPlayer(QWidget *parent)
    : QWidget(parent)
{
}

void CvMatPlayer::setFrame(cv::Mat const &mat)
{
    _frame = ASM::cvMatToQPixmap(mat);
    repaint();
}

void CvMatPlayer::paintEvent(QPaintEvent *ev)
{
    std::ignore = ev;

    QPainter painter{ this };
    painter.fillRect(rect(), Qt::black);

    if (_frame.isNull())
        return;

    const QPixmap frame = _frame.scaled(width(), height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QRect frameRect = frame.rect();
    frameRect.moveCenter(rect().center());

    painter.drawPixmap(frameRect, frame);
}
