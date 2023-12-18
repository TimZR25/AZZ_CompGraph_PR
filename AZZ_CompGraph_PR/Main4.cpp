//#include <stdlib.h>
//#include <glut.h>
//#include <iostream>
//
//static int WSize = 800, HSize = 800;
//static GLfloat vertices[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
//{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},
//{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0} };
//
//GLfloat colors[][3] = { {1.0, 0.0, 0.0},{0.0,0.0,0.0},
//{1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},
//{1.0,0.0,1.0},{0.5, 0.5, 0.5},{0.0,1.0,1.0} };
//
//void polygon(int a, int b, int c, int d)
//{
//	glBegin(GL_POLYGON);
//	glColor3fv(colors[a]);
//	glVertex3fv(vertices[a]);
//	glColor3fv(colors[b]);
//	glVertex3fv(vertices[b]);
//	glColor3fv(colors[c]);
//	glVertex3fv(vertices[c]);
//	glColor3fv(colors[d]);
//	glVertex3fv(vertices[d]);
//	glEnd();
//}
//
//void colorcube()
//{
//	polygon(0, 3, 2, 1);
//	polygon(2, 3, 7, 6);
//	polygon(0, 4, 7, 3);
//	polygon(1, 2, 6, 5);
//	polygon(4, 5, 6, 7);
//	polygon(0, 1, 5, 4);
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPushMatrix();
//
//	glViewport(0, 400, 400, 400);    //ортографическая
//	glLoadIdentity();
//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
//	colorcube();
//
//	glViewport(400, 400, 400, 400);      //изометрическая
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
//	glRotatef(35, 1.0, 0.0, 0.0);
//	glRotatef(45, 0.0, 1.0, 0.0);
//	colorcube();
//
//	glViewport(0, 0, 400, 400);     //диметрическая 
//	glLoadIdentity();
//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
//	glRotatef(15.0, 1.0, 0.0, 0.0);
//	glRotatef(15.0, 0.0, 1.0, 0.0);
//	colorcube();
//
//	glViewport(400, 0, 400, 400);   //перспективная
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 12.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(0, 0, 4, 0, 0, 0, 0, 1, 0);
//	glRotatef(35, 1.0, 0.0, 0.0);
//	glRotatef(45, 0.0, 1.0, 0.0);
//	colorcube();
//
//	glutSwapBuffers();
//
//}
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//	glEnable(GL_CULL_FACE);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-3, 3, -3, 3, 0, 10);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv)
//{
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowPosition(150, 150);
//	glutInitWindowSize(WSize, HSize);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}
#include "stb_image.h"
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <GL/gl.h>
#include <gl/glu.h>
#include <glut.h>

using namespace std;

double anglePhi = 0, angleOmega = 0;
static int WSize = 800, HSize = 800;
static GLfloat vertices[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},
{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0} };

GLuint mouse1, mouse2, mouse3, mouse4, mouse5, mouse6;


void textureDuck1()
{
	int width, height, nrChannels;
	unsigned char* data1 = stbi_load("мышка1.bmp", &width, &height, &nrChannels, 0);

	glGenTextures(2, &mouse1);
	glBindTexture(GL_TEXTURE_2D, mouse1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data1)
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data1);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		stbi_image_free(data1);
	}
	else
	{
		cout << "The image could not be uploaded" << endl;
		stbi_image_free(data1);
	}
}

void textureDuck2()
{
	int width, height, nrChannels;
	unsigned char* data2 = stbi_load("мышка2.bmp", &width, &height, &nrChannels, 0);

	glGenTextures(2, &mouse2);
	glBindTexture(GL_TEXTURE_2D, mouse2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data2)
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data2);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		stbi_image_free(data2);
	}
	else
	{
		cout << "The image could not be uploaded" << endl;
		stbi_image_free(data2);
	}
}

void textureDuck3()
{
	int width, height, nrChannels;
	unsigned char* data3 = stbi_load("мышка3.bmp", &width, &height, &nrChannels, 0);

	glGenTextures(2, &mouse3);
	glBindTexture(GL_TEXTURE_2D, mouse3);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data3)
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data3);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		stbi_image_free(data3);
	}
	else
	{
		cout << "The image could not be uploaded" << endl;
		stbi_image_free(data3);
	}
}

void textureDuck4()
{
	int width, height, nrChannels;
	unsigned char* data4 = stbi_load("мышка4.bmp", &width, &height, &nrChannels, 0);

	glGenTextures(2, &mouse4);
	glBindTexture(GL_TEXTURE_2D, mouse4);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data4)
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data4);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		stbi_image_free(data4);
	}
	else
	{
		cout << "The image could not be uploaded" << endl;
		stbi_image_free(data4);
	}
}



void textureDuck5()
{
	int width, height, nrChannels;
	unsigned char* data5 = stbi_load("мышка5.bmp", &width, &height, &nrChannels, 0);

	glGenTextures(2, &mouse5);
	glBindTexture(GL_TEXTURE_2D, mouse5);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data5)
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data5);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		stbi_image_free(data5);
	}
	else
	{
		cout << "The image could not be uploaded" << endl;
		stbi_image_free(data5);
	}
}




void textureDuck6()
{
	int width, height, nrChannels;
	unsigned char* data6 = stbi_load("мышка6.bmp", &width, &height, &nrChannels, 0);

	glGenTextures(2, &mouse6);
	glBindTexture(GL_TEXTURE_2D, mouse6);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data6)
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data6);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		stbi_image_free(data6);
	}
	else
	{
		cout << "The image could not be uploaded" << endl;
		stbi_image_free(data6);
	}
}

void polygon(GLuint mouse, int a, int b, int c, int d)
{
	glBindTexture(GL_TEXTURE_2D, mouse);
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3fv(vertices[a]);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3fv(vertices[b]);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3fv(vertices[c]);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3fv(vertices[d]);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawCube()
{
	polygon(mouse1, 1, 0, 3, 2);
	polygon(mouse2, 2, 6, 5, 1);
	polygon(mouse3, 3, 7, 6, 2);
	polygon(mouse4, 0, 4, 5, 1);
	polygon(mouse5, 0, 3, 7, 4);
	polygon(mouse6, 7, 6, 5, 4);
}

void display(void)
{
	double x = 7 * cos(anglePhi) * cos(angleOmega);
	double y = 7 * sin(anglePhi) * cos(angleOmega);
	double z = 7 * sin(angleOmega);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0, 1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawCube();

	glutSwapBuffers();
}

void specialKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a': angleOmega += 0.1; break;
	case 'w': anglePhi += 0.1; break;
	case 'd': angleOmega -= 0.1; break;
	case 's': anglePhi -= 0.1; break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WSize, HSize);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("кубик с мышками");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(specialKeys);
	glEnable(GL_DEPTH_TEST);
	textureDuck1();
	textureDuck2();
	textureDuck3();
	textureDuck4();
	textureDuck5();
	textureDuck6();
	glutMainLoop();
	return 0;
}
