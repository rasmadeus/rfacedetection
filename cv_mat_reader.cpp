#include "cv_mat_reader.h"

CvMatReader::CvMatReader(QObject *parent)
    : QObject{ parent }
{
}

CvMatReader::~CvMatReader()
{
    stop();
}

void CvMatReader::start(QString const &path)
{
    stop();
    _thread = std::make_unique<std::thread>(&CvMatReader::read, this, path);
}

void CvMatReader::stop()
{
    if (_thread)
    {
        _isRunning = false;
        _thread->join();
        _thread.release();
    }
}

void CvMatReader::read(QString const &path)
{
    _isRunning = true;
    CvMatSrc src{ path };

    const std::chrono::milliseconds fps{ static_cast<int>(1000.0 / src.fps()) };

    while(_isRunning)
    {
        cv::Mat mat = src.next();
        if (mat.empty())
            _isRunning = false;
        else
        {
            emit readyRead(mat);
            std::this_thread::sleep_for(fps);
        }
    }
}
