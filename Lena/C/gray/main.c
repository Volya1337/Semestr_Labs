#include "qdbmp.h"
#include <stdio.h>
#include <math.h>

int main(void)
{
    BMP*    bmp;
    UCHAR   r, g, b;
    UINT    width, height;
    UINT    x, y;
    int gray;

    bmp = BMP_ReadFile( "/home/valery/Semestr/Lena/C/gray/lena.bmp" );
    BMP_CHECK_ERROR( stderr, -1 ); /* If an error has occurred, notify and exit */

    width = BMP_GetWidth( bmp );
    height = BMP_GetHeight( bmp );

    for ( x = 0 ; x < width ; ++x )
    {
        for ( y = 0 ; y < height ; ++y )
        {
            /* Get pixel's RGB values */
            BMP_GetPixelRGB( bmp, x, y, &r, &g, &b );

            gray = (int)sqrtf((r*r+g*g+b*b)/3);
            BMP_SetPixelRGB( bmp, x, y, gray, gray, gray );
        }
    }

    BMP_WriteFile( bmp, "/home/valery/Semestr/Lena/C/gray/lena_gray.bmp");
    BMP_CHECK_ERROR( stderr, -2 );

    BMP_Free( bmp );

    return 0;
}