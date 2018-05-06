#include "frame_src_executor.h"


FrameSrcExecutor::FrameSrcExecutor(std::unique_ptr<FrameSrc> &&frameSrc)
    : _frameSrc{ std::move(frameSrc) }
    , _thread{ &FrameSrcExecutor::run, this }
{
}

FrameSrcExecutor::~FrameSrcExecutor()
{
    _doWork = false;
    _thread.join();
}

void FrameSrcExecutor::run()
{
    while(_doWork)
    {
        auto frame = _frameSrc->next();
        if (frame.empty())
            _doWork = false;
        else
            notify(frame);
    }
}
