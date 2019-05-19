#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

class TextureManager
{
    struct BITMAPINFOHEADER{
        uint  biSize;
        int   biWidth;
        int   biHeight;
        short biPlanes;
        short biBitCount;
        uint  biCompression;
        uint  biSizeImage;
        int   biXPelsPerMeter;
        int   biYPelsPerMeter;
        uint  biClrUsed;
        uint  biClrImportant;
    };

public:
    TextureManager();
    int LoadBitmap(char *filename);
};

#endif // TEXTUREMANAGER_H
