#include <GL/glut.h>
#include <math.h>

/* Global variables */
static int shoulder_right_z = 0, shoulder_left_z = 0, elbow_right = 0, elbow_left = 0,
           fingerBase_right = 0, fingerUp_right = 0, fingerBase_left = 0, fingerUp_left = 0,
           hip_right_x = 0, knee_right = 0, knee_left = 0, hip_left_x = 0, full_body_angle = 0,
           hip_right_z = 0, hip_left_z, shoulder_right_x = 0, shoulder_left_x = 0, shoulder_right_y = 0, shoulder_left_y = 0;

/* Initialize OpenGL Graphics */
void init(void)
{
    glClearColor(0.3, 0.5, 0.6, 0.0); // Set background color
    glMatrixMode(GL_PROJECTION);      // To operate on projection matrix
    gluPerspective(65.0, (GLfloat)1024 / (GLfloat)869, 1.0, 60.0);
}

void draw_head_trunk(void)
{

    glTranslatef(-3, -3, -3);
    glRotatef(full_body_angle, 0, 1, 0);
    glTranslatef(3.0, 3, 3);

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
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear color
    glShadeModel(GL_FLAT);        // Enable flat shading
    glMatrixMode(GL_MODELVIEW);   // To operate on model-view matrix
    glLoadIdentity();             // Reset the model-view matrix
    gluLookAt(0, 0, -20, 0, 0, 1, 0, 1, 0);
    draw_head_trunk();
    // draw right leg
    draw_leg(1, hip_right_x, hip_right_z, knee_right);
    // draw left leg
    draw_leg(-1, hip_left_x, hip_left_z, knee_left);
    // draw right arm
    draw_arm(-1.5, -1.0, -0.75, -0.75, -0.65, -0.25, -0.2, -0.1, shoulder_right_z, shoulder_right_x, shoulder_right_y, elbow_right, fingerBase_right, fingerUp_right);
    // draw left arm
    draw_arm(1.5, 1.0, 0.75, 0.75, 0.65, 0.25, 0.2, 0.1, shoulder_left_z, shoulder_left_x, shoulder_left_y, elbow_left, fingerBase_left, fingerUp_left);
    glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
}

