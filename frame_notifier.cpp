#include <algorithm>
#include "frame_notifier.h"


void FrameNotifier::add(const std::shared_ptr<FrameListener> &listener)
{
    std::lock_guard<std::mutex> locker{ _mutex };
    _listeners.push_back(listener);
}

void FrameNotifier::remove(const std::shared_ptr<FrameListener> &listener)
{
    std::lock_guard<std::mutex> locker{ _mutex };
    auto newEnd = std::remove(_listeners.begin(), _listeners.end(), listener);
    _listeners.erase(newEnd, _listeners.end());
}

void FrameNotifier::notify(Frame const &frame)
{
    std::lock_guard<std::mutex> locker{ _mutex };
    for(auto &listener : _listeners)
        listener->process(frame);
}
