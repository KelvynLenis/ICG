#ifndef MYGL_H
#define MYGL_H

#include "core.h"
#include "frame_buffer.h"

typedef struct {
    int red;
    int green;
    int blue;

} tCor;

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

//
// >>> Declare aqui as funções que você implementar <<<
//

void putPixel(int x, int y, tCor color);
void drawLine(int x0, int y0, int  x1, int y1, tCor color);
void plotLineLow(int x0,int y0, int x1, int y1, tCor color);
void plotLineHigh(int x0,int y0, int x1, int y1, tCor color);

#endif  // MYGL_H
