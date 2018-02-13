#pragma once
#include "Matrix.h"
#include "MF.h"
#include "Bullet.h"
#include <chrono>

class SpaceShip
{
public:
	SpaceShip();
	~SpaceShip();
	void show(FWApplication* application, Vector eye, Vector lookAt);
	void moveForward();
	void turnHorizontal(bool left);
	void turnVertical(bool up);
	void roll(bool left);
	Bullet shoot();
	void sightToggle();

private:
	std::vector<Matrix> sides_;
	bool sight_;

	Matrix showSight();

	void createTop();
	void createBottom();
	void createLeft();
	void createRight();
	void createBack();
};
