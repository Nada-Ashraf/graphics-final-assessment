#include "FloorAndWalls.h"

FloorAndWalls::FloorAndWalls(float *vertices)
{
    this->vertices = vertices;
}

void FloorAndWalls::changeTexture(const char *textureName)
{
    Image *image = loadBMP(textureName);
    texture = loadTexture(image);
    delete image;
}

FloorAndWalls::~FloorAndWalls()
{
}

GLuint FloorAndWalls::loadTexture(Image *image)
{
    glGenTextures(1, &texture);            //Make room for our texture
    glBindTexture(GL_TEXTURE_2D, texture); //Tell OpenGL which texture to edit
    //Map the image to the texture
    glTexImage2D(GL_TEXTURE_2D,               //Always GL_TEXTURE_2D
                 0,                           //0 for now
                 GL_RGB,                      //Format OpenGL uses for image
                 image->width, image->height, //Width and height
                 0,                           //The border of the image
                 GL_RGB,                      //GL_RGB, because pixels are stored in RGB format
                 GL_UNSIGNED_BYTE,            //GL_UNSIGNED_BYTE, because pixels are stored
                                              //as unsigned numbers
                 image->pixels);              //The actual pixel data
    return texture;                           //Returns the id of the texture
}

void FloorAndWalls::displayFloorAndWalls()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);

    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(vertices[0], vertices[1], vertices[2]); //vertex1
    glTexCoord2f(4.0f, 0.0f);
    glVertex3f(vertices[3], vertices[4], vertices[5]); //vertex2
    glTexCoord2f(4.0f, 4.0f);
    glVertex3f(vertices[6], vertices[7], vertices[8]); //vertex3
    glTexCoord2f(0.0f, 4.0f);
    glVertex3f(vertices[9], vertices[10], vertices[11]); //vertex4
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}