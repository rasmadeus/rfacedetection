#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include "cv_mat_reader.h"
#include "ui_main_view.h"

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget* parent = nullptr);

private:
    void loadVideo();

private:
    Ui::MainView _ui;
    CvMatReader _reader;
};

#endif // MAIN_VIEW_H
