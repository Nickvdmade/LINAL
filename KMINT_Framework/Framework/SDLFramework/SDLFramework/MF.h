#pragma once
#include "Matrix.h"
#include <SDL_stdinc.h>

class MF
{
public:
	static Matrix scale2d(float x, float y);
	static Matrix translate2d(float x, float y);
	static Matrix rotate2d(float degree);
	static Matrix scale3d(float x, float y, float z);
	static Matrix translate3d(float x, float y, float z);
	static Matrix rotate3d(float degree, Vector point, Vector axis);

private:
	static Matrix rotateX(float degree);
	static Matrix rotateY(float degree);
	static Matrix rotateZ(float degree);
};
