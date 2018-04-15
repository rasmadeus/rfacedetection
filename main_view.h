#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include "face_src.h"
#include "frame_src.h"
#include "ui_main_view.h"

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget* parent = nullptr);

private:
    void loadVideo();

private:
    FaceSrc _faceSrc;
    FrameSrc _frameSrc;
    Ui::MainView _ui;
};

#endif // MAIN_VIEW_H
