#ifndef FRAME_SRC_EXECUTOR_H
#define FRAME_SRC_EXECUTOR_H

#include <atomic>
#include <memory>
#include <thread>
#include "frame_listener.h"
#include "frame_notifier.h"
#include "frame_src.h"


class FrameSrcExecutor : public FrameNotifier
{
public:
    explicit FrameSrcExecutor(std::unique_ptr<FrameSrc> &&frameSrc);
    ~FrameSrcExecutor();

private:
    void run();

private:
    std::unique_ptr<FrameSrc> _frameSrc;
    std::thread _thread;
    std::atomic<bool> _doWork{ true };
};

#endif // FRAME_SRC_EXECUTOR_H
