#include "entityline.h"

#include "defaultshaders.h"
#include "VertexTypes.h"

EntityLine::EntityLine(float x1, float y1, float x2, float y2)
{
    shaderProgram = DefaultShaders::getInstance()->getShader("PrimitiveColor");

    //p1.setX(x1);
    p1 = QPoint(x1,y1);
    p2 = QPoint(x2,y2);

    initializeGLFunctions();

    glGenBuffers(2, vboIds);

    initGeometry();
}

EntityLine::~EntityLine()
{
    glDeleteBuffers(2, vboIds);
}

void EntityLine::update()
{

}

void EntityLine::draw()
{
    transform.setToIdentity();

    transform.translate(position);
    transform.scale(scale);
    transform.rotate(1.0f, rotation);


    // Set modelview-projection matrix
    shaderProgram->setUniformValue("mvp_matrix", camera->getCameraMatrix() * transform);
    shaderProgram->setUniformValue("color", color);

    glBindBuffer(GL_ARRAY_BUFFER, vboIds[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIds[1]);

    quintptr offset = 0;

    // Locate vertex position data
    int vertexLocation = shaderProgram->attributeLocation("a_position");
    shaderProgram->enableAttributeArray(vertexLocation);
    glVertexAttribPointer(vertexLocation, 3, GL_FLOAT, GL_FALSE, sizeof(VertexSimple), (const void *)offset);

    // Draw from VBO 1
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_SHORT, 0);
}


void EntityLine::initGeometry()
{

    VertexSimple vertices[] = {
        {QVector3D(p1.x(), p1.y(),  0.0)},  // v0
        {QVector3D(p2.x(), p2.y(),  0.0)},  // v1
    };

    GLushort indices[] = {
        0,  1
    };

    // Transfer vertex data to VBO 0
    glBindBuffer(GL_ARRAY_BUFFER, vboIds[0]);
    glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(VertexSimple), vertices, GL_STATIC_DRAW);

    // Transfer index data to VBO 1
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIds[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * sizeof(GLushort), indices, GL_STATIC_DRAW);
}

