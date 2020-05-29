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
    // glPushMatrix();
    // glTranslatef(this->position[0],
    //              this->position[1],
    //              this->position[2]);
    // glScalef(0.125, 0.125, 0.125);
    // this->drawHeadTrunk();
    // // right arm
    // this->drawArm(shoulderX, true);
    // // left arm
    // this->drawArm(-shoulderX, false);
    // // left leg
    // this->drawLeg(leftHipX, leftHipY, -0.5, 1, leftKnee);
    // // right leg
    // this->drawLeg(rightHipX, rightHipY, 0.5, -1, rightKnee);
    // glPopMatrix();

    // Into the stack, draw the lower right body
    glPushMatrix();

    glTranslatef(this->position[0],
                 this->position[1],
                 this->position[2]);
    glScalef(0.5, 0.5, 0.5);
    glPushMatrix();

    // Translation and rotation of the coordinate system
    glTranslatef(curDistanceX, 0.0, curDistanceZ); // go ahead
    glRotatef((GLfloat)curTurn, 0.0, 1.0, 0.0);    // turn to

    // Adjust the coordinate system to the right to locate the center of rotation
    glTranslatef(0.375, 0.0, 0.0);
    // Whether to lift the right thigh
    glRotatef((GLfloat)swingRight, 1.0, 0.0, 0.0);
    //Decrease the coordinate system and prepare to draw the right thigh
    glTranslatef(0.0, -0.5, 0.0);
    glColor3f(0.5, 0.8, 0.3);
    //Draw the right thigh
    glPushMatrix();
    glScalef(0.4, 1.0, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();

    // Decrease the coordinate system and locate the center of rotation
    glTranslatef(0.0, -0.5, 0.0);
    // Whether to raise the right calf
    glRotatef((GLfloat)legDis, 1.0, 0.0, 0.0);
    // Decrease the coordinate system and prepare to draw the right calf
    glTranslatef(0.0, -0.5, 0.0);
    glColor3f(0.1, 0.5, 0.5);
    // Draw the right calf
    glPushMatrix();
    glScalef(0.3, 1.0, 0.3);
    glutSolidCube(1.0);
    glPopMatrix();

    // Decrease the coordinate system and prepare to draw the right foot
    glTranslatef(0.0, -0.5, -0.1);
    glColor3f(0.8, 0.8, 0.2);
    // Draw the right foot
    glPushMatrix();
    glScalef(0.5, 0.1, 0.7);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
    // Unstack

    // Push into the stack, draw the lower left body
    glPushMatrix();
    // Translate and rotate the coordinate system
    glTranslatef(curDistanceX, 0.0, curDistanceZ); // forward
    glRotatef((GLfloat)curTurn, 0.0, 1.0, 0.0);    // Turn

    // The same applies to the left thigh
    glTranslatef(-0.375, 0.0, 0.0);
    glRotatef((GLfloat)swingLeft, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glColor3f(0.5, 0.8, 0.3);
    glPushMatrix();
    glScalef(0.4, 1.0, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
    // The same applies to the left calf
    glTranslatef(0.0, -0.5, 0.0);
    glRotatef((GLfloat)legDis, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glColor3f(0.1, 0.5, 0.5);
    glPushMatrix();
    glScalef(0.3, 1.0, 0.3);
    glutSolidCube(1.0);
    glPopMatrix();
    // Similarly deal with the left foot
    glTranslatef(0.0, -0.5, -0.1);
    glColor3f(0.8, 0.8, 0.2);
    glPushMatrix();
    glScalef(0.5, 0.1, 0.7);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
    // Unstack

    // Push into the stack, draw the chest and head
    glPushMatrix();
    glTranslatef(curDistanceX, 0.0, curDistanceZ);
    glRotatef((GLfloat)curTurn, 0.0, 1.0, 0.0);
    //chest
    glTranslatef(0.0, 1.0, 0.0);
    glColor3f(1.0, 0.7, 0.1);
    glPushMatrix();
    glScalef(1.4, 2.0, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();
    //head
    glTranslatef(0.0, 1.25, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    //eye
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

    //mouth
    glTranslatef(0.125, -0.25, 0.0);
    glColor3f(0.8, 0.2, 0.2);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
    // Unstack

    // Push the stack and draw the right arm
    glPushMatrix();
    glTranslatef(curDistanceX, 0.0, curDistanceZ);
    glRotatef((GLfloat)curTurn, 0.0, 1.0, 0.0);
    // right arm
    glTranslatef(0.85, 1.75, 0.0);
    glRotatef((GLfloat)swingLeft, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glColor3f(0.8, 0.4, 0.5);
    glPushMatrix();
    glScalef(0.3, 1.6, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
    // Unstack

    // Push into the stack and draw the left arm
    glPushMatrix();
    glTranslatef(curDistanceX, 0.0, curDistanceZ);
    glRotatef((GLfloat)curTurn, 0.0, 1.0, 0.0);
    // Left arm
    glTranslatef(-0.85, 1.75, 0.0);
    glRotatef((GLfloat)swingRight, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glColor3f(0.8, 0.4, 0.5);
    glPushMatrix();
    glScalef(0.3, 1.6, 0.4);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    // Unstack
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
    // glDisable(GL_TEXTURE_2D);
    glColor3f(0.2, 0.7, 0.1);
    glPushMatrix();

    glPushMatrix();
    glScalef(2.0, 4.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 4.0, 0);
    glutWireSphere(1, 8, 8);
    glPopMatrix();

    glPopMatrix();
}

void RobotBody::shoulder_up_killer()
{
    shoulderX = (shoulderX + 5) % 360;
    if (shoulderX > 70)
        shoulderX = 70;
}
void RobotBody::shoulder_down_killer()
{
    shoulderX = (shoulderX - 5) % 360;
    if (shoulderX < -90)
        shoulderX = -90;
}
void RobotBody::shoulder_up_celebration()
{
    shoulderZ = (shoulderZ + 5) % 360;
    if (shoulderZ > 70)
        shoulderZ = 70;
    glutPostRedisplay();
}
void RobotBody::shoulder_down_celebration()
{
    shoulderZ = (shoulderZ - 5) % 360;
    if (shoulderZ < -90)
        shoulderZ = -90;
    glutPostRedisplay();
}
void RobotBody::elbow_up()
{
    elbow = (elbow + 5) % 360;
    if (elbow > 130)
        elbow = 130;
    glutPostRedisplay();
}
void RobotBody::elbow_down()
{
    elbow = (elbow - 5) % 360;
    if (elbow < 0)
        elbow = 0;
    glutPostRedisplay();
}

void RobotBody::left_knee_down()
{
    leftKnee = (leftKnee + 5) % 360;
    if (leftKnee > 90)
        leftKnee = 90;
    glutPostRedisplay();
}
void RobotBody::left_knee_up()
{
    leftKnee = (leftKnee - 5) % 360;
    if (leftKnee < 0)
        leftKnee = 0;
    glutPostRedisplay();
}

void RobotBody::right_knee_down()
{
    rightKnee = (rightKnee + 5) % 360;
    if (rightKnee > 90)
        rightKnee = 90;
    glutPostRedisplay();
}
void RobotBody::right_knee_up()
{
    rightKnee = (rightKnee - 5) % 360;
    if (rightKnee < 0)
        rightKnee = 0;
    glutPostRedisplay();
}

void RobotBody::right_hip_up()
{
    if (rightHipX < 100)
        rightHipX = (rightHipX + 5) % 180;
    glutPostRedisplay();
}

void RobotBody::right_hip_down()
{
    if (rightHipX > -100)
        rightHipX = (rightHipX - 5) % 180;
    glutPostRedisplay();
}

// void RobotBody::right_hip_down()
// {
//     rightHipY = (rightHipY + 5) % 360;
//     if (rightHipY > 45)
//         rightHipY = 45;
//     glutPostRedisplay();
// }
// void RobotBody::right_hip_up()
// {
//     rightHipY = (rightHipY - 5) % 360;
//     if (rightHipY < 0)
//         rightHipY = 0;
//     glutPostRedisplay();
// }
// void RobotBody::right_hip_down2()
// {
//     rightHipX = (rightHipX + 5) % 360;
//     if (rightHipX > 90)
//         rightHipX = 90;
//     glutPostRedisplay();
// }
// void RobotBody::right_hip_up2()
// {
//     rightHipX = (rightHipX - 5) % 360;
//     if (rightHipX < 0)
//         rightHipX = 0;
//     glutPostRedisplay();
// }
// void RobotBody::left_hip_down()
// {
//     leftHipY = (leftHipY + 5) % 360;
//     if (leftHipY > 45)
//         leftHipY = 45;
//     glutPostRedisplay();
// }
// void RobotBody::left_hip_up()
// {
//     leftHipY = (leftHipY - 5) % 360;
//     if (leftHipY < 0)
//         leftHipY = 0;
//     glutPostRedisplay();
// }
// void RobotBody::left_hip_down2()
// {
//     leftHipX = (leftHipX + 5) % 360;
//     if (leftHipX > 90)
//         leftHipX = 90;
//     glutPostRedisplay();
// }
// void RobotBody::left_hip_up2()
// {
//     leftHipX = (leftHipX - 5) % 360;
//     if (leftHipX < 0)
//         leftHipX = 0;
//     glutPostRedisplay();
// }

void RobotBody::movement(void)
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
    this->displayRobotBody();
    glutPostRedisplay();
    // if (!isStand)
    //     glutTimerFunc(value, this->movement, value);
}

void RobotBody::stand()
{
    swingLeft = 0;
    swingRight = 0;
    isSwingForward = false;
    legDis = 0;
}