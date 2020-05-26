#include "ObjectHandler.h"

void ObjectHandler::drawModel(void)
{
    glPushMatrix();
    glmUnitize(pmodel);
    glmFacetNormals(pmodel);
    glmVertexNormals(pmodel, 90.0);
    glTranslatef(x, y, z);
    glRotatef(angle_y, 0, 1, 0);
    glRotatef(angle_x, 1, 0, 0);
    glmScale(pmodel, scale);
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

ObjectHandler::ObjectHandler(char *objectName, float x, float y, float z, float angle_y, float angle_x, float scale)
{
    pmodel = glmReadOBJ(objectName);
    this->x = x;
    this->y = y;
    this->z = z;
    this->angle_y = angle_y;
    this->angle_x = angle_x;
    this->scale = scale;
}

ObjectHandler::~ObjectHandler()
{
    delete pmodel;
}

void ObjectHandler::setAngle_y(float angle_y)
{
    this->angle_y = angle_y;
}

void ObjectHandler::setCoordinates(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}