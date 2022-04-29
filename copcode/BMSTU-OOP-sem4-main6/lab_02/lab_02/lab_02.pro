TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        base_errors.cpp \
        base_iterator.cpp \
        base_vector.cpp \
        main.cpp

HEADERS += \
    base_errors.h \
    base_iterator.h \
    base_matrix.hpp \
    base_vector.h \
    const_iterator.h \
    const_iterator.hpp \
    defines.h \
    errors.h \
    iterator.h \
    iterator.hpp \
    vector.h \
    vector.hpp

