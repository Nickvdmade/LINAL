#pragma once
#include "Matrix.h"
#include "MF.h"
#include <chrono>

class Target
{
public:
	Target();
	~Target();
	void show(FWApplication* application, Vector eye, Vector lookAt);
	void update();

private:
	std::vector<Matrix> matrix_;
	float scaleFactor_;
	std::chrono::system_clock::time_point startTime_;

	void createTop();
	void createBottom();
	void createLeft();
	void createRight();
	void createFront();
	void createBack();
};
