#ifndef BODY_INCLUDED
#define BODY_INCLUDED

#ifndef MATH_HEADER
#define MATH_HEADER
#include <math.h>
#endif

#ifndef GL_HEADER
#define GL_HEADER
#include <GL/glut.h>
#endif
#include "ObjectHandler.h"

class RobotBody
{
private:
    // TODO change in private block and variable names
    double position[3] = {0, 0, 0};
    int shoulderX = 0, shoulderZ = -90, elbow = 0, handBase = 0,
        handUp = 0, rightHipY = 0, rightHipX = 0, leftHipY = 0, leftHipX = 0, leftKnee = 0, rightKnee = 0;
    ObjectHandler *obj;
    /******************************** RobotBody Parts ********************************/
    void drawArm(int, bool);
    void drawLeg(int, int, float, int, int);
    void drawHeadTrunk();
    /****************************** End RobotBody Parts ******************************/

public:
    /***************************** Constructors *********************************/
    RobotBody(double x, double y, double z);
    RobotBody(double x,
              double y,
              double z,
              std::string objectPath,
              float object_x,
              float object_y,
              float object_z,
              float angle_y,
              float angle_x,
              float scale);
    /**************************** End Constructors ******************************/
    // Display
    void displayRobotBody();

    /******************************** Body Parts Movements ********************************/
    // Shoulder
    void shoulder_up_killer();
    void shoulder_up_celebration();
    void shoulder_down_killer();
    void shoulder_down_celebration();
    // Elbow
    void elbow_up();
    void elbow_down();
    // Knee
    void left_knee_up();
    void left_knee_down();
    void right_knee_up();
    void right_knee_down();
    /****************************** End Body Parts Movements ******************************/
};

#endif