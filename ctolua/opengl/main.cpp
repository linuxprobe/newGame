#include <glut.h>
//#include "gl.h"
#include <iostream>
using namespace std;
float POINT1[] = {30.0,10.0};
float POINT2[] = {100.0,100.0};

GLint pt[8][3] = {{0,0,0},{0,100,0},{100,0,0},{100,100,0},
{0,0,100},{0,100,100},{100,0,100},{100,100,100} };
#define imageWidth 64
#define imageHeight 64
static GLubyte checkImage[imageWidth][imageHeight][4];
static GLuint texName;
void makeImage()
{
	int i,j,c;
	for (i = 0; i < imageHeight; i++)
	{
		for (j = 0; j < imageWidth; j++)
		{
			c = (((i&0x8)==0)^((j&0x8)==0))*255;
			checkImage[i][j][0] = (GLubyte)c;
			checkImage[i][j][1] = (GLubyte)c;
			checkImage[i][j][2] = (GLubyte)c;
			checkImage[i][j][3] = (GLubyte)255;
		}
	}
}
void init(void){
	glClearColor(0.0,0.0,0.0,0.0);//黑色清屏
	glShadeModel(GL_FLAT);//单调着色
	glEnable(GL_DEPTH_TEST);
	makeImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,imageWidth,imageHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,checkImage);
}

void myDisplay(void)

{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//清色彩缓冲区
	//glColor3f(1.0,1.0,1.0);//设置白色
		//gluLookAt(0.0,0.0,2.0, 0.0,0.0,0.0, 0.0,1.0,0.0);//设置相机参数
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D,texName);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0,0.0);glVertex3f(-2.0,-1.0,0.0);
	glTexCoord2f(0.0,1.0);glVertex3f(-2.0,1.0,0.0);
	glTexCoord2f(1.0,1.0);glVertex3f(0.0,1.0,0.0);
	glTexCoord2f(1.0,0.0);glVertex3f(0.0,-1.0,0.0);
	glEnd();
	//glLoadIdentity();//加载单位矩阵

	//glScaled(1.0,2.0,1.0);//x,y,z缩放比率
	//glutWireCube(1.0);//画立方体
	glFlush();//立即绘制
	glDisable(GL_TEXTURE_2D);
	
}
void reshape(int w,int h){
	printf("%d  %d",w,h);
	glViewport(0,0,(GLsizei)w,(GLsizei)h);//调整视口位置和大小
	glMatrixMode(GL_PROJECTION);//切换到投影矩阵
	glLoadIdentity();//加载单位阵至投影矩阵
	//glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);//设置视景体
	gluPerspective(60,(GLfloat)w/(GLfloat)h,1.0,30);
	glMatrixMode(GL_MODELVIEW);//切换到模型视图矩阵
	glLoadIdentity();//加载单位阵
	glTranslatef(0.0,0.0,-3.6);
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

	init();
	glutDisplayFunc(&myDisplay);
	glutReshapeFunc(&reshape);

	glutMainLoop();

	return 0;

}