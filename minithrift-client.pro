TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    calculator_types.cpp \
    calculator_constants.cpp \
    Calculator.cpp


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += thrift

OTHER_FILES += \
    calculator.thrift

HEADERS += \
    calculator_types.h \
    calculator_constants.h \
    Calculator.h
