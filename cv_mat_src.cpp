#include "cv_mat_src.h"

CvMatSrc::CvMatSrc(QString const &videoFilePath)
    : _videoCapture{ videoFilePath.toStdString() }
    , _fps{ _videoCapture.get(CV_CAP_PROP_FPS) }
{
}

CvMatSrc::~CvMatSrc()
{
    _videoCapture.release();
}

cv::Mat CvMatSrc::next()
{
    cv::Mat frame;
    _videoCapture >> frame;
    return frame;
}

double CvMatSrc::fps() const
{
    return _fps;
}
