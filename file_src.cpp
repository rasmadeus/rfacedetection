#include "file_src.h"

FileSrc::FileSrc(QString &&pathToVideoFile)
    : _videoCapture{ pathToVideoFile.toStdString() }
    , _fps{ _videoCapture.get(CV_CAP_PROP_FPS) }
{
}

FileSrc::~FileSrc()
{
    _videoCapture.release();
}

Frame FileSrc::next()
{
    cv::Mat frame;
    _videoCapture >> frame;
    return { std::move(frame) };
}