/* Handler for kayboard events. */
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        if (shoulder_right_z < 100)
            shoulder_right_z = (shoulder_right_z + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S':
        if (shoulder_right_z > -100)
            shoulder_right_z = (shoulder_right_z - 5) % 360;
        glutPostRedisplay();
        break;
    case 'A':
        if (shoulder_left_z < 100)
            shoulder_left_z = (shoulder_left_z + 5) % 360;
        glutPostRedisplay();
        break;
    case 'a':
        if (shoulder_left_z < -100)
            shoulder_left_z = (shoulder_left_z - 5) % 360;
        glutPostRedisplay();
        break;
    case 'i':
        if (shoulder_left_x < 100)
            shoulder_left_x = (shoulder_left_x + 5) % 360;
        glutPostRedisplay();
        break;
    case 'I':
        if (shoulder_left_x > -100)
            shoulder_left_x = (shoulder_left_x - 5) % 360;
        glutPostRedisplay();
        break;
    case 'j':
        if (shoulder_right_x < 100)
            shoulder_right_x = (shoulder_right_x + 5) % 360;
        glutPostRedisplay();
        break;
    case 'J':
        if (shoulder_right_x > -100)
            shoulder_right_x = (shoulder_right_x - 5) % 360;
        glutPostRedisplay();
        break;
    case 'e':
        if (elbow_right < 150)
            elbow_right = (elbow_right + 5) % 360;
        glutPostRedisplay();
        break;
    case 'E':
        if (elbow_right > -150)
            elbow_right = (elbow_right - 5) % 360;
        glutPostRedisplay();
        break;
    case 'C':
        if (elbow_left < 150)
            elbow_left = (elbow_left + 5) % 360;
        glutPostRedisplay();
        break;
    case 'c':
        if (elbow_left > -150)
            elbow_left = (elbow_left - 5) % 360;
        glutPostRedisplay();
        break;
    case 'f':
        if (fingerBase_right < 90)
            fingerBase_right = (fingerBase_right + 5) % 360;
        glutPostRedisplay();
        break;
    case 'F':
        if (fingerBase_right > 0)
            fingerBase_right = (fingerBase_right - 5) % 360;
        glutPostRedisplay();
        break;
    case 'g':
        if (fingerUp_right < 90)
            fingerUp_right = (fingerUp_right + 5) % 360;
        glutPostRedisplay();
        break;
    case 'G':
        if (fingerUp_right > 0)
            fingerUp_right = (fingerUp_right - 5) % 360;
        glutPostRedisplay();
        break;
    case 'H':
        if (fingerBase_left < 0)
            fingerBase_left = (fingerBase_left + 5) % 360;
        glutPostRedisplay();
        break;
    case 'h':
        if (fingerBase_left > -90)
            fingerBase_left = (fingerBase_left - 5) % 360;
        glutPostRedisplay();
        break;
    case 'O':
        if (fingerUp_left < 0)
            fingerUp_left = (fingerUp_left + 5) % 360;
        glutPostRedisplay();
        break;
    case 'o':
        if (fingerUp_left > -90)
            fingerUp_left = (fingerUp_left - 5) % 360;
        glutPostRedisplay();
        break;
    case 'q':
        if (hip_right_x < 100)
            hip_right_x = (hip_right_x + 5) % 180;
        glutPostRedisplay();
        break;
    case 'Q':
        if (hip_right_x > -100)
            hip_right_x = (hip_right_x - 5) % 180;
        glutPostRedisplay();
        break;
    case 'r':
        if (hip_left_x < 100)
            hip_left_x = (hip_left_x + 5) % 360;
        glutPostRedisplay();
        break;
    case 'R':
        if (hip_left_x > -100)
            hip_left_x = (hip_left_x - 5) % 360;
        glutPostRedisplay();
        break;
    case 'p':
        if (hip_left_z < 30)
            hip_left_z = (hip_left_z + 5) % 360;
        glutPostRedisplay();
        break;
    case 'P':
        if (hip_left_z > -30)
            hip_left_z = (hip_left_z - 5) % 360;
        glutPostRedisplay();
        break;
    case 'x':
        if (hip_right_z < 30)
            hip_right_z = (hip_right_z + 5) % 360;
        glutPostRedisplay();
        break;
    case 'X':
        if (hip_right_z > -30)
            hip_right_z = (hip_right_z - 5) % 360;
        glutPostRedisplay();
        break;
    case 'W':
        if (knee_right < 0)
            knee_right = (knee_right + 5) % 360;
        glutPostRedisplay();
        break;
    case 'w':
        if (knee_right > -120)
            knee_right = (knee_right - 5) % 360;
        glutPostRedisplay();
        break;
    case 'T':
        if (knee_left < 0)
            knee_left = (knee_left + 5) % 360;
        glutPostRedisplay();
        break;
    case 't':
        if (knee_left > -120)
            knee_left = (knee_left - 5) % 360;
        glutPostRedisplay();
        break;
    case 'B':
        if (full_body_angle < 0)
            full_body_angle = (full_body_angle + 5) % 360;
        glutPostRedisplay();
        break;
    case 'b':
        if (full_body_angle > -360)
            full_body_angle = (full_body_angle - 5) % 360;
        glutPostRedisplay();
        break;
    case 'm':
        if (shoulder_left_y < 100)
            shoulder_left_y = (shoulder_left_y + 5) % 360;
        glutPostRedisplay();
        break;
    case 'M':
        if (shoulder_left_y > -100)
            shoulder_left_y = (shoulder_left_y - 5) % 360;
        glutPostRedisplay();
        break;
    case 'N':
        if (shoulder_right_y < 100)
            shoulder_right_y = (shoulder_right_y + 5) % 360;
        glutPostRedisplay();
        break;
    case 'n':
        if (shoulder_right_y > -100)
            shoulder_right_y = (shoulder_right_y - 5) % 360;
        glutPostRedisplay();
        break;

    default:
        break;
    }
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Enable double buffered mode and GLUT_RGB
    glutInitWindowSize(1000, 1000);              // Set the window's initial width & height
    glutInitWindowPosition(100, 100);            // Position the window's initial top-left corner
    glutCreateWindow("Robot body");              // Create window with the given title
    init();                                      // Our own OpenGL initialization
    glutDisplayFunc(display);                    // Register callback handler for window re-paint event
    glutKeyboardFunc(keyboard);                  // Sets the keyboard callback for the current window.
    glutMainLoop();                              // Enter the infinite event-processing loop
    return 0;
}