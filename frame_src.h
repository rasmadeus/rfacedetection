#ifndef FRAME_SRC_H
#define FRAME_SRC_H

#include "frame.h"
#include <QObject>

class FrameSrc : public QObject
{
    Q_OBJECT
public:
    explicit FrameSrc(QObject *parent = nullptr);

    void start(double fps);
    void stop();
    void push(Frame const &frame);

protected:
    void timerEvent(QTimerEvent *ev) override;

signals:
    void ready(cv::Mat const &frame);

private:
    int _fpsTimerId{ -1 };
    std::queue<Frame> _frames;
};

#endif // FRAME_SRC_H
