#include <glut.h>
#include <stdlib.h>
#include <iostream>

int mouseX;
int mouseY;
bool isPressed = false;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	int a = 10;
	glVertex2f(-glutGet(GLUT_WINDOW_WIDTH) / 2 + mouseX + 2*a, -glutGet(GLUT_WINDOW_HEIGHT) / 2 + mouseY + 2*a);
	glVertex2f(-glutGet(GLUT_WINDOW_WIDTH) / 2 + mouseX, -glutGet(GLUT_WINDOW_HEIGHT) / 2 + mouseY + 2*a);
	glVertex2f(-glutGet(GLUT_WINDOW_WIDTH) / 2 + mouseX, -glutGet(GLUT_WINDOW_HEIGHT) / 2 + mouseY);
	glVertex2f(-glutGet(GLUT_WINDOW_WIDTH) / 2 + mouseX + 2*a, -glutGet(GLUT_WINDOW_HEIGHT) / 2 + mouseY);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void motion(int x, int y)
{
	if (isPressed == false) return;

	mouseX = glutGet(GLUT_WINDOW_WIDTH) / 2 - x;
	mouseY = glutGet(GLUT_WINDOW_HEIGHT) / 2 - y;

	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON || state == GLUT_DOWN)
	{
		mouseX = glutGet(GLUT_WINDOW_WIDTH) / 2 - x;
		mouseY = glutGet(GLUT_WINDOW_HEIGHT) / 2 - y;

		isPressed = true;
	}
	else
	{
		isPressed = false;
	}
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
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
	glutMotionFunc(motion);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
