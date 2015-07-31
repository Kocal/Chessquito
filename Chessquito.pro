TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++1y

LIBS += -lSDL


SOURCES += \
    Joueur.cpp \
    main.cpp \
    Partie.cpp \
    Piece.cpp \
    Plateau.cpp \
    Util.cpp \
    Reine.cpp \
    Tour.cpp \
    Fou.cpp \
    Cavalier.cpp \
    Pion.cpp \
    Roi.cpp

HEADERS += \
    Joueur.h \
    Partie.h \
    Piece.h \
    Plateau.h \
    Util.h \
    Reine.h \
    Tour.h \
    Fou.h \
    Cavalier.h \
    Pion.h \
    Roi.h

