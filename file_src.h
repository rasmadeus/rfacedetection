#ifndef FILE_SRC_H
#define FILE_SRC_H

#include "frame.h"
#include "frame_src.h"


class FileSrc : public FrameSrc
{
public:
    FileSrc(QString &&pathToVideoFile);
    ~FileSrc() override;

    Frame next() override;
    double fps() const { return _fps; }

private:
    cv::VideoCapture _videoCapture;
    double _fps{ 0.0 };
};

#endif // FILE_SRC_H
