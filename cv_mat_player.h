#ifndef CV_MAT_PLAYER_H
#define CV_MAT_PLAYER_H

#include <QWidget>

class CvMatPlayer : public QWidget
{
    Q_OBJECT
public:
    explicit CvMatPlayer(QWidget *parent = nullptr);
    void setFrame(cv::Mat const &mat);

signals:
    void started();
    void stopped();
    void frameReady(const cv::Mat& mat);

protected:
    void paintEvent(QPaintEvent *ev) override;

private:
    QPixmap _frame;
};

#endif // CV_MAT_PLAYER_H
