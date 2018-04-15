#include "frame.h"

Frame::Frame(cv::Mat &&frame)
    : _frame{ std::move(frame) }
{
}

void Frame::append(std::vector<cv::Rect> const &faces, cv::Scalar const &color)
{
    for(const auto& faceRect : faces)
    {
        const int x = faceRect.x;
        const int y = faceRect.y;
        const int w = faceRect.width;
        const int h = faceRect.height;
        cv::rectangle(_frame, cv::Point{ x, y }, cv::Point{ x + w, y + h }, color, 2, 4);
    }
}

cv::Mat Frame::toGray() const
{
    cv::Mat frameGray;
    cv::cvtColor(_frame, frameGray, cv::COLOR_BGR2GRAY);
    return frameGray;
}

cv::Mat Frame::toGray8U() const
{
    auto frameGray = toGray();

    double min = 0.0;
    double max = 0.0;
    cv::minMaxLoc(frameGray, &min, &max);

    cv::Mat gray8U;
    frameGray.convertTo(gray8U, CV_8U, 255.0 / (max - min), - min);
    return gray8U;
}
