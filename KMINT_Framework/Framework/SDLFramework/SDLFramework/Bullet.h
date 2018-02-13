#pragma once
#include "Vector.h"
#include "Matrix.h"
#include "MF.h"
#include <chrono>

class Bullet
{
public:
	Bullet(Vector start, Vector end);
	~Bullet();
	void show(FWApplication* application, Vector eye, Vector lookAt);
	void update();

private:
	Matrix matrix_;
	int distanceTraveled_;
	int maxDistance_;
};
