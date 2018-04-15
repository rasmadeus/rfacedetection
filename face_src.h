#ifndef FACE_SRC_H
#define FACE_SRC_H

#include "frame.h"
#include <atomic>
#include <thread>
#include <future>
#include <QObject>

class FaceSrc : public QObject
{
    Q_OBJECT
public:
    explicit FaceSrc(QObject *parent = nullptr);
    ~FaceSrc() override;

    double start(QString const &path);
    void stop();

private:
    void startPlay(QString const &path, std::promise<double> &&fps);

signals:
    void ready(Frame const &frame);

private:

    std::atomic<bool> _isPlaying{ false };
    std::unique_ptr<std::thread> _thread{ nullptr };
};

#endif // FACE_SRC_H
