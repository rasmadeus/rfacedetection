#ifndef CV_MAT_READER_H
#define CV_MAT_READER_H

#include <atomic>
#include <memory>
#include <thread>
#include <QObject>
#include "cv_mat_src.h"

class CvMatReader : public QObject
{
    Q_OBJECT

public:
    explicit CvMatReader(QObject* parent = nullptr);
    ~CvMatReader();
    void start(QString const &path);
    void stop();

signals:
    void readyRead(cv::Mat const &frame);

private:
    void read(QString const &path);

private:
    std::atomic<bool> _isRunning{ false };
    std::unique_ptr<std::thread> _thread;
};

#endif // CV_MAT_READER_H
