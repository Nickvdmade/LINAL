#pragma once
#include "Vector.h"

class Camera
{
public:
	Camera();
	~Camera();
	Vector getEye();
	Vector getLookAt();
	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();
	void turnLeft();
	void turnRight();
	void moveCloser();
	void moveFurther();

private:
	Vector eye_;
	Vector lookAt_;
};
