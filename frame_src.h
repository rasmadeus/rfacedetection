#ifndef FRAME_SRC_H
#define FRAME_SRC_H

class Frame;


class FrameSrc
{
public:
    virtual ~FrameSrc() = default;
    virtual Frame next() = 0;
};

#endif // FRAME_SRC_H
