TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += trab1

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    trabalho01/caramujao.cpp \
    trabalho01/entrada.cpp \
    trabalho01/banco.cpp \
    trabalho01/pedraFundamental.cpp \
    trabalho01/arvore.cpp \
    trabalho01/bloco.cpp \
    trabalho01/piso.cpp \
    trabalho01/objeto.cpp
HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    trabalho01/caramujao.h \
    trabalho01/entrada.h \
    trabalho01/banco.h \
    trabalho01/pedraFundamental.h \
    trabalho01/arvore.h \
    trabalho01/bloco.h \
    trabalho01/piso.h \
    trabalho01/objeto.h

