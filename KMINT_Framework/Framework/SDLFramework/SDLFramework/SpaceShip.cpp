#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
	createTop();
	createBottom();
	createLeft();
	createRight();
	createBack();
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::show(FWApplication* application, Vector eye, Vector lookAt)
{
	if (sight_)
	{
		application->SetColor(Color(255, 255, 0, 255));
		Matrix sight = showSight();
		sight.show3d(application, eye, lookAt);
	}
	application->SetColor(Color(255, 255, 255, 255));
	for (int i = 0; i < sides_.size(); i++)
		sides_[i].show3d(application, eye, lookAt);
}

void SpaceShip::moveForward()
{
	Matrix back = sides_[4];
	float** backMatrix = back.getMatrix();
	Vector backVector1(3);
	backVector1.setItem(0, backMatrix[0][0]);
	backVector1.setItem(1, backMatrix[1][0]);
	backVector1.setItem(2, backMatrix[2][0]);
	Vector backVector2(3);
	backVector2.setItem(0, backMatrix[0][1]);
	backVector2.setItem(1, backMatrix[1][1]);
	backVector2.setItem(2, backMatrix[2][1]);
	Vector backVector3(3);
	backVector3.setItem(0, backMatrix[0][2]);
	backVector3.setItem(1, backMatrix[1][2]);
	backVector3.setItem(2, backMatrix[2][2]);
	Vector direction1 = backVector1 - backVector2;
	Vector direction2 = backVector2 - backVector3;
	Vector normal = direction1.crossProduct(direction2);
	normal.normalize();
	std::vector<float> normalVector = normal.getVector();
	for (int i = 0; i < sides_.size(); i++)
		sides_[i] = sides_[i] * MF::translate3d(normalVector[0], normalVector[1], normalVector[2]);
}

void SpaceShip::turnHorizontal(bool left)
{
	Matrix top = sides_[0];
	float** topMatrix = top.getMatrix();
	Vector topVector1(3);
	topVector1.setItem(0, topMatrix[0][0]);
	topVector1.setItem(1, topMatrix[1][0]);
	topVector1.setItem(2, topMatrix[2][0]);
	Vector topVector2(3);
	topVector2.setItem(0, topMatrix[0][1]);
	topVector2.setItem(1, topMatrix[1][1]);
	topVector2.setItem(2, topMatrix[2][1]);
	Vector topVector3(3);
	topVector3.setItem(0, topMatrix[0][2]);
	topVector3.setItem(1, topMatrix[1][2]);
	topVector3.setItem(2, topMatrix[2][2]);
	Vector direction1 = topVector1 - topVector2;
	Vector direction2 = topVector2 - topVector3;
	Vector normal = direction1.crossProduct(direction2);
	normal.normalize();
	Vector rotationPoint(3);
	rotationPoint.setItem(0, topMatrix[0][1] + (topMatrix[0][2] - topMatrix[0][1]) / 2);
	rotationPoint.setItem(1, topMatrix[1][1] + (topMatrix[1][2] - topMatrix[1][1]) / 2);
	rotationPoint.setItem(2, topMatrix[2][1] + (topMatrix[2][2] - topMatrix[2][1]) / 2);
	float rotation = 10;
	if (!left)
		rotation = -rotation;
	for (int i = 0; i < sides_.size(); i++)
		sides_[i] = sides_[i] * MF::rotate3d(rotation, rotationPoint, normal);
}

void SpaceShip::turnVertical(bool up)
{
	Matrix top = sides_[0];
	float** topMatrix = top.getMatrix();
	Vector rotationAxis(3);
	rotationAxis.setItem(0, topMatrix[0][2] - topMatrix[0][1]);
	rotationAxis.setItem(1, topMatrix[1][2] - topMatrix[1][1]);
	rotationAxis.setItem(2, topMatrix[2][2] - topMatrix[2][1]);
	rotationAxis.normalize();
	Vector rotationPoint(3);
	rotationPoint.setItem(0, topMatrix[0][1] + (topMatrix[0][2] - topMatrix[0][1]) / 2);
	rotationPoint.setItem(1, topMatrix[1][1] + (topMatrix[1][2] - topMatrix[1][1]) / 2);
	rotationPoint.setItem(2, topMatrix[2][1] + (topMatrix[2][2] - topMatrix[2][1]) / 2);
	float rotation = 10;
	if (up)
		rotation = -rotation;
	for (int i = 0; i < sides_.size(); i++)
		sides_[i] = sides_[i] * MF::rotate3d(rotation, rotationPoint, rotationAxis);
}

