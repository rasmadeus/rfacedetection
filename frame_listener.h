#ifndef FRAME_LISTENER_H
#define FRAME_LISTENER_H

#include "frame.h"


class FrameListener
{
public:
    virtual ~FrameListener() = default;
    virtual void process(Frame const &frame) = 0;
};

#endif // FRAME_LISTENER_H
