#include "mygl.h"

//
// >>> Defina aqui as funções que você implementar <<< 
//


void putPixel(int x, int y, tCor color1){


    fb_ptr[(x + y * IMAGE_WIDTH) * 4 + 0] = color1.red; // componente R
    fb_ptr[(x + y * IMAGE_WIDTH) * 4 + 1] = color1.green; // componente G
    fb_ptr[(x + y * IMAGE_WIDTH) * 4 + 2] = color1.blue; // componente B
    fb_ptr[(x + y * IMAGE_WIDTH) * 4 + 3] = 255; // componente A  

}

void DrawLine(int xi, int xf, int yi, int yf, tCor color){
    int incE, incNE, d, inclinacao=1, dx, dy;
    dx = xf - xi;
    dy = yf - yi;

    incE = 2 * dx;
    incNE = 2 * dx - 2 * dy;
    d = 2 * dx - dy;

    while (yi < yf){
        PutPixel(xi, yi, color);
        if (d <= 0) {
           d+=incE;
           yi++;
        }
        else{
           d+=incNE;
           yi++;
           xi+=inclinacao;
        }
    }
}

// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {

    //
    // >>> Chame aqui as funções que você implementou <<<
    //

    tCor color;

    color.red = 255;
    color.green = 0;
    color.blue = 0;


    putPixel(256, 255, color);
    DrawLine(260, 270, 280, 330, color);
    DrawLine(260, 270, 260, 330, color);
    DrawLine(260, 270, 240, 330, color);
    DrawLine(260, 270, 260, 210, color);
    DrawLine(260, 270, 280, 210, color);
    DrawLine(260, 270, 240, 210, color);

}
