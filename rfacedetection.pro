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
    cv_mat_src.cpp \
    cv_mat_reader.cpp

HEADERS += \
    asm_open_cv.h \
    main_view.h \
    pch.h \
    cv_mat_player.h \
    cv_mat_src.h \
    cv_mat_reader.h

FORMS += \
    main_view.ui
