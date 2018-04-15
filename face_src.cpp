#include "face_src.h"
#include "frame.h"
#include "cv_mat_src.h"
#include "face_detector.h"

FaceSrc::FaceSrc(QObject *parent) :
    QObject{ parent }
{
}

FaceSrc::~FaceSrc()
{
    stop();
}

double FaceSrc::start(QString const &path)
{
    stop();

    std::promise<double> fpsPromise;
    auto fpsFuture = fpsPromise.get_future();

    _thread = std::make_unique<std::thread>(&FaceSrc::startPlay, this, path, std::move(fpsPromise));

    return fpsFuture.get();
}

void FaceSrc::startPlay(QString const &path, std::promise<double> &&fps)
{
    _isPlaying = true;

    CvMatSrc src{ path };
    FaceDetector detector;

    if (!src.isOpened() || detector.empty())
    {
        _isPlaying = false;
        fps.set_value(0.0);
    }
    else
    {
        fps.set_value(src.fps());
    }

    while(_isPlaying)
    {
        auto frameMat = src.next();
        if (frameMat.empty())
        {
            _isPlaying = false;
        }
        else
        {
            Frame frame{ std::move(frameMat) };
            const auto faces = detector.find(frame.toGray8U());
            frame.append(faces);

            emit ready(frame);
        }
    }
}

void FaceSrc::stop()
{
    if (_isPlaying)
    {
        _isPlaying = false;
        _thread->join();
        _thread.reset(nullptr);
    }
}
