//#include <glut.h>
//#include <stdlib.h>
//
//
//static GLfloat spin = 0.0;
//
//bool isStop;
//
//void spinDisplay(void)
//{
//	if (isStop) return;
//
//	spin = spin + 2.0;
//	if (spin > 360.0)
//		spin = spin - 360.0;
//	glutPostRedisplay();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	if (key == 'x') isStop = false;
//	if (key == 'X') isStop = true;
//	if (key == 27) exit(0);
//}
//
//void mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON) isStop = false;
//	if (button == GLUT_RIGHT_BUTTON) isStop = true;
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPushMatrix();
//	glRotatef(spin, 0.0, 0.0, 1.0);
//	glColor3f(1.0, 1.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex2f(-25.0, -25.0);
//	glVertex2f(25.0, -25.0);
//	glVertex2f(25.0, 25.0);
//	glVertex2f(-25.0, 25.0);
//	glEnd();
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(250, 250);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutIdleFunc(spinDisplay);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(mouse);
//	glutMainLoop();
//	return 0;   /* ANSI C requires main to return int. */
//}
