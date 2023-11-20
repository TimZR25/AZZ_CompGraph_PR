#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include "Checker.h"
#define L 24

int mouseX;
int mouseY;
bool isPressed = false;
int sizeChecker = 50;

Checker _checkers[L];


void createField() // отрисовывает поле шахматной доски 8x8
{
	glColor3f(1, 0.902, 0.654);

	int cellSize = 100;

	for (int x = -300; x < 400; x += 200)	// создает клетки в шахматном порядке начиная с нечетного ряда с шагом 2 ряда
	{
		for (int y = -400; y < 400; y += 200)
		{
			glBegin(GL_POLYGON);
			glVertex2f(x, y);
			glVertex2f(x + cellSize, y);
			glVertex2f(x + cellSize, y + cellSize);
			glVertex2f(x, y + cellSize);
			glEnd();
		}
	}

	for (int x = -400; x < 400; x += 200)	// создает клетки в шахматном порядке начиная с четного ряда с шагом 2 ряда
	{
		for (int y = -300; y < 400; y += 200)
		{
			glBegin(GL_POLYGON);
			glVertex2f(x, y);
			glVertex2f(x + cellSize, y);
			glVertex2f(x + cellSize, y + cellSize);
			glVertex2f(x, y + cellSize);
			glEnd();
		}
	}
}

void drawCheckers() // отрисовывает шашки от центра координат шашки
{
	for (int i = 0; i < L; i++)
	{
		if (_checkers[i].IsDead) continue; // пропускает "удаленные" шашки

		glBegin(GL_POLYGON);
		glColor3f(_checkers[i].checkerColor.R, _checkers[i].checkerColor.G, _checkers[i].checkerColor.B);
		glVertex2f(_checkers[i].X - sizeChecker / 2, _checkers[i].Y + sizeChecker / 2);
		glVertex2f(_checkers[i].X - sizeChecker / 2, _checkers[i].Y - sizeChecker / 2);
		glVertex2f(_checkers[i].X + sizeChecker / 2, _checkers[i].Y - sizeChecker / 2);
		glVertex2f(_checkers[i].X + sizeChecker / 2, _checkers[i].Y + sizeChecker / 2);
		glEnd();
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	
	createField();

	drawCheckers();

	glPopMatrix();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	isPressed = (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN); // проверка на нажатую левую кнопку мыши


	if (button == GLUT_RIGHT_BUTTON) // удаление шашки, если нажата правая кнопка мыши
	{
		for (int i = 0; i < L; i++)
		{
			if (_checkers[i].X - sizeChecker / 2 < x - 400 && _checkers[i].X + sizeChecker / 2 > x - 400 
				&& _checkers[i].Y - sizeChecker / 2 < 400 - y && _checkers[i].Y + sizeChecker / 2 > 400 - y) // проверка что мышь находится внутри квадрата
			{
				_checkers[i].IsDead = true;
				glutPostRedisplay();
			}
		}
	}
}

void mouseMotion(int x, int y) 
{
	for (int i = 0; i < L; i++)
	{
		if (_checkers[i].X - sizeChecker / 2 < x - 400 && _checkers[i].X + sizeChecker / 2 > x - 400 
			&& _checkers[i].Y - sizeChecker / 2 < 400 - y && _checkers[i].Y + sizeChecker / 2 > 400 - y) // проверка что мышь находится внутри квадрата
		{
			_checkers[i].X = x - 400;
			_checkers[i].Y = 400 - y;
			glutPostRedisplay();

			if (isPressed == true) break;
		}
	}
}

void createLowerCheckers(int i, Color color)
{
	for (int x = -400; x < 400; x += 200) // создает клетки в шахматном порядке начиная с нечетного ряда с шагом 2 ряда
	{
		for (int y = -400; y < 0; y += 200)
		{
			_checkers[i] = Checker(x + sizeChecker, y + sizeChecker, color);
			i++;
		}
	}

	for (int x = -300; x < 400; x += 200) // создает клетки в шахматном порядке начиная с четного ряда с шагом 2 ряда
	{
		_checkers[i] = Checker(x + sizeChecker, -300 + sizeChecker, color);
		i++;
	}
}

void createUpperCheckers(int i, Color color)
{
	for (int x = -300; x < 400; x += 200) // создает клетки в шахматном порядке начиная с нечетного ряда с шагом 2 ряда
	{
		for (int y = 400; y > 0; y += -200)
		{
			_checkers[i] = Checker(x + sizeChecker, y - sizeChecker, color);
			i++;
		}
	}

	for (int x = -400; x < 400; x += 200) // создает клетки в шахматном порядке начиная с четного ряда с шагом 2 ряда
	{
		_checkers[i] = Checker(x + sizeChecker, 300 - sizeChecker, color);
		i++;
	}
}

void init(void)
{
	glClearColor(0.597, 0.343, 0.164, 0.0);
	glShadeModel(GL_FLAT);

	createLowerCheckers(0, Color(1.0, 1.0, 1.0));
	createUpperCheckers(12, Color(0.0, 0.0, 0.0));
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
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutMainLoop();
	return 0;
}
