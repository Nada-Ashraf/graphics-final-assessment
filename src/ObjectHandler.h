#ifndef OBJECT_HANDLER_H_INCLUDED
#define OBJECT_HANDLER_H_INCLUDED

#include "glm.h"
#include <string>

#ifndef GL_HEADER
#define GL_HEADER
#include <GL/glut.h>
#endif

class ObjectHandler
{
private:
    GLMmodel *pmodel;
    float x, y, z, angle_y, angle_x, scale;

public:
    ObjectHandler(std::string objectPath, float x, float y, float z, float angle_y, float angle_x, float scale);
    ~ObjectHandler();
    void setAngle_y(float angle_y);
    void setCoordinates(float x, float y, float z);
    void drawModel();
};

#endif