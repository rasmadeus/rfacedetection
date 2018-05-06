#ifndef CV_MAT_PLAYER_H
#define CV_MAT_PLAYER_H

#include "frame.h"
#include <QWidget>

class CvMatPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit CvMatPlayer(QWidget *parent = nullptr);
    void setFrame(Frame const &frame);

protected:
    void paintEvent(QPaintEvent *ev) override;

private:
    QPixmap _frame;
};

#endif // CV_MAT_PLAYER_H
