#include "RobotBody.h"

RobotBody::RobotBody()
{
}

RobotBody::RobotBody(double x, double y, double z)
{
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}

RobotBody::RobotBody(double x, double y, double z, char *objectName, float object_x, float object_y, float object_z, float angle_y, float angle_x, float scale)
{
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
    this->object = new ObjectHandler(objectName, object_x, object_y, object_z, angle_y, angle_x, scale);
}

RobotBody::~RobotBody()
{
}

void draw_head_trunk(void)
{
    glPushMatrix();
    glTranslatef(0, 4, 0);
    glScalef(1, 1.5, 1);
    glutWireSphere(1, 10, 10);
    glPopMatrix();
    glScalef(1.5, 2, 1);
    glutWireCube(2.5);
}

void draw_arm(float shoulder_t1, float shoulder_t2, float elbow_t1, float elbow_t2,
              float finger_t1, float finger_t2, float finger_t3, float finger_t4,
              float shoulder_angle_z, float shoulder_angle_x, float shoulder_angle_y, float elbow_angle, float fingerBase, float fingerUp)
{
    // Draw shoulder
    glPushMatrix();
    glTranslatef(shoulder_t1, 1, 0);
    glRotatef(shoulder_angle_z, 0, 0, 1);
    glRotatef(shoulder_angle_x, 1, 0, 0);
    glRotatef(shoulder_angle_y, 0, 1, 0);
    glTranslatef(shoulder_t2, 0, 0);
    glPushMatrix();
    glScalef(1.5, 0.3, 1);
    glutWireCube(1);
    glPopMatrix();

    // Draw elbow
    glTranslatef(elbow_t1, 0, 0);
    glRotatef(elbow_angle, 0, 0, 1);
    glTranslatef(elbow_t2, 0, 0);
    glPushMatrix();
    glScalef(1.5, 0.3, 1);
    glutWireCube(1);
    glPopMatrix();
    glPushMatrix();
    glPushMatrix();
    glPushMatrix();
    glPushMatrix();

    // First finger
    glTranslatef(finger_t1, 0.1, -0.2);
    glRotatef(fingerBase, 0, 0, 1);
    glTranslatef(finger_t2, 0, 0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(finger_t3, 0, 0);
    glRotatef(fingerUp, 0, 0, 1);
    glTranslatef(finger_t4, 0, 0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(0.8);
    glPopMatrix();

    // Second Finger
    glPopMatrix();
    glTranslatef(finger_t1, 0.1, 0.05);
    glRotatef(fingerBase, 0, 0, 1);
    glTranslatef(finger_t2, 0, 0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(finger_t3, 0, 0);
    glRotatef(fingerUp, 0, 0, 1);
    glTranslatef(finger_t4, 0, 0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(0.8);
    glPopMatrix();

    // Third Finger
    glPopMatrix();
    glTranslatef(finger_t1, 0.1, 0.2);
    glRotatef(fingerBase, 0, 0, 1);
    glTranslatef(finger_t2, 0, 0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(finger_t3, 0, 0);
    glRotatef(fingerUp, 0, 0, 1);
    glTranslatef(finger_t4, 0, 0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(0.8);
    glPopMatrix();

    // Fourth finger
    glPopMatrix();
    glTranslatef(finger_t1, 0.1, 0.35);
    glRotatef(fingerBase, 0, 0, 1);
    glTranslatef(finger_t2, 0, 0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(finger_t3, 0, 0);
    glRotatef(fingerUp, 0, 0, 1);
    glTranslatef(finger_t4, 0, 0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(0.8);
    glPopMatrix();

    // Fourth finger
    glPopMatrix();
    glTranslatef(finger_t1, 0.1, 0.45);
    glRotatef(fingerBase, 0, 0, 1);
    glTranslatef(finger_t2, 0, 0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(finger_t3, 0, 0);
    glRotatef(fingerUp, 0, 0, 1);
    glTranslatef(finger_t4, 0, 0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(0.8);
    glPopMatrix();

    // glPopMatrix();
    glPopMatrix();
}

void draw_leg(float t, float hip_angle_x, float hip_angle_z, float knee_angle)
{
    glPushMatrix();
    glTranslatef(t, -1, 0);
    glRotatef(hip_angle_x, 1, 0, 0);
    glRotatef(hip_angle_z, 0, 0, 1);
    glTranslatef(0, -1, 0);

    glPushMatrix();
    glScalef(0.5, 1.5, 1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(0, -0.75, 0);
    glRotatef(knee_angle, 1, 0, 0);
    glTranslatef(0, -0.75, 0);
    glPushMatrix();
    glScalef(0.5, 1.5, 1);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(0, -1, 0);
    glPushMatrix();
    glScalef(1, 0.5, 2.5);
    glutWireCube(0.75);
    glPopMatrix();
    glPopMatrix();
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void RobotBody::display_body(void)
{
    // glClear(GL_COLOR_BUFFER_BIT); // Clear color
    // glShadeModel(GL_FLAT);        // Enable flat shading
    // glMatrixMode(GL_MODELVIEW);   // To operate on model-view matrix
    // glLoadIdentity();             // Reset the model-view matrix
    glPushMatrix();
    glTranslatef(this->position[0],
                 this->position[1],
                 this->position[2]);
    glScalef(0.125, 0.125, 0.125);
    this->draw_head_trunk();
    // draw right leg
    this->draw_leg(1, hip_right_x, hip_right_z, knee_right);
    // draw left leg
    this->draw_leg(-1, hip_left_x, hip_left_z, knee_left);
    // draw right arm
    this->draw_arm(-1.5, -1.0, -0.75, -0.75, -0.65, -0.25, -0.2, -0.1, shoulder_right_z, shoulder_right_x, shoulder_right_y, elbow_right, fingerBase_right, fingerUp_right);
    // draw left arm
    this->draw_arm(1.5, 1.0, 0.75, 0.75, 0.65, 0.25, 0.2, 0.1, shoulder_left_z, shoulder_left_x, shoulder_left_y, elbow_left, fingerBase_left, fingerUp_left);
    // glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
    glPopMatrix();
}
