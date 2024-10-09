TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        class_Estacion.cpp \
        class_Naves.cpp \
        class_RedNacional.cpp \
        class_Surtidor.cpp \
        class_Tanque.cpp \
        class_Ventas.cpp \
        funcionesGenerales.cpp \
        main.cpp

HEADERS += \
    class_Estacion.h \
    class_Naves.h \
    class_RedNacional.h \
    class_Surtidor.h \
    class_Tanque.h \
    class_Ventas.h \
    funcionesGenerales.h
