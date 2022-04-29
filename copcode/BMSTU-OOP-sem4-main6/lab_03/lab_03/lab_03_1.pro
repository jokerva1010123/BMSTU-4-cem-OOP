QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstract_load_controller.cpp \
    builder_camera.cpp \
    builder_model.cpp \
    builder_scene.cpp \
    camera.cpp \
    camera_command.cpp \
    composite.cpp \
    compound.cpp \
    config.cpp \
    facade.cpp \
    links.cpp \
    load_model_controller.cpp \
    load_scene_controller.cpp \
    loader_filecamera.cpp \
    loader_filemodel.cpp \
    loader_filescene.cpp \
    main.cpp \
    mainwindow.cpp \
    manager_draw.cpp \
    manager_draw_creator.cpp \
    manager_load.cpp \
    manager_load_creator.cpp \
    manager_reform.cpp \
    manager_reform_creator.cpp \
    manager_scene.cpp \
    manager_scene_creator.cpp \
    model.cpp \
    model_command.cpp \
    point.cpp \
    qt_drawer.cpp \
    scene.cpp \
    scene_command.cpp

HEADERS += \
    abstract_factory.h \
    abstract_load_controller.h \
    base_builder.h \
    base_command.h \
    base_drawer.h \
    base_loader.h \
    base_loadercamera.h \
    base_loadermodel.h \
    base_loaderscene.h \
    base_manager.h \
    builder_camera.h \
    builder_model.h \
    builder_scene.h \
    camera.h \
    camera_command.h \
    composite.h \
    compound.h \
    config.h \
    errors.hpp \
    facade.h \
    iterator.hpp \
    iterator_base.hpp \
    iterator_const.hpp \
    links.h \
    load_model_controller.h \
    load_scene_controller.h \
    loader_filecamera.h \
    loader_filemodel.h \
    loader_filescene.h \
    mainwindow.h \
    manager_draw.h \
    manager_draw_creator.h \
    manager_load.h \
    manager_load_creator.h \
    manager_reform.h \
    manager_reform_creator.h \
    manager_scene.h \
    manager_scene_creator.h \
    matrix.hpp \
    matrix_base.hpp \
    model.h \
    model_command.h \
    object.h \
    point.h \
    qt_drawer.h \
    qt_factory.h \
    scene.h \
    scene_command.h \
    vector.hpp \
    visitor.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin -lconfig++
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
