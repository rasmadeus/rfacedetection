#include "cv_mat_player.h"

#include <QPainter>

CvMatPlayer::CvMatPlayer(QWidget *parent)
    : QWidget{ parent }
{
}

void CvMatPlayer::setFrame(const Frame &frame)
{
    _frame = frame.toPixmap();
    repaint();
}

void CvMatPlayer::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev)

    QPainter painter{ this };
    painter.fillRect(rect(), Qt::black);

    if (_frame.isNull())
        return;

    QPixmap const frame = _frame.scaled(width(), height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QRect frameRect = frame.rect();
    frameRect.moveCenter(rect().center());

    painter.drawPixmap(frameRect, frame);
}