void SpaceShip::roll(bool left)
{
	Matrix back = sides_[4];
	float** backMatrix = back.getMatrix();
	Vector backVector1(3);
	backVector1.setItem(0, backMatrix[0][0]);
	backVector1.setItem(1, backMatrix[1][0]);
	backVector1.setItem(2, backMatrix[2][0]);
	Vector backVector2(3);
	backVector2.setItem(0, backMatrix[0][1]);
	backVector2.setItem(1, backMatrix[1][1]);
	backVector2.setItem(2, backMatrix[2][1]);
	Vector backVector3(3);
	backVector3.setItem(0, backMatrix[0][2]);
	backVector3.setItem(1, backMatrix[1][2]);
	backVector3.setItem(2, backMatrix[2][2]);
	Vector direction1 = backVector1 - backVector2;
	Vector direction2 = backVector2 - backVector3;
	Vector normal = direction1.crossProduct(direction2);
	normal.normalize();
	Vector rotationPoint(3);
	rotationPoint.setItem(0, backMatrix[0][0] + (backMatrix[0][1] - backMatrix[0][0]) / 2);
	rotationPoint.setItem(1, backMatrix[1][0] + (backMatrix[1][1] - backMatrix[1][0]) / 2);
	rotationPoint.setItem(2, backMatrix[2][0] + (backMatrix[2][1] - backMatrix[2][0]) / 2);
	std::vector<float> normalVector = normal.getVector();
	float rotation = 10;
	if (!left)
		rotation = -rotation;
	for (int i = 0; i < sides_.size(); i++)
		sides_[i] = sides_[i] * MF::rotate3d(rotation, rotationPoint, normal);
}

Bullet SpaceShip::shoot()
{
	Matrix back = sides_[4];
	float** backMatrix = back.getMatrix();
	Vector backVector1(3);
	backVector1.setItem(0, backMatrix[0][0]);
	backVector1.setItem(1, backMatrix[1][0]);
	backVector1.setItem(2, backMatrix[2][0]);
	Vector backVector2(3);
	backVector2.setItem(0, backMatrix[0][1]);
	backVector2.setItem(1, backMatrix[1][1]);
	backVector2.setItem(2, backMatrix[2][1]);
	Vector backVector3(3);
	backVector3.setItem(0, backMatrix[0][2]);
	backVector3.setItem(1, backMatrix[1][2]);
	backVector3.setItem(2, backMatrix[2][2]);
	Vector direction1 = backVector1 - backVector2;
	Vector direction2 = backVector2 - backVector3;
	Vector normal = direction1.crossProduct(direction2);
	normal.normalize();
	std::vector<float> normalVector = normal.getVector();
	Matrix top = sides_[0];
	float** topMatrix = top.getMatrix();
	Vector start(3);
	start.setItem(0, topMatrix[0][0]);
	start.setItem(1, topMatrix[1][0]);
	start.setItem(2, topMatrix[2][0]);
	Vector end(3);
	end.setItem(0, topMatrix[0][0] + normalVector[0]);
	end.setItem(1, topMatrix[1][0] + normalVector[1]);
	end.setItem(2, topMatrix[2][0] + normalVector[2]);
	Bullet bullet(start, end);
	return bullet;
}

void SpaceShip::sightToggle()
{
	sight_ = !sight_;
}

