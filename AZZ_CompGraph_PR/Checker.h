#pragma once
#include <stdlib.h>
#include <glut.h>


struct Color
{
	GLfloat R;
	GLfloat G;
	GLfloat B;

	Color(GLfloat r, GLfloat g, GLfloat b);
	Color();
};

class Checker
{
public:
	int X;
	int Y;
	bool IsDead;
	Color checkerColor;

	Checker(int x, int y, Color color);
	Checker();
};


