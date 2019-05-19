TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += pessoal
INCLUDEPATH += textures

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    pessoal/objeto.cpp \
    pessoal/planeta.cpp \
    main.cpp \
    pessoal/astronauta.cpp \
    pessoal/texturemanager.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    pessoal/objeto.h \
    pessoal/planeta.h \
    pessoal/texturemanager.h \
    pessoal/astronauta.h
