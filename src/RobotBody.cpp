#include "RobotBody.h"

RobotBody::RobotBody(double x, double y, double z)
{
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}

RobotBody::RobotBody(double x, double y, double z, std::string objectName, float object_x, float object_y, float object_z, float angle_y, float angle_x, float scale)
{
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
    this->obj = new ObjectHandler(objectName, object_x, object_y, object_z, angle_y, angle_x, scale);
}

void RobotBody::displayRobotBody()
{
    glPushMatrix();
    glTranslatef(this->position[0],
                 this->position[1],
                 this->position[2]);
    glScalef(0.125, 0.125, 0.125);
    this->drawHeadTrunk();
    // right arm
    this->drawArm(shoulderX, true);
    // left arm
    this->drawArm(-shoulderX, false);
    // left leg
    this->drawLeg(leftHipX, leftHipY, -0.5, 1, leftKnee);
    // right leg
    this->drawLeg(rightHipX, rightHipY, 0.5, -1, rightKnee);
    glPopMatrix();
}

void RobotBody::drawArm(int angle, bool isRight)
{
    glPushMatrix();
    if (isRight)
    {
        glRotatef(180, 0, 1, 0);
    }
    else
    {
        glRotatef(0, 0, 1, 0);
    }
    glTranslatef(1.0, 2.0, 0.0);
    glRotatef((GLfloat)angle, 1, 0, 0);
    glRotatef((GLfloat)shoulderZ, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    if (this->obj && isRight)
    {
        obj->drawModel();
    }

    // Finger 1
    glTranslatef(1.0, -0.25, 0.0);
    glRotatef((GLfloat)handBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)handUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();

    // Finger 2
    glTranslatef(1.0, 0.25, 0.2);
    glRotatef((GLfloat)-1 * handBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-1 * handUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();

    // Finger 3
    glTranslatef(1.0, 0.25, -0.2);
    glRotatef((GLfloat)-1 * handBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-1 * handUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();

    // Finger 4
    glTranslatef(1.0, 0.25, -0.4);
    glRotatef((GLfloat)-1 * handBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-1 * handUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();

    // Finger 5
    glTranslatef(1.0, 0.25, 0.4);
    glRotatef((GLfloat)-1 * handBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-1 * handUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();
}

void RobotBody::drawLeg(int hipAngleX, int hipAngleY, float translateX, int rotationAxis, int kneeAngle)
{
    glPushMatrix();
    glTranslatef(translateX, -4, 0);
    glTranslatef(0, 2, 0);
    glRotatef(hipAngleY, 0, rotationAxis, 0);
    glRotatef(hipAngleX, 1, 0, 0);
    glTranslatef(0, -2, 0);

    glPushMatrix();
    glScalef(1, 4, 1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(0, -2, 0);
    glRotatef(leftKnee, -1, 0, 0);
    glTranslatef(0, -1, 0);
    glScalef(1, 2, 1);
    glutWireCube(1);

    glPopMatrix();
}

void RobotBody::drawHeadTrunk(void)
{
    glPushMatrix();
    glScalef(2.0, 4.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 4.0, 0);
    glutWireSphere(1, 8, 8);
    glPopMatrix();
}