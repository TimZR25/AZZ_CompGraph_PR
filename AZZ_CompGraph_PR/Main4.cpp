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
