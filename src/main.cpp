#include "ObjectHandler.h"
#include "RobotBody.h"
#include "CameraMovement.h"
#include "imageloader.h"

#include <stdio.h>
#include <iostream>

#ifndef GL_HEADER
#define GL_HEADER
#include <GL/glut.h>
#endif

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;
const float ASPECT = float(WINDOW_WIDTH) / float(WINDOW_HEIGHT);

CameraMovement camera;
ObjectHandler laptop{"./objects/Laptop.obj", 1, 0.75, -1, 0, 0, 2};

GLfloat light_ambient[] = {0.0, 0.0, 0.0, 0.0};
GLfloat light_diffuse[] = {0.5, 0.5, 0.5, 1.0};
GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_position[] = {0.5, 5.0, 0.0, 1.0};

GLfloat lightPos1[] = {0, -5.0, 0, 1.0};
// Material Properties
GLfloat mat_amb_diff[] = {0.643, 0.753, 0.934, 1.0};
GLfloat mat_specular[] = {0.0, 0.0, 0.0, 1.0};
GLfloat shininess[] = {100.0};

RobotBody Body{0, 0, -1};
// RobotBody RobotBody2{-1, 0.75, -1, "./Objects/sword.obj", 0.6, 0, -2.5, 0, 0, 5};

void initRendering()
{
    // Turn on the power
    glEnable(GL_LIGHTING);
    // Flip light switch
    // glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    // assign light parameters
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    // Material Properties
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    GLfloat lightColor1[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor1);
    glEnable(GL_NORMALIZE);
    //Enable smooth shading
    glShadeModel(GL_SMOOTH);
    // Enable Depth buffer
    glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'd':
        camera.cameraRight();
        glutPostRedisplay();
        break;
    case 'w':
        camera.cameraForward();
        glutPostRedisplay();
        break;
    case 's':
        camera.cameraBackward();
        glutPostRedisplay();
        break;
    case 'a':
        camera.cameraLeft();
        glutPostRedisplay();
        break;

    default:
        break;
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera.initializeCamera();
    glPushMatrix();
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glPopMatrix();
    //materials properties
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glPushMatrix();
    // RobotBody2.display_body();

    glPushMatrix();
    Body.display_body();
    glPopMatrix();

    laptop.drawModel();

    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("ROOM");
    initRendering();

    glMatrixMode(GL_PROJECTION);
    gluPerspective(90.0, ASPECT, 0.1, 60.0);

    glutKeyboardFunc(keyboard);

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
