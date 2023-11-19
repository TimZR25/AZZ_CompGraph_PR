#pragma once
#include <stdlib.h>
#include <glut.h>


struct Color
{
	GLfloat R;
	GLfloat G;
	GLfloat B;

	Color(GLfloat r, GLfloat g, GLfloat b)
	{
		R = r;
		G = g;
		B = b;
	}

	Color()
	{
		R = 1.0;
		G = 1.0;
		B = 1.0;
	}
};

class Checker
{
public:
	int X;
	int Y;
	//bool IsAlive;
	Color checkerColor;
	Checker(int x, int y, Color color)
	{
		X = x;
		Y = y;
		checkerColor = color;
	}

	Checker()
	{
		X = 0;
		Y = 0;
		checkerColor = Color();
	}
};


