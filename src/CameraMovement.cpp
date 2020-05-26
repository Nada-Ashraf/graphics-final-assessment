#include "CameraMovement.h"

#ifndef MATH_HEADER
#define MATH_HEADER
#include <math.h>
#endif

#ifndef GL_HEADER
#define GL_HEADER
#include <GL/glut.h>
#endif

CameraMovement::CameraMovement(/* args */)
{
}

CameraMovement::~CameraMovement()
{
}

void CameraMovement::initializeCamera()
{
    gluLookAt(eye[0], eye[1], eye[2],
              center[0], center[1], center[2],
              up[0], up[1], up[2]);
}

void CameraMovement::crossProduct(double a[], double b[], double c[])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}

void CameraMovement::normalize(double a[])
{
    double norm;
    norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
    norm = sqrt(norm);
    a[0] /= norm;
    a[1] /= norm;
    a[2] /= norm;
}

void CameraMovement::rotatePoint(double a[], double theta, double p[])
{
    double temp[3];
    temp[0] = p[0];
    temp[1] = p[1];
    temp[2] = p[2];

    temp[0] = -a[2] * p[1] + a[1] * p[2];
    temp[1] = a[2] * p[0] - a[0] * p[2];
    temp[2] = -a[1] * p[0] + a[0] * p[1];

    temp[0] *= sin(theta);
    temp[1] *= sin(theta);
    temp[2] *= sin(theta);

    temp[0] += (1 - cos(theta)) * (a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
    temp[1] += (1 - cos(theta)) * (a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
    temp[2] += (1 - cos(theta)) * (a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

    temp[0] += cos(theta) * p[0];
    temp[1] += cos(theta) * p[1];
    temp[2] += cos(theta) * p[2];

    p[0] = temp[0];
    p[1] = temp[1];
    p[2] = temp[2];
}

void CameraMovement::cameraLeft()
{
    double ax[] = {0, 1, 0};
    this->rotatePoint(ax, (double)5 / 180 * 3.14, eye);
}

void CameraMovement::cameraRight()
{
    double ax[] = {0, 1, 0};
    this->rotatePoint(ax, (double)-5 / 180 * 3.14, eye);
}

void CameraMovement::cameraUp()
{
    double ax[] = {1, 0, 0};
    this->rotatePoint(ax, (double)5 / 180 * 3.14, eye);
}

void CameraMovement::cameraDown()
{
    double ax[] = {1, 0, 0};
    this->rotatePoint(ax, (double)-5 / 180 * 3.14, eye);
}

void CameraMovement::cameraForward()
{
    if (eye[2] < 0)
    {
        eye[2] = eye[2] + 1;
    }
    gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);
}

void CameraMovement::cameraBackward()
{
    eye[2] = eye[2] - 1;
    gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);
}
