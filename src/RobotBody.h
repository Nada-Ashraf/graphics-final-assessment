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
    ObjectHandler *obj;
    /******************************** RobotBody Parts ********************************/
    void drawArm(int, float, bool);
    void drawLowerBody(float, int, int);
    void drawHeadTrunk();
    int shoulder_attack = 0;
    /****************************** End RobotBody Parts ******************************/

public:
    int shoulder_celebration = 0;
    int lknee = 0;
    int rknee = 0;
    int swingLeft = 0;
    int swingRight = 0;
    bool isSwingForward = false;
    bool isLighting = false;
    int curTurn = 180; // current facing angle
    int maxAngel = 0;  // Maximum swing angle
    int stepDis = 0;   // Thigh swing speed
    float speed = 0;   // forward speed
    bool isStand = true;
    float curDistanceX = 0, curDistanceZ = 0; // current distance
    float legDis = 0;

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
    // helper function
    void stand();
    void walking();
    void shoulder_up();
    void shoulder_down();
    void celebration();
    void celebration2();
};

#endif