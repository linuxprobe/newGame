#include <glut.h>
//#include "gl.h"
#include <iostream>
using namespace std;
int POINT1[] = {10,10};
int POINT2[] = {100,100};

void myDisplay(void)

{
	glClear(GL_COLOR_BUFFER_BIT);
	// 	glRasterPos2i(100,100);
	// 	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,98);
	// 	glutStrokeCharacter(GLUT_BITMAP_8_BY_13,98);
	//glRecti(200, 100, 50, 250);
	glBegin(GL_LINES);
	glVertex2iv(POINT1);
	glVertex2iv(POINT2);
	glEnd();

	glFlush();
}
void setPeix(int xcord,int ycord)
{
	glBegin(GL_POINTS);
	glVertex2i(xcord,ycord);
	glEnd();
}

int main(int argc, char *argv[])

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowPosition(100, 100);

	glutInitWindowSize(400, 400);

	glutCreateWindow("第一个OpenGL程序");

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0,400.0,0.0,400.0);

	glutDisplayFunc(&myDisplay);

	glutMainLoop();

	return 0;

}