#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include "Checker.h"

int mouseX;
int mouseY;
bool isPressed = false;
int size = 50;

Checker _checkers[24];

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1, 0.902, 0.654);

	int a = 100;
	for (int x = -300; x < 400; x += 200)
	{
		for (int y = -400; y < 400; y += 200)
		{
			glBegin(GL_POLYGON);
			glVertex2f(x, y);
			glVertex2f(x + a, y);
			glVertex2f(x + a, y + a);
			glVertex2f(x, y + a);
			glEnd();
		}
	}

	for (int x = -400; x < 400; x += 200)
	{
		for (int y = -300; y < 400; y += 200)
		{
			glBegin(GL_POLYGON);
			glVertex2f(x, y);
			glVertex2f(x + a, y);
			glVertex2f(x + a, y + a);
			glVertex2f(x, y + a);
			glEnd();
		}
	}
	
	for (int i = 0; i < 24; i++)
	{
		//if (_checkers[i].IsAlive) continue;

		glBegin(GL_POLYGON);
		glColor3f(_checkers[i].checkerColor.R, _checkers[i].checkerColor.G, _checkers[i].checkerColor.B);
		glVertex2f(_checkers[i].X - size / 2, _checkers[i].Y + size / 2);
		glVertex2f(_checkers[i].X - size / 2, _checkers[i].Y - size / 2);
		glVertex2f(_checkers[i].X + size / 2, _checkers[i].Y - size / 2);
		glVertex2f(_checkers[i].X + size / 2, _checkers[i].Y + size / 2);
		glEnd();
	}

	glPopMatrix();
	glutSwapBuffers();
}

void mouseMotion(int x, int y) {


	for (int i = 0; i < 24; i++)
	{
		if (_checkers[i].X - size / 2 < x - 400 && _checkers[i].X + size / 2 > x - 400 && _checkers[i].Y - size / 2 < 400 - y && _checkers[i].Y + size / 2 > 400 - y)
		{
			_checkers[i].X = x - 400;
			_checkers[i].Y = 400 - y;
			glutPostRedisplay();
		}
	}
}

void init(void)
{
	glClearColor(0.597, 0.343, 0.164, 0.0);
	glShadeModel(GL_FLAT);

	int i = 0;

	for (int x = -400; x < 400; x += 200)
	{
		for (int y = -400; y < 0; y += 200)
		{
			_checkers[i] = Checker(x + size, y + size, Color(1.0, 1.0, 1.0));
			i++;
		}
	}

	for (int x = -300; x < 400; x += 200)
	{
		_checkers[i] = Checker(x + size, -300 + size, Color(1.0, 1.0, 1.0));
		i++;
	}



	for (int x = -300; x < 400; x += 200)
	{
		for (int y = 400; y > 0; y += -200)
		{
			_checkers[i] = Checker(x + size, y - size, Color(0.0, 0.0, 0.0));
			i++;
		}
	}

	for (int x = -400; x < 400; x += 200)
	{
		_checkers[i] = Checker(x + size, 300 - size, Color(0.0, 0.0, 0.0));
		i++;
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-400, 400, -400, 400);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMotionFunc(mouseMotion);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