Matrix SpaceShip::showSight()
{
	Matrix back = sides_[4];
	float** backMatrix = back.getMatrix();
	Vector backVector1(3);
	backVector1.setItem(0, backMatrix[0][0]);
	backVector1.setItem(1, backMatrix[1][0]);
	backVector1.setItem(2, backMatrix[2][0]);
	Vector backVector2(3);
	backVector2.setItem(0, backMatrix[0][1]);
	backVector2.setItem(1, backMatrix[1][1]);
	backVector2.setItem(2, backMatrix[2][1]);
	Vector backVector3(3);
	backVector3.setItem(0, backMatrix[0][2]);
	backVector3.setItem(1, backMatrix[1][2]);
	backVector3.setItem(2, backMatrix[2][2]);
	Vector direction1 = backVector1 - backVector2;
	Vector direction2 = backVector2 - backVector3;
	Vector normal = direction1.crossProduct(direction2);
	normal.normalize();
	std::vector<float> normalVector = normal.getVector();
	Matrix top = sides_[0];
	float** topMatrix = top.getMatrix();
	Vector start(3);
	start.setItem(0, topMatrix[0][0]);
	start.setItem(1, topMatrix[1][0]);
	start.setItem(2, topMatrix[2][0]);
	Vector end(3);
	end.setItem(0, topMatrix[0][0] + 300 * normalVector[0]);
	end.setItem(1, topMatrix[1][0] + 300 * normalVector[1]);
	end.setItem(2, topMatrix[2][0] + 300 * normalVector[2]);
	Matrix matrix(3, 2);
	matrix.setItem(0, start);
	matrix.setItem(1, end);
	return matrix;
}

void SpaceShip::createTop()
{
	Vector vector1(3);
	vector1.setItem(0, 15);
	vector1.setItem(1, 0);
	vector1.setItem(2, 5);
	Vector vector2(3);
	vector2.setItem(0, -15);
	vector2.setItem(1, 10);
	vector2.setItem(2, 5);
	Vector vector3(3);
	vector3.setItem(0, -15);
	vector3.setItem(1, -10);
	vector3.setItem(2, 5);
	Matrix matrix(3, 3);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	sides_.push_back(matrix);
}

void SpaceShip::createBottom()
{
	Vector vector1(3);
	vector1.setItem(0, 15);
	vector1.setItem(1, 0);
	vector1.setItem(2, -5);
	Vector vector2(3);
	vector2.setItem(0, -15);
	vector2.setItem(1, 10);
	vector2.setItem(2, -5);
	Vector vector3(3);
	vector3.setItem(0, -15);
	vector3.setItem(1, -10);
	vector3.setItem(2, -5);
	Matrix matrix(3, 3);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	sides_.push_back(matrix);
}

void SpaceShip::createLeft()
{
	Vector vector1(3);
	vector1.setItem(0, 15);
	vector1.setItem(1, 0);
	vector1.setItem(2, 5);
	Vector vector2(3);
	vector2.setItem(0, -15);
	vector2.setItem(1, 10);
	vector2.setItem(2, 5);
	Vector vector3(3);
	vector3.setItem(0, -15);
	vector3.setItem(1, 10);
	vector3.setItem(2, -5);
	Vector vector4(3);
	vector4.setItem(0, 15);
	vector4.setItem(1, 0);
	vector4.setItem(2, -5);
	Matrix matrix(3, 4);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	sides_.push_back(matrix);
}

void SpaceShip::createRight()
{
	Vector vector1(3);
	vector1.setItem(0, 15);
	vector1.setItem(1, 0);
	vector1.setItem(2, 5);
	Vector vector2(3);
	vector2.setItem(0, -15);
	vector2.setItem(1, -10);
	vector2.setItem(2, 5);
	Vector vector3(3);
	vector3.setItem(0, -15);
	vector3.setItem(1, -10);
	vector3.setItem(2, -5);
	Vector vector4(3);
	vector4.setItem(0, 15);
	vector4.setItem(1, 0);
	vector4.setItem(2, -5);
	Matrix matrix(3, 4);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	sides_.push_back(matrix);
}

void SpaceShip::createBack()
{
	Vector vector1(3);
	vector1.setItem(0, -15);
	vector1.setItem(1, 10);
	vector1.setItem(2, 5);
	Vector vector2(3);
	vector2.setItem(0, -15);
	vector2.setItem(1, -10);
	vector2.setItem(2, 5);
	Vector vector3(3);
	vector3.setItem(0, -15);
	vector3.setItem(1, -10);
	vector3.setItem(2, -5);
	Vector vector4(3);
	vector4.setItem(0, -15);
	vector4.setItem(1, 10);
	vector4.setItem(2, -5);
	Matrix matrix(3, 4);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	sides_.push_back(matrix);
}
