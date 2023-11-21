#include <stdlib.h>
#include <glut.h>
#include <iostream>


GLfloat vertices[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},
{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0} };

GLfloat colors[][3] = { {1.0, 1.0, 1.0},{1.0,0.0,0.0},
{1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},
{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0} };

GLfloat spin = 0.0;
bool isSpinned;

void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(vertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(vertices[c]);
	glColor3fv(colors[d]);
	glVertex3fv(vertices[d]);
	glEnd();
}
void colorcube()
{
	polygon(0, 3, 2, 1);
	polygon(2, 3, 7, 6);
	polygon(0, 4, 7, 3);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
	polygon(0, 1, 5, 4);
}

void spinDisplay(void)
{
	if (isSpinned == false) return;

	spin = spin + 0.05;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'x')
		isSpinned = true; // запустить вращение
	if (key == 'X')
		isSpinned = false; // остановить вращение
	if (key == 27)
		exit(0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	
	glViewport(0, 400, 400, 400);
	colorcube();

	glViewport(400, 400, 400, 400);
	gluLookAt(0, 0, 0, -1, -1, -1, 0, 1, 0);
	colorcube();

	glViewport(0, 0, 400, 400);
	colorcube();

	glViewport(400, 0, 400, 400);
	colorcube();


	glPopMatrix();
	glutSwapBuffers();
}

void init(void)
{
	glShadeModel(GL_FLAT);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -5, 5);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cube");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(spinDisplay);
	glutMainLoop();
	return 0;
}
