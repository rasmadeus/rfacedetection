#ifndef PAINT_LISTENER_H
#define PAINT_LISTENER_H

#include <deque>
#include <mutex>
#include <QObject>
#include "cv_mat_player.h"
#include "frame_listener.h"
#include "face_detector.h"


class PaintListener : public QObject, public FrameListener
{
    Q_OBJECT

public:
    explicit PaintListener(CvMatPlayer &player, int latensy, QObject *parent = nullptr);
    void process(Frame const &frame) override;

protected:
    void timerEvent(QTimerEvent *ev) override;

private:
    int _timerId{ -1 };
    CvMatPlayer &_player;
    std::mutex _mutex;
    std::deque<Frame> _frames;
    int _latensy;
};

#endif // PAINT_LISTENER_H
