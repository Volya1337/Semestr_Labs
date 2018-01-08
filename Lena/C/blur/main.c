#include "qdbmp.h"
#include <stdio.h>
#include <math.h>
#define N 5
int main(void)
{
    BMP*    bmp;
    UCHAR   r,r1,r2,r3,r4,r5,r6,r7,r8,g,g1,g2,g3,g4,g5,g6,g7,g8,b,b1,b2,b3,b4,b5,b6,b7,b8;
    UINT    width, height;
    UINT    x, y;


    bmp = BMP_ReadFile( "/home/valery/Semestr/Lena/C/blur/lena.bmp" );
    BMP_CHECK_ERROR( stderr, -1 );

    width = BMP_GetWidth( bmp );
    height = BMP_GetHeight( bmp );

    x=0;
    while (x < width){
        y=0;
        while (y < height)
        {
            BMP_GetPixelRGB(bmp, x-N, y-N, &r, &g, &b);
            BMP_GetPixelRGB(bmp, x-N, y, &r1, &g1, &b1);
            BMP_GetPixelRGB(bmp, x-N, y+N, &r2, &g2, &b2);
            BMP_GetPixelRGB(bmp, x, y-N, &r3, &g3, &b3);
            BMP_GetPixelRGB(bmp, x, y, &r4, &g4, &b4);
            BMP_GetPixelRGB(bmp, x, y+N, &r5, &g5, &b5);
            BMP_GetPixelRGB(bmp, x+N, y-N, &r6, &g6, &b6);
            BMP_GetPixelRGB(bmp, x+N, y, &r7, &g7, &b7);
            BMP_GetPixelRGB(bmp, x+N, y+N, &r8, &g8, &b8);
            r = (r+r1+r2+r3+r4+r5+r6+r7+r8)/9;
            g = (g+g1+g2+g3+g4+g5+g6+g7+g8)/9;
            b = (b+b1+b2+b3+b4+b5+b6+b7+b8)/9;
            BMP_SetPixelRGB( bmp, x, y, r,g,b);
            y+=1;
        }
        x+=1;
    }

    BMP_WriteFile( bmp, "/home/valery/Semestr/Lena/C/blur/lena_blur.bmp");
    BMP_CHECK_ERROR( stderr, -2 );

    BMP_Free( bmp );

    return 0;
}