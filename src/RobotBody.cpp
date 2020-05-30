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
    // Into the stack
    glPushMatrix();
    glTranslatef(this->position[0],
                 this->position[1],
                 this->position[2]);
    glScalef(0.5, 0.5, 0.5);
    // draw right lower body
    this->drawLowerBody(0.375, swingRight);
    // draw left lower body
    this->drawLowerBody(-0.375, swingLeft);
    // draw the chest and head
    this->drawHeadTrunk();
    // draw the right arm
    this->drawArm(swingLeft, 0.85, true);
    // draw the left arm
    this->drawArm(swingRight, -0.85, false);
    // Unstack
    glPopMatrix();
}

void RobotBody::drawArm(int angle, float t, bool isRight)
{
    // Push the stack and draw the arm
    glPushMatrix();
    glTranslatef(curDistanceX, 0.0, curDistanceZ);
    glRotatef((GLfloat)curTurn, 0.0, 1.0, 0.0);
    glTranslatef(t, 1.75, 0.0);
    glRotatef((GLfloat)angle, 1.0, 0.0, 0.0);
    if (!isRight && isStand)
        glRotatef((GLfloat)shoulder_attack, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glColor3f(0.8, 0.4, 0.5);
    glPushMatrix();
    glScalef(0.3, 1.6, 0.4);
    glutSolidCube(1.0);
    glPushMatrix();
    if (this->obj && !isRight)
    {
        obj->drawModel();
    }
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    // Unstack
}

void RobotBody::drawLowerBody(float t, int angle)
{
    // Push into the stack
    glPushMatrix();
    glTranslatef(curDistanceX, 0.0, curDistanceZ);
    glRotatef((GLfloat)curTurn, 0.0, 1.0, 0.0);

    // Thigh
    glTranslatef(t, 0.0, 0.0);
    glRotatef((GLfloat)angle, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glColor3f(0.5, 0.8, 0.3);
    glPushMatrix();
    glScalef(0.4, 1.0, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();

    // Calf
    glTranslatef(0.0, -0.5, 0.0);
    glRotatef((GLfloat)legDis, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glColor3f(0.1, 0.5, 0.5);
    glPushMatrix();
    glScalef(0.3, 1.0, 0.3);
    glutSolidCube(1.0);
    glPopMatrix();

    // Foot
    glTranslatef(0.0, -0.5, -0.1);
    glColor3f(0.8, 0.8, 0.2);
    glPushMatrix();
    glScalef(0.5, 0.1, 0.7);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
    // Unstack
}

void RobotBody::drawHeadTrunk(void)
{
    // Push into the stack, draw the chest and head
    glPushMatrix();
    glTranslatef(curDistanceX, 0.0, curDistanceZ);
    glRotatef((GLfloat)curTurn, 0.0, 1.0, 0.0);

    // Chest
    glTranslatef(0.0, 1.0, 0.0);
    glColor3f(1.0, 0.7, 0.1);
    glPushMatrix();
    glScalef(1.4, 2.0, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // Head
    glTranslatef(0.0, 1.25, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // Eye
    glTranslatef(0.125, 0.1, -0.25);
    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glTranslatef(-0.25, 0.0, 0.0);
    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Mouth
    glTranslatef(0.125, -0.25, 0.0);
    glColor3f(0.8, 0.2, 0.2);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
    // Unstack
}

void RobotBody::stand()
{
    swingLeft = 0;
    swingRight = 0;
    isSwingForward = false;
    legDis = 0;
}

void RobotBody::walk()
{
    int tempTurn = curTurn;
    curDistanceX = curDistanceX - speed * sin((GLfloat)tempTurn / 360 * 3.14 * 2);
    curDistanceZ = curDistanceZ - speed * cos((GLfloat)tempTurn / 360 * 3.14 * 2);
    if (!isSwingForward)
    {
        swingLeft = (swingLeft + stepDis);
        swingRight = (swingRight - stepDis);
        if (swingLeft > 0)
        {
            legDis = legDis - stepDis * 1.2;
        }
        else
        {
            legDis = legDis + stepDis * 1.2;
        }
    }
    else
    {
        swingLeft = (swingLeft - stepDis);
        swingRight = (swingRight + stepDis);
        if (swingLeft < 0)
        {
            legDis = legDis - stepDis * 1.2;
        }
        else
        {
            legDis = legDis + stepDis * 1.2;
        }
    }
    if (swingLeft > maxAngel)
    {
        isSwingForward = true;
    }
    if (swingLeft < maxAngel * -1)
    {
        isSwingForward = false;
    }
    // displayRobotBody();
    glutPostRedisplay();
}

void RobotBody::shoulder_up()
{
    shoulder_attack = (shoulder_attack + 5) % 360;
    if (shoulder_attack > 20)
        shoulder_attack = 20;
}
void RobotBody::shoulder_down()
{
    shoulder_attack = (shoulder_attack - 5) % 360;
    if (shoulder_attack < 0)
        shoulder_attack = 0;
}