#include "imageloader.h"
#include "ObjectHandler.h"
#include "RobotBody.h"
#include "Camera.h"
#include "Surface.h"
#include <stdio.h>
#include <iostream>

/************************************* Window *************************************/
const int WINDOW_WIDTH = 2000;
const int WINDOW_HEIGHT = 1000;
const float WINDOW_RATIO = ((float)WINDOW_WIDTH) / WINDOW_HEIGHT;
/*********************************** End Window ***********************************/

/************************************* Paths *************************************/
/* Objects */
std::string drumPath = "./Objects/drum.obj";
std::string manPath = "./Objects/al.obj";
std::string gunPath = "./Objects/ACR.obj";
std::string planePath = "./Objects/f-16.obj";

/* Textures */
std::string grayTexturePath = "./Textures/gray.bmp";
std::string patternTexturePath = "./Textures/pattern.bmp";
std::string metalTexturePath = "./Textures/metal.bmp";
std::string greenBronzeTexturePath = "./Textures/Liberty-GreenBronze-1.bmp";
std::string grassTexturePath = "./Textures/grass.bmp";
std::string mattoniBasamentoTexturePath = "./Textures/Liberty-MattoniBasamento-1.bmp";

/************************************ End Paths ***********************************/

/************************************ Properties **********************************/
/* Material Properties */
GLfloat materialShin[] = {100.0},
        materialSpec[] = {0.0, 0.0, 0.0, 1.0},
        materialDiff[] = {0.643, 0.753, 0.934, 1.0};

/* Light Properties */
GLfloat lightPos[] = {0, -5.0, 0, 1.0},
        lightColor[] = {1.0f, 1.0f, 1.0f, 1.0f};

/********************************** End Properties *********************************/
float manAngle = 0;
bool kill = false;
Camera cam;
/************************************* Surfaces *************************************/
// floor
Surface floorSurface = Surface({-2, -0.25, 2, 2, -0.25, 2, 2, -0.25, -2, -2, -0.25, -2});
// walls
Surface firstWall = Surface({-2, -0.25, 2, -2, -0.25, -2, -2, 2, -2, -2, 2, 2});
Surface secondWall = Surface({2, -0.25, 2, 2, -0.25, -2, 2, 2, -2, 2, 2, 2});
Surface thirdWall = Surface({2, -0.25, -2, -2, -0.25, -2, -2, 2, -2, 2, 2, -2});

/*********************************** End Surfaces ************************************/

/******************************** Objects and bodies **********************************/
RobotBody body = RobotBody(-1, 0.8, -1, gunPath, 0.1, -0.55, -1.6, 0, 0, 1.0);
ObjectHandler drumObject = ObjectHandler(drumPath, 1, 0.45, -0.8, 180, 0, 0.7);
ObjectHandler manObject = ObjectHandler(manPath, 0.2, 0.4, 1.0, 0, 0, 0.7);
ObjectHandler plane = ObjectHandler(planePath, 1, 5, -1, 0, 0, 2);

/*********************************** End Objects ***********************************/

/******************************* Functions Declerations ****************************/
void walking_timer(int value);
void display();
void kill_timer(int x);
void intialization();
void choose_floor_menu(int key);
void change_floor_to(std::string newFloorPath);
void keyboard_control(unsigned char key, int x, int y);
/**************************** End Functions Declerations ***************************/

/******************************* Functions Definations ****************************/
void walking_timer(int value)
{
    body.walk();
    if (!body.isStand)
        glutTimerFunc(value, walking_timer, value);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Initialize camera
    cam.initialize();
    // Materials properties
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, materialShin);

    // Color Properties
    GLfloat specref[] = {1.0f, 1.0f, 0.3f, 0.1f};
    glEnable(GL_COLOR_MATERIAL);

    // Display robot
    glPushMatrix();
    body.displayRobotBody();
    glPopMatrix();

    // Display surfaces
    floorSurface.display_surface();
    firstWall.display_surface();
    secondWall.display_surface();
    thirdWall.display_surface();

    // Display drum object
    drumObject.drawModel();

    // Display plane object
    // plane.drawModel();

    // Display alcapone
    // glPushMatrix();
    glRotatef(manAngle, 0, 0, 1);
    manObject.drawModel();
    // glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void kill_timer(int x)
{
    if (kill)
    {
        if (x == 80)
            return;
        if (x >= 40 && x < 60)
        {
            if (manAngle < 100)
                manAngle += 5;
        }
        else if (x >= 60 && x < 80)
            manAngle -= 5;
        else if (x < 20)
            body.shoulder_up();
        else if (x < 40)
            body.shoulder_down();
        glutPostRedisplay();
        glutTimerFunc(50, kill_timer, ++x);
    }
}

void intialization()
{
    // window intialization
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Kill al capone");

    // Set Textures
    floorSurface.change_texture(greenBronzeTexturePath.c_str());
    firstWall.change_texture(mattoniBasamentoTexturePath.c_str());
    secondWall.change_texture(mattoniBasamentoTexturePath.c_str());
    thirdWall.change_texture(mattoniBasamentoTexturePath.c_str());

    glEnable(GL_COLOR_MATERIAL);

    // Light Properties
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos);

    // Properties
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(90.0, WINDOW_RATIO, 0.1, 60.0);

    // Display
    glutDisplayFunc(display);

    // Keyboard
    glutKeyboardFunc(keyboard_control);

    // Menu
    glutCreateMenu(choose_floor_menu);
    glutAddMenuEntry("Choose Floor", 0);
    glutAddMenuEntry("------------", 0);
    glutAddMenuEntry("Pattern", 'c');
    glutAddMenuEntry("Grass", 'g');
    glutAddMenuEntry("Gray", 'r');
    glutAddMenuEntry("Metal", 'm');
    glutAddMenuEntry("Green bronze", 'b');
    glutAddMenuEntry("Mattoni Basamento", 'x');
    glutAddMenuEntry("------------", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void choose_floor_menu(int key)
{
    switch (key)
    {
    case 'm':
        change_floor_to(metalTexturePath);
        break;
    case 'g':
        change_floor_to(grassTexturePath);
        break;
    case 'r':
        change_floor_to(grayTexturePath);
        break;
    case 'c':
        change_floor_to(patternTexturePath);
        break;
    case 'b':
        change_floor_to(greenBronzeTexturePath);
        break;
    case 'x':
        change_floor_to(mattoniBasamentoTexturePath);
        break;
    default:
        break;
    }
}

void change_floor_to(std::string newFloorPath)
{
    floorSurface.change_texture(newFloorPath.c_str());
    glutPostRedisplay();
}

void keyboard_control(unsigned char key, int x, int y)
{
    switch (key)
    {
    // camera
    case 'w':
        cam.forward_backword(0.01);
        glutPostRedisplay();
        break;
    case 's':
        cam.forward_backword(-0.01);
        glutPostRedisplay();
        break;
    case 'd':
        cam.turn_right();
        glutPostRedisplay();
        break;
    case 'a':
        cam.turn_left();
        glutPostRedisplay();
        break;
    case 'q':
        cam.turn_up();
        glutPostRedisplay();
        break;
    case 'e':
        cam.turn_down();
        glutPostRedisplay();
        break;
    // Game
    case 'x': // Turn right
        body.curTurn = (body.curTurn - 5) % 360;
        glutPostRedisplay();
        break;
    case 'z': // Turn left
        body.curTurn = (body.curTurn + 5) % 360;
        glutPostRedisplay();
        break;
    case 'm': // Stand
        body.isStand = true;
        glutPostRedisplay();
        break;
    case 'n': // walk
        body.stand();
        body.maxAngel = 20;
        body.stepDis = 1;
        body.speed = 0.02;
        kill = false;
        //Avoid calling timer twice
        if (body.isStand)
            glutTimerFunc(20, walking_timer, 20);
        body.isStand = false;
        break;
    case 'k': // kill
        body.isStand = true;
        body.stand();
        body.displayRobotBody();
        kill = true;
        glutTimerFunc(0, kill_timer, 0);
        break;
    case 'b': //run
        body.stand();
        body.maxAngel = 55;
        body.stepDis = 5;
        body.speed = 0.04;
        //Avoid calling timer twice
        if (body.isStand)
            glutTimerFunc(10, walking_timer, 10);
        body.isStand = false;
        break;
    default:
        break;
    }
}
/**************************** End Functions Definations ***************************/

/************************************* Main *************************************/

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    intialization();
    glutMainLoop();
    return 0;
}

/*********************************** End Main ***********************************/