#ifndef FloorAndWalls_INCLUDED
#define FloorAndWalls_INCLUDED

#include "imageloader.h"

#ifndef GL_HEADER
#define GL_HEADER
#include <GL/glut.h>
#endif

class FloorAndWalls
{
private:
    float *vertices;
    GLuint texture;
    GLuint loadTexture(Image *image);

public:
    FloorAndWalls(float *vertices);
    ~FloorAndWalls();
    void changeTexture(const char *textureName);
    void displayFloorAndWalls();
};

#endif