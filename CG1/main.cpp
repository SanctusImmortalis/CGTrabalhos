#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	Pixel c = {256, 256, 255, 255, 255 ,255};
	Pixel o1 = {511, 384, 255, 0, 0, 255};
	Pixel o2 = {384, 511, 0, 255, 0, 255};
	Pixel o3 = {128, 511, 0, 0, 255, 255};
	Pixel o4 = {0, 384, 128, 128, 0, 255};
	Pixel o5 = {0, 128, 128, 0, 128, 255};
	Pixel o6 = {128, 0, 0, 128, 128, 255};
	Pixel o7 = {384, 0, 128, 128, 128, 255};
	Pixel o8 = {511, 128, 0, 0, 0, 255};

	DrawLine(c, o1);
	DrawLine(c, o2);
	DrawLine(c, o3);
	DrawLine(c, o4);
	DrawLine(c, o5);
	DrawLine(c, o6);
	DrawLine(c, o7);
	DrawLine(c, o8);

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
