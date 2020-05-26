#ifndef CAMERA_INCLUDED
#define CAMERA_INCLUDED

class CameraMovement
{
private:
    double center[3] = {0, 0, -1};
    double up[3] = {0, 1, 0};
    double eye[3] = {0, 0, 0};

    void crossProduct(double a[], double b[], double c[]);
    void rotatePoint(double a[], double theta, double p[]);
    void normalize(double a[]);

public:
    CameraMovement(/* args */);
    ~CameraMovement();
    void initializeCamera();
    void cameraLeft();
    void cameraRight();
    void cameraUp();
    void cameraForward();
    void cameraBackward();
    void cameraDown();
};

#endif