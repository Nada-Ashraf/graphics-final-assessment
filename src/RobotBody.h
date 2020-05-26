
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
    int shoulder_right_z = 0, shoulder_left_z = 0, elbow_right = 0, elbow_left = 0,
        fingerBase_right = 0, fingerUp_right = 0, fingerBase_left = 0, fingerUp_left = 0,
        hip_right_x = 0, knee_right = 0, knee_left = 0, hip_left_x = 0, full_body_angle = 0,
        hip_right_z = 0, hip_left_z, shoulder_right_x = 0, shoulder_left_x = 0, shoulder_right_y = 0, shoulder_left_y = 0;
    double position[3] = {0, 0, 0};
    ObjectHandler *object;
    void draw_head_trunk(void);
    void draw_arm(float shoulder_t1, float shoulder_t2, float elbow_t1, float elbow_t2,
                  float finger_t1, float finger_t2, float finger_t3, float finger_t4,
                  float shoulder_angle_z, float shoulder_angle_x, float shoulder_angle_y, float elbow_angle, float fingerBase, float fingerUp);
    void draw_leg(float t, float hip_angle_x, float hip_angle_z, float knee_angle);

public:
    RobotBody();
    RobotBody(double x, double y, double z);
    RobotBody(double x, double y, double z, char *objectName, float object_x, float object_y, float object_z, float angle_y, float angle_x, float scale);
    ~RobotBody();
    void display_body();

    // keyboard events
};

#endif