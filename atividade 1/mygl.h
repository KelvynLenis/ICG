#ifndef MYGL_H
#define MYGL_H

#include "core.h"
#include "frame_buffer.h"

//Struct para cores.
struct tCor {
  int red;
	int green;
	int blue;
	int alpha;
};

//Struct para coordenadas X e Y de cada vértice e sua cor.
struct tVertice {
	int x;
	int y;
	struct tCor color;
};

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

//
// >>> Declare aqui as funções que você implementar <<<
//

int abs (int i);

void putPixel(struct tVertice vertice);
void drawnLineLow (struct tVertice vertice, struct tVertice vertice2);
void drawnLineHigh (struct tVertice vertice, struct tVertice vertice2);
void drawnLine (struct tVertice vertice, struct tVertice vertice2);
void drawnTriangle (struct tVertice vertice, struct tVertice vertice2, struct tVertice vertice3);


#endif  // MYGL_H
