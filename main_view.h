#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include <memory>
#include "frame_src_executor.h"
#include "paint_listener.h"
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
    std::shared_ptr<PaintListener> _paintListener;
    std::unique_ptr<FrameSrcExecutor> _frameSrcExecutor{ nullptr };
};

#endif // MAIN_VIEW_H
