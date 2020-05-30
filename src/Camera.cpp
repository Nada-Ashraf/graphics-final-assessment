#include "Camera.h"

#ifndef MATH_HEADER
#define MATH_HEADER
#include <math.h>
#endif

#ifndef GL_HEADER
#define GL_HEADER
#include <GL/glut.h>
#endif

void Camera::initialize()
{
    gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);
}

void Camera::cross_product(const std::vector<double> &a, const std::vector<double> &b, std::vector<double> &c)
{
    c[0] = a[1] * b[2] - a[2] * b[1], c[1] = a[2] * b[0] - a[0] * b[2], c[2] = a[0] * b[1] - a[1] * b[0];
}

void Camera::normalize(std::vector<double> &a)
{
    double normalization = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] /= normalization, a[1] /= normalization, a[2] /= normalization;
}

void Camera::rotate(const std::vector<double> &dir, double theta, std::vector<double> &p)
{
    double p0 = (-dir[2] * p[1] + dir[1] * p[2]) * sin(theta),
           p1 = (dir[2] * p[0] - dir[0] * p[2]) * sin(theta),
           p2 = (-dir[1] * p[0] + dir[0] * p[1]) * sin(theta);
    p0 += (1 - cos(theta)) * (dir[0] * dir[0] * p[0] + dir[0] * dir[1] * p[1] + dir[0] * dir[2] * p[2]) + cos(theta) * p[0],
        p1 += (1 - cos(theta)) * (dir[0] * dir[1] * p[0] + dir[1] * dir[1] * p[1] + dir[1] * dir[2] * p[2]) + cos(theta) * p[1],
        p2 += (1 - cos(theta)) * (dir[0] * dir[2] * p[0] + dir[1] * dir[2] * p[1] + dir[2] * dir[2] * p[2]) + cos(theta) * p[2];
    p[0] = p0, p[1] = p1, p[2] = p2;
}

void Camera::turn_up()
{
    std::vector<double> axis = {0, 0, 0};
    cross_product(eye, up, axis);
    normalize(axis);
    rotate(axis, 0.1, eye);
    rotate(axis, 0.1, up);
    normalize(up);
}

void Camera::turn_down()
{
    std::vector<double> axis = {0, 0, 0};
    cross_product(eye, up, axis);
    normalize(axis);
    rotate(axis, -0.1, eye);
    rotate(axis, -0.1, up);
    normalize(up);
}

void Camera::turn_right()
{
    center[0] -= eye[0], center[1] -= eye[1], center[2] -= eye[2];
    rotate({0, 1, 0}, -speed, center);
    center[0] += eye[0], center[1] += eye[1], center[2] += eye[2];
}

void Camera::turn_left()
{
    center[0] -= eye[0], center[1] -= eye[1], center[2] -= eye[2];
    rotate({0, 1, 0}, speed, center);
    center[0] += eye[0], center[1] += eye[1], center[2] += eye[2];
}

void Camera::forward_backword(double speed)
{
    std::vector<double> dir(3);
    dir[0] = center[0] - eye[0], dir[1] = center[1] - eye[1], dir[2] = center[2] - eye[2];
    normalize(dir);
    eye[0] += dir[0] * speed, eye[2] += dir[2] * speed;
    center[0] += dir[0] * speed, center[2] += dir[2] * speed;
}