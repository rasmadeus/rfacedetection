#ifndef FRAME_NOTIFIER_H
#define FRAME_NOTIFIER_H

#include <memory>
#include <mutex>
#include <vector>
#include "frame_listener.h"


class FrameNotifier
{
public:
    void add(std::shared_ptr<FrameListener> const &listener);
    void remove(std::shared_ptr<FrameListener> const &listener);
    void notify(const Frame &frame);

private:
    std::mutex _mutex;
    std::vector<std::shared_ptr<FrameListener>> _listeners;
};

#endif // FRAME_NOTIFIER_H
