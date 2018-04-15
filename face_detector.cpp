#include "face_detector.h"

FaceDetector::FaceDetector()
{
    _faceCascade.load("./res/haarcascade_frontalface.xml");
}

std::vector<cv::Rect> FaceDetector::find(cv::Mat const &frame)
{
    static const int faceNeighborsMax = 9;
    static const double scaleFactor = 1.2;

    std::vector<cv::Rect> faces;
    _faceCascade.detectMultiScale(frame, faces, scaleFactor, faceNeighborsMax);

    return faces;
}
