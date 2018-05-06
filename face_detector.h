#ifndef FACE_DETECTOR_H
#define FACE_DETECTOR_H

class FaceDetector
{
public:
    FaceDetector();
    std::vector<cv::Rect> find(cv::Mat const &frame);

private:
    cv::CascadeClassifier _faceCascade;
};

#endif // FACE_DETECTOR_H
