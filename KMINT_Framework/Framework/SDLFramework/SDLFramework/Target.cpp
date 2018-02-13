#include "Target.h"

Target::Target()
{
	createTop();
	createBottom();
	createLeft();
	createRight();
	createFront();
	createBack();
	scaleFactor_ = 0.99;
	startTime_ = std::chrono::system_clock::now();
}

Target::~Target()
{
}

void Target::show(FWApplication* application, Vector eye, Vector lookAt)
{
	application->SetColor(Color(0, 255, 255, 255));
	for (int i = 0; i < matrix_.size(); i++)
		matrix_[i].show3d(application, eye, lookAt);
}

void Target::update()
{
	std::chrono::duration<double> time = std::chrono::system_clock::now() - startTime_;
	if (time.count() > 0.5)
	{
		startTime_ = std::chrono::system_clock::now();
		scaleFactor_ = 2 - scaleFactor_;
	}
	for (int i = 0; i < matrix_.size(); i++)
		matrix_[i] = matrix_[i] * MF::translate3d(-500, -500, -500) * MF::scale3d(scaleFactor_, scaleFactor_, scaleFactor_) * MF::translate3d(500, 500, 500);
}

void Target::createTop()
{
	Vector vector1(3);
	vector1.setItem(0, 400);
	vector1.setItem(1, 400);
	vector1.setItem(2, 400);
	Vector vector2(3);
	vector2.setItem(0, 600);
	vector2.setItem(1, 400);
	vector2.setItem(2, 400);
	Vector vector3(3);
	vector3.setItem(0, 600);
	vector3.setItem(1, 600);
	vector3.setItem(2, 400);
	Vector vector4(3);
	vector4.setItem(0, 400);
	vector4.setItem(1, 600);
	vector4.setItem(2, 400);
	Matrix matrix(3, 4);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	matrix_.push_back(matrix);
}

void Target::createBottom()
{
	Vector vector1(3);
	vector1.setItem(0, 400);
	vector1.setItem(1, 400);
	vector1.setItem(2, 600);
	Vector vector2(3);
	vector2.setItem(0, 600);
	vector2.setItem(1, 400);
	vector2.setItem(2, 600);
	Vector vector3(3);
	vector3.setItem(0, 600);
	vector3.setItem(1, 600);
	vector3.setItem(2, 600);
	Vector vector4(3);
	vector4.setItem(0, 400);
	vector4.setItem(1, 600);
	vector4.setItem(2, 600);
	Matrix matrix(3, 4);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	matrix_.push_back(matrix);
}

void Target::createLeft()
{
	Vector vector1(3);
	vector1.setItem(0, 400);
	vector1.setItem(1, 400);
	vector1.setItem(2, 400);
	Vector vector2(3);
	vector2.setItem(0, 600);
	vector2.setItem(1, 400);
	vector2.setItem(2, 400);
	Vector vector3(3);
	vector3.setItem(0, 600);
	vector3.setItem(1, 400);
	vector3.setItem(2, 600);
	Vector vector4(3);
	vector4.setItem(0, 400);
	vector4.setItem(1, 400);
	vector4.setItem(2, 600);
	Matrix matrix(3, 4);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	matrix_.push_back(matrix);
}

void Target::createRight()
{
	Vector vector1(3);
	vector1.setItem(0, 400);
	vector1.setItem(1, 600);
	vector1.setItem(2, 600);
	Vector vector2(3);
	vector2.setItem(0, 400);
	vector2.setItem(1, 600);
	vector2.setItem(2, 400);
	Vector vector3(3);
	vector3.setItem(0, 600);
	vector3.setItem(1, 600);
	vector3.setItem(2, 400);
	Vector vector4(3);
	vector4.setItem(0, 600);
	vector4.setItem(1, 600);
	vector4.setItem(2, 600);
	Matrix matrix(3, 4);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	matrix_.push_back(matrix);
}

void Target::createFront()
{
	Vector vector1(3);
	vector1.setItem(0, 600);
	vector1.setItem(1, 600);
	vector1.setItem(2, 400);
	Vector vector2(3);
	vector2.setItem(0, 600);
	vector2.setItem(1, 600);
	vector2.setItem(2, 600);
	Vector vector3(3);
	vector3.setItem(0, 600);
	vector3.setItem(1, 400);
	vector3.setItem(2, 600);
	Vector vector4(3);
	vector4.setItem(0, 600);
	vector4.setItem(1, 400);
	vector4.setItem(2, 400);
	Matrix matrix(3, 4);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	matrix_.push_back(matrix);
}

void Target::createBack()
{
	Vector vector1(3);
	vector1.setItem(0, 400);
	vector1.setItem(1, 400);
	vector1.setItem(2, 400);
	Vector vector2(3);
	vector2.setItem(0, 400);
	vector2.setItem(1, 400);
	vector2.setItem(2, 600);
	Vector vector3(3);
	vector3.setItem(0, 400);
	vector3.setItem(1, 600);
	vector3.setItem(2, 600);
	Vector vector4(3);
	vector4.setItem(0, 400);
	vector4.setItem(1, 600);
	vector4.setItem(2, 400);
	Matrix matrix(3, 4);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	matrix_.push_back(matrix);
}
