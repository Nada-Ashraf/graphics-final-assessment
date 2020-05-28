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
    int shoulder = 0, shoulder2 = -90, elbow = 0, handBase = 0,
        handUp = 0, rightHipY = 0, rightHipX = 0, rknee = 0, lknee = 0, leftHipY = 0, leftHipX = 0;
    ObjectHandler *obj;
    /******************************** RobotBody Parts ********************************/
    void drawArm(int, bool);
    void drawLeg(int, int, float, int);
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
};

#endif