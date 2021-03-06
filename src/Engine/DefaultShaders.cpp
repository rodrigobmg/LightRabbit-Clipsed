#include "DefaultShaders.h"

#include <QDebug>
#include <QGLShaderProgram>

DefaultShaders *DefaultShaders::instance = 0;


DefaultShaders::DefaultShaders()
{
    shaders.insert("SimpleTextured", loadShaders("vshader.glsl", "fshader.glsl"));
    shaders.insert("PrimitiveColor", loadShaders("vs_primitive_color.glsl", "fs_primitive_color.glsl"));
    shaders.insert("SpriteBatch", loadShaders("VS_SpriteBatch.glsl", "FS_SpriteBatch.glsl"));
}

DefaultShaders::~DefaultShaders()
{
    QMapIterator<QString, QGLShaderProgram *> i(shaders);
    while (i.hasNext())
    {
        i.next();
        delete i.value();
    }

    shaders.clear();
}

QGLShaderProgram *DefaultShaders::loadShaders(QString vsFilename, QString fsFilename)
{
    vsFilename = ":/shaders/" + vsFilename;
    fsFilename = ":/shaders/" + fsFilename;

    QGLShaderProgram *program = new QGLShaderProgram();

    setlocale(LC_NUMERIC, "C");

    if (!program->addShaderFromSourceFile(QGLShader::Vertex, vsFilename))
        qDebug() << "Compile Vertex shader: fail" << endl;

    if (!program->addShaderFromSourceFile(QGLShader::Fragment, fsFilename))
        qDebug() << "Compile Fragment shader: fail" << endl;

    if (!program->link())
        qDebug() << "link shaders program: fail" << endl;

    if (!program->bind())
        qDebug() << "bind shaders program: fail" << endl;

    qDebug() << "Shader program log:" << program->log();

    setlocale(LC_ALL, "");

    return program;
}



QGLShaderProgram *DefaultShaders::getShader(QString shaderName)
{
    QGLShaderProgram *value = 0;

    if (shaders.contains(shaderName))
    {
        value = shaders.value(shaderName);
    }
    else
    {
        qDebug() << "DefaultShaders::getShader: can't find shader:" << shaderName << endl;
    }

    return value;
}







DefaultShaders *DefaultShaders::getInstance()
{
    if (instance == 0)
        instance = new DefaultShaders();
    return instance;
}

void DefaultShaders::deleteInstance()
{
    if (instance != 0)
        delete instance;
    instance = 0;
}
