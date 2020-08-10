#include "mygl.h"

//
// >>> Defina aqui as funções que você implementar <<<
//

//Retorna o valor absoluto do número inteiro passado como parâmetro
int abs (int i) {
	if (i < 0) {
		i *= -1;
	}

	return i;
}

void putPixel(struct tVertice vertice) {
	fb_ptr[vertice.y * 4 + IMAGE_WIDTH * 4 * vertice.x] = vertice.color.red;
	fb_ptr[vertice.y * 4 + IMAGE_WIDTH * 4 * vertice.x + 1] = vertice.color.green;
	fb_ptr[vertice.y * 4 + IMAGE_WIDTH * 4 * vertice.x + 2] = vertice.color.blue;
	fb_ptr[vertice.y * 4 + IMAGE_WIDTH * 4 * vertice.x + 3] = vertice.color.alpha;
}

void drawnLineLow (struct tVertice vertice, struct tVertice vertice2){
	int dx = vertice2.x - vertice.x;
	int dy = vertice2.y - vertice.y;
	int yi = 1;

	float dr = (vertice2.color.red - vertice.color.red)/dx;
    float dg = (vertice2.color.green - vertice.color.green)/dx;
    float db = (vertice2.color.blue - vertice.color.blue)/dx;

	if (dy < 0) {
		yi = -1;
		dy = -dy;
	}

	int D = 2*dy - dx;


	for (int i= vertice.x; i <= vertice2.x; i++) {

		vertice.x = i;

		vertice.color.red +=dr;
        vertice.color.green += dg;
        vertice.color.blue += db;

        putPixel(vertice);


		if (D > 0) {
			vertice.y += yi;
			D -= 2*dx;
		}

		D += 2*dy;
	}
}

void drawnLineHigh (struct tVertice vertice, struct tVertice vertice2) {
	int dx = vertice2.x - vertice.x;
	int dy = vertice2.y - vertice.y;
	int xi = 1;

	float dr = (vertice2.color.red - vertice.color.red)/dy;
    float dg = (vertice2.color.green - vertice.color.green)/dy;
    float db = (vertice2.color.blue - vertice.color.blue)/dy;


	if (dx < 0) {
		xi = -1;
		dx = -dx;
	}
	int D = 2*dx - dy;

	for (int i = vertice.y; i <= vertice2.y; i++){

		vertice.y = i;

		vertice.color.red += dr;
        vertice.color.green += dg;
        vertice.color.blue += db;

        putPixel(vertice);

		if (D > 0) {
			vertice.x += xi;
			D -= 2*dy;
		}

		D += 2*dx;
	}
}

void drawnLine (struct tVertice vertice, struct tVertice vertice2){
	if (abs(vertice2.y - vertice.y) < abs(vertice2.x - vertice.x)) {
		if (vertice.x > vertice2.x)
		{
			drawnLineLow(vertice2, vertice);
		} else {
			drawnLineLow(vertice, vertice2);
		}
	} else {
		if (vertice.y > vertice2.y) {
			drawnLineHigh(vertice2, vertice);
		} else {
			drawnLineHigh(vertice, vertice2);
		}
	}
}

void drawnTriangle (struct tVertice vertice, struct tVertice vertice2, struct tVertice vertice3) {
	drawnLine(vertice, vertice2);
	drawnLine(vertice2, vertice3);
	drawnLine(vertice3, vertice);
}

// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Chame aqui as funções que você implementou <<<
    //

    struct tVertice vertice;
    struct tVertice vertice2;
    struct tVertice vertice3;


    vertice.x = 300;
    vertice.y = 150;

    vertice2.x = 500;
    vertice2.y = 70;

    vertice3.x = 500;
    vertice3.y = 230;

    vertice.color.red = 0;
    vertice.color.green = 255;
    vertice.color.blue = 0;
    vertice.color.alpha = 255;

    vertice2.color.red = 0;
    vertice2.color.green = 0;
    vertice2.color.blue = 255;
    vertice2.color.alpha = 255;

    vertice3.color.red = 255;
    vertice3.color.green = 0;
    vertice3.color.blue = 0;
    vertice3.color.alpha = 255;


    //Teste das Funções implementadas;

    //putPixel(vertice);
    //putPixel(vertice2);
    //putPixel(vertice3);

    //drawnLine(vertice, vertice3);

    drawnTriangle(vertice, vertice2, vertice3);



}
