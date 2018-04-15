#include "frame_src.h"
#include <chrono>
#include <QTimerEvent>

FrameSrc::FrameSrc(QObject *parent)
    : QObject{ parent }
{
}

void FrameSrc::start(double fps)
{
    stop();

    _fpsTimerId = startTimer(std::chrono::milliseconds(static_cast<int>(1000.0 / fps)));
}

void FrameSrc::stop()
{
    if (_fpsTimerId != -1)
    {
        killTimer(_fpsTimerId);
        _fpsTimerId = -1;
    }
}

void FrameSrc::push(Frame const &frame)
{
    _frames.push(frame);
}

void FrameSrc::timerEvent(QTimerEvent *ev)
{
    if (ev->timerId() == _fpsTimerId)
    {
        if (!_frames.empty())
        {
            emit ready(_frames.front().frame());
            _frames.pop();
        }
    }
}
