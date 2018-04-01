#include "main_view.h"

Q_DECLARE_METATYPE(cv::Mat);

int main(int argc, char *argv[])
{
    QApplication app{ argc, argv };

    qRegisterMetaType<cv::Mat>("cv::Mat");

    MainView mainView;
    mainView.show();

    return app.exec();
}
