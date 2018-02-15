#include "Camera.h"

Camera::Camera()
{
	eye_ = Vector(4);
	eye_.setItem(0, 0);
	eye_.setItem(1, 0);
	eye_.setItem(2, 500);
	eye_.setItem(3, 1);

	lookAt_ = Vector(4);
	lookAt_.setItem(0, 250);
	lookAt_.setItem(1, 250);
	lookAt_.setItem(2, 0);
	lookAt_.setItem(3, 1);
}

Camera::~Camera()
{
}

Vector Camera::getEye()
{
	return eye_;
}

Vector Camera::getLookAt()
{
	return lookAt_;
}

void Camera::moveForward()
{
	Vector direction = lookAt_;
	direction.normalize3d();
	direction.absolute();
	lookAt_ = lookAt_ + direction.scale(10);
	eye_ = eye_ + direction.scale(10);
	//werkt niet zoals het hoort
}

void Camera::moveBackward()
{
	Vector direction = lookAt_;
	direction.normalize3d();
	direction.absolute();
	lookAt_ = lookAt_ - direction.scale(10);
	eye_ = eye_ - direction.scale(10);
	//werkt niet zoals het hoort
}

void Camera::moveLeft()
{
	// TODO: camera naar links bewegen
}

void Camera::moveRight()
{
	// TODO: camera naar rechts bewegen
}

void Camera::turnLeft()
{
	// TODO: camera naar links draaien
}

void Camera::turnRight()
{
	// TODO: camera naar rechts draaien
}

void Camera::moveCloser()
{
	Vector direction = lookAt_ - eye_;
	direction.normalize3d();
	eye_ = eye_ + direction.scale(10);
}

void Camera::moveFurther()
{
	Vector direction = lookAt_ - eye_;
	direction.normalize3d();
	eye_ = eye_ - direction.scale(10);
}
