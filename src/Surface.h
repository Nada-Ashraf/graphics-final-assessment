#ifndef SURFACE_INCLUDED
#define SURFACE_INCLUDED

#include "imageloader.h"
#include <vector>
#ifndef GL_HEADER
#define GL_HEADER
#include <GL/glut.h>
#endif

class Surface
{
private:
    GLuint id;
    std::vector<float> vertices;
    GLuint load_texture(Image *image);

public:
    Surface(std::vector<float> vec);
    void display_surface();
    void change_texture(const char *textureName);
};

#endif