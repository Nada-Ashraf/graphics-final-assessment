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
    int curw;
    int curh;
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
    void stand();

    /******************************** Body Parts Movements ********************************/
    // Shoulder
    void shoulder_up_killer();
    void shoulder_up_celebration();
    void shoulder_down_killer();
    void shoulder_down_celebration();

    // Elbow
    void elbow_up();
    void elbow_down();

    // Hip
    void right_hip_up();
    void right_hip_up2();
    void right_hip_down();
    void right_hip_down2();
    void left_hip_up();
    void left_hip_up2();
    void left_hip_down();
    void left_hip_down2();

    // Knee
    void left_knee_up();
    void left_knee_down();
    void right_knee_up();
    void right_knee_down();

    void movement(void);
    /****************************** End Body Parts Movements ******************************/
};

#endif