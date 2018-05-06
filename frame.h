#ifndef FRAME_H
#define FRAME_H

class Frame
{
public:
    Frame() = default;
    Frame(cv::Mat &&frame);

    bool empty() const { return _frame.empty(); }

    QPixmap toPixmap() const;
    cv::Mat toGray() const;
    cv::Mat toGray8U() const;

    cv::Mat const &frame() const { return _frame; }
    void append(std::vector<cv::Rect> const &faces, cv::Scalar const &color = { 255, 0, 0 });

private:
    cv::Mat _frame;
};

#endif // FRAME_H
