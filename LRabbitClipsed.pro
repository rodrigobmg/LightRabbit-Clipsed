#-------------------------------------------------
#
# Project created by QtCreator 2013-07-23T10:29:53
#
#-------------------------------------------------

QT       += core gui
QT += opengl



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LRabbitClipsed
TEMPLATE = app


SOURCES += main.cpp\
    DrawableEntity.cpp \
    EntityObject.cpp \
    Line.cpp \
    VertexBufferManager.cpp \
    Sprite.cpp \
    SpriteBatch.cpp \
    Camera2D.cpp \
    DefaultShaders.cpp \
    FormAbout.cpp \
    GLWidget.cpp \
    MainWindow.cpp \
    Rect.cpp \
    Scene.cpp \
    SceneObject.cpp \
    TextureAtlas.cpp \
    TextureRegion.cpp \
    FormNewClip.cpp \
    MainWindow2.cpp

HEADERS  += \
    DrawableEntity.h \
    VertexTypes.h \
    EntityObject.h \
    Line.h \
    VertexBufferManager.h \
    Sprite.h \
    SpriteBatch.h \
    Camera2D.h \
    DefaultShaders.h \
    FormAbout.h \
    GLWidget.h \
    MainWindow.h \
    Rect.h \
    Scene.h \
    SceneObject.h \
    TextureAtlas.h \
    TextureRegion.h \
    FormNewClip.h \
    ListWidgetItems.h

FORMS    += \
    FormAbout.ui \
    MainWindow.ui \
    FormNewClip.ui

OTHER_FILES += \
    README.md

RESOURCES += \
    Shaders.qrc \
    Icons.qrc

QMAKE_CXXFLAGS += -std=c++11
