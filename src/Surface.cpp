#include "Surface.h"

Surface::Surface(std::vector<float> vec) : vertices(vec)
{
}

void Surface::change_texture(const char *textureName)
{
    Image *img = loadBMP(textureName);
    this->id = load_texture(img);
    delete img;
}

GLuint Surface::load_texture(Image *img)
{
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);
    // image to texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->pixels);
    return this->id;
}

void Surface::display_surface()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(this->vertices[0], this->vertices[1], this->vertices[2]);
    glTexCoord2f(4.0f, 0.0f);
    glVertex3f(this->vertices[3], this->vertices[4], this->vertices[5]);
    glTexCoord2f(4.0f, 4.0f);
    glVertex3f(this->vertices[6], this->vertices[7], this->vertices[8]);
    glTexCoord2f(0.0f, 4.0f);
    glVertex3f(this->vertices[9], this->vertices[10], this->vertices[11]);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}