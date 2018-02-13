#include "Bullet.h"

Bullet::Bullet(Vector start, Vector end)
{
	matrix_ = Matrix(3, 2);
	matrix_.setItem(0, start);
	matrix_.setItem(1, end);
	distanceTraveled_ = 0;
	maxDistance_ = 300;
}

Bullet::~Bullet()
{
}

void Bullet::show(FWApplication* application, Vector eye, Vector lookAt)
{
	if (distanceTraveled_ >= maxDistance_)
		return; 
	application->SetColor(Color(255, 0, 0, 255));
	matrix_.show3d(application, eye, lookAt);
}

void Bullet::update()
{
	distanceTraveled_++;
	float** matrix = matrix_.getMatrix();
	matrix_ = matrix_ * MF::translate3d(matrix[0][1] - matrix[0][0], matrix[1][1] - matrix[1][0], matrix[2][1] - matrix[2][0]);
}
