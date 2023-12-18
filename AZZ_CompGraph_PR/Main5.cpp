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


void textureMouse1()
{
	int width, height, nrChannels;
	const char* pathName = "мышка1.bmp";
	unsigned char* data1 = stbi_load(pathName, &width, &height, &nrChannels, 0);

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
		cout << "The image "+ (string)pathName + " could not be uploaded" << endl;
		stbi_image_free(data1);
	}
}

void textureMouse2()
{
	int width, height, nrChannels;
	const char* pathName = "мышка2.bmp";
	unsigned char* data2 = stbi_load(pathName, &width, &height, &nrChannels, 0);

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
		cout << "The image " + (string)pathName + " could not be uploaded" << endl;
		stbi_image_free(data2);
	}
}

void textureMouse3()
{
	int width, height, nrChannels;
	const char* pathName = "мышка3.bmp";
	unsigned char* data3 = stbi_load(pathName, &width, &height, &nrChannels, 0);

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
		cout << "The image " + (string)pathName + " could not be uploaded" << endl;
		stbi_image_free(data3);
	}
}

void textureMouse4()
{
	int width, height, nrChannels;
	const char* pathName = "мышка4.bmp";
	unsigned char* data4 = stbi_load(pathName, &width, &height, &nrChannels, 0);

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
		cout << "The image " + (string)pathName + " could not be uploaded" << endl;
		stbi_image_free(data4);
	}
}



void textureMouse5()
{
	int width, height, nrChannels;
	const char* pathName = "мышка5.bmp";
	unsigned char* data5 = stbi_load(pathName, &width, &height, &nrChannels, 0);

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
		cout << "The image " + (string)pathName + " could not be uploaded" << endl;
		stbi_image_free(data5);
	}
}




void textureMouse6()
{
	int width, height, nrChannels;
	const char* pathName = "мышка6.bmp";
	unsigned char* data6 = stbi_load(pathName, &width, &height, &nrChannels, 0);

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
		cout << "The image " + (string)pathName + " could not be uploaded" << endl;
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
	double x = 5 * cos(anglePhi) * cos(angleOmega);
	double y = 5 * sin(anglePhi) * cos(angleOmega);
	double z = 5 * sin(angleOmega);

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
	case 'a': angleOmega -= 0.1; break;
	case 'w': anglePhi -= 0.1; break;
	case 'd': angleOmega += 0.1; break;
	case 's': anglePhi += 0.1; break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Rus");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WSize, HSize);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Кубик с мышками");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(specialKeys);
	glEnable(GL_DEPTH_TEST);
	textureMouse1();
	textureMouse2();
	textureMouse3();
	textureMouse4();
	textureMouse5();
	textureMouse6();
	glutMainLoop();
	return 0;
}