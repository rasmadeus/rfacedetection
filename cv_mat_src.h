#ifndef CV_MAT_SRC_H
#define CV_MAT_SRC_H

class CvMatSrc
{
public:
    CvMatSrc(QString const &videoFilePath);
    ~CvMatSrc();
    cv::Mat next();
    double fps() const;

private:
    cv::VideoCapture _videoCapture;
    double _fps{ 0.0 };
};

#endif // CV_MAT_SRC_H
