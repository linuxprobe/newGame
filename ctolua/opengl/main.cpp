#include <glut.h>
//#include "gl.h"
#include <iostream>
using namespace std;
float POINT1[] = {30.0,10.0};
float POINT2[] = {100.0,100.0};

GLint pt[8][3] = {{0,0,0},{0,100,0},{100,0,0},{100,100,0},
{0,0,100},{0,100,100},{100,0,100},{100,100,100} };
void init(void){
	glClearColor(0.0,0.0,0.0,0.0);//黑色清屏
	glShadeModel(GL_FLAT);//单调着色

}
void myDisplay(void)

{
	glClear(GL_COLOR_BUFFER_BIT);//清色彩缓冲区
	glColor3f(1.0,1.0,1.0);//设置白色
	glLoadIdentity();//加载单位矩阵
	gluLookAt(5.0,5.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);//设置相机参数
	glScaled(1.0,2.0,1.0);//x,y,z缩放比率
	glutWireCube(1.0);//画立方体
	glFlush();//立即绘制
	
}
void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);//调整视口位置和大小
	glMatrixMode(GL_PROJECTION);//切换到投影矩阵
	glLoadIdentity();//加载单位阵至投影矩阵
	glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);//设置视景体
	glMatrixMode(GL_MODELVIEW);//切换到模型视图矩阵
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
	init();
	glutDisplayFunc(&myDisplay);
	glutReshapeFunc(&reshape);

	glutMainLoop();

	return 0;

}