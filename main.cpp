#include "frame.h"
#include "main_view.h"

Q_DECLARE_METATYPE(Frame);
Q_DECLARE_METATYPE(cv::Mat);
Q_DECLARE_METATYPE(std::vector<cv::Rect>);

int main(int argc, char *argv[])
{
    QApplication app{ argc, argv };

    qRegisterMetaType<Frame>("Frame");
    qRegisterMetaType<cv::Mat>("cv::Mat");
    qRegisterMetaType<std::vector<cv::Rect>>("std::vector<cv::Rect>");

    MainView mainView;
    mainView.show();

    return app.exec();
}
