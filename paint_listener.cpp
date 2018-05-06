#include <QTimerEvent>
#include "paint_listener.h"


PaintListener::PaintListener(CvMatPlayer &player, int latensy, QObject *parent)
    : QObject{ parent }
    , _player{ player }
    , _latensy{ latensy }
{
    _timerId = startTimer(_latensy);
}

void PaintListener::process(Frame const &frame)
{
    std::lock_guard<std::mutex> locker{ _mutex };
    _frames.push_back(frame);
}

void PaintListener::timerEvent(QTimerEvent *ev)
{
    if (ev->timerId() == _timerId)
    {
        std::lock_guard<std::mutex> locker{ _mutex };
        if (_frames.empty())
            return;

        _player.setFrame(_frames.front());
        _frames.pop_front();
    }
}
