#pragma once
#include "Matrix.h"
#include <SDL_stdinc.h>

class MF
{
public:
	static Matrix scale2d(int x, int y);
	static Matrix translate2d(int x, int y);
	static Matrix rotate2d(int degree);
	static Matrix scale3d(int x, int y, int z);
	static Matrix translate3d(int x, int y, int z);
	static Matrix rotate3d(int degree, Vector point, Vector axis);

private:
	static Matrix rotateX(float degree);
	static Matrix rotateY(float degree);
	static Matrix rotateZ(float degree);
};
