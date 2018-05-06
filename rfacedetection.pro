QT += core gui widgets

TARGET = lfacedetection
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += precompile_header c++14
PRECOMPILED_HEADER = pch.h

include(./opencv.pri)

SOURCES += \
    main.cpp \
    main_view.cpp \
    cv_mat_player.cpp \
    face_detector.cpp \
    frame.cpp \
    frame_listener.cpp \
    frame_src.cpp \
    file_src.cpp \
    frame_src_executor.cpp \
    frame_notifier.cpp \
    paint_listener.cpp

HEADERS += \
    asm_open_cv.h \
    main_view.h \
    pch.h \
    cv_mat_player.h \
    face_detector.h \
    frame.h \
    frame_listener.h \
    frame_src.h \
    file_src.h \
    frame_src_executor.h \
    frame_notifier.h \
    paint_listener.h

FORMS += \
    main_view.ui

RESOURCES += \
    res.qrc
