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
    this->drawLowerBody(0.375, swingRight, rknee);
    // draw left lower body
    this->drawLowerBody(-0.375, swingLeft, lknee);
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
    // glRotatef((GLfloat)shoulder_celebration, 0.0, 0.0, 1.0);
    if (!isRight)
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

void RobotBody::drawLowerBody(float t, int angle, int celebration_angle)
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
    // glRotatef(celebration_angle, -1, 0, 0);
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

void RobotBody::walking()
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
    // glutPostRedisplay();
}

void RobotBody::shoulder_up()
{
    shoulder_attack = (shoulder_attack + 5) % 360;
    if (shoulder_attack > 70)
        shoulder_attack = 70;
}
void RobotBody::shoulder_down()
{
    shoulder_attack = (shoulder_attack - 5) % 360;
    if (shoulder_attack < -90)
        shoulder_attack = -90;
}

void RobotBody::celebration()
{
    // left knee down
    lknee = (lknee + 5) % 360;
    if (lknee > 90)
        lknee = 90;
    // right knee down
    rknee = (rknee + 5) % 360;
    if (rknee > 90)
        rknee = 90;

    // shoulder up
    shoulder_celebration = (shoulder_celebration + 5) % 360;
    if (shoulder_celebration > 70)
        shoulder_celebration = 70;

    // // elbow down
    // elbow = (elbow + 5) % 360;
    // if (elbow > 130)
    //     elbow = 130;
    glutPostRedisplay();
}

void RobotBody::celebration2()
{
    lknee = (lknee - 5) % 360;
    if (lknee < 0)
        lknee = 0;

    rknee = (rknee - 5) % 360;
    if (rknee < 0)
        rknee = 0;

    shoulder_celebration = (shoulder_celebration - 5) % 360;
    if (shoulder_celebration < -90)
        shoulder_celebration = -90;

    // elbow = (elbow - 5) % 360;
    // if (elbow < 0)
    //     elbow = 0;
    glutPostRedisplay();
}

// void timer(int value)
// {
//     // value %= 80;
//     int tempTurn = body.curTurn;
//     body.curDistanceX = body.curDistanceX - body.speed * sin((GLfloat)tempTurn / 360 * 3.14 * 2);
//     body.curDistanceZ = body.curDistanceZ - body.speed * cos((GLfloat)tempTurn / 360 * 3.14 * 2);
//     if (!body.isSwingForward)
//     {
//         body.swingLeft = (body.swingLeft + body.stepDis);
//         body.swingRight = (body.swingRight - body.stepDis);
//         if (body.swingLeft > 0)
//         {
//             body.legDis = body.legDis - body.stepDis * 1.2;
//         }
//         else
//         {
//             body.legDis = body.legDis + body.stepDis * 1.2;
//         }
//     }
//     else
//     {
//         body.swingLeft = (body.swingLeft - body.stepDis);
//         body.swingRight = (body.swingRight + body.stepDis);
//         if (body.swingLeft < 0)
//         {
//             body.legDis = body.legDis - body.stepDis * 1.2;
//         }
//         else
//         {
//             body.legDis = body.legDis + body.stepDis * 1.2;
//         }
//     }
//     if (body.swingLeft > body.maxAngel)
//     {
//         body.isSwingForward = true;
//     }
//     if (body.swingLeft < body.maxAngel * -1)
//     {
//         body.isSwingForward = false;
//     }
//     body.displayRobotBody();
//     glutPostRedisplay();
//     if (!body.isStand)
//         glutTimerFunc(value, timer, value);
//     // glutTimerFunc(20, timer, ++value);
// }
