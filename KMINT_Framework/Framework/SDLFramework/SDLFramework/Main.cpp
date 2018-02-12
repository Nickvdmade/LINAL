#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Vector.h"
#include "Matrix.h"
#include "MF.h"
#include <complex>

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	
	/*Vector vector1(2);
	vector1.setItem(0, 100);
	vector1.setItem(1, 50);
	Vector vector2(2);
	vector2.setItem(0, 100);
	vector2.setItem(1, 100);
	Vector vector3(2);
	vector3.setItem(0, 50);
	vector3.setItem(1, 100);
	Vector vector4(2);
	vector4.setItem(0, 50);
	vector4.setItem(1, 50);
	Vector vector5(2);
	vector5.setItem(0, 75);
	vector5.setItem(1, 25);
	Matrix matrix(2, 5);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	matrix.setItem(4, vector5);
	Matrix mutatie = MF::translate2d(-50, -100) * MF::rotate2d(10) * MF::scale2d(2, 1) * MF::translate2d(50, 100);
	Matrix matrix2 = matrix * mutatie;*/

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
	Vector vector5(3);
	vector5.setItem(0, 400);
	vector5.setItem(1, 400);
	vector5.setItem(2, 600);
	Vector vector6(3);
	vector6.setItem(0, 600);
	vector6.setItem(1, 400);
	vector6.setItem(2, 600);
	Vector vector7(3);
	vector7.setItem(0, 600);
	vector7.setItem(1, 600);
	vector7.setItem(2, 600);
	Vector vector8(3);
	vector8.setItem(0, 400);
	vector8.setItem(1, 600);
	vector8.setItem(2, 600);
	Matrix matrix(3, 8);
	matrix.setItem(0, vector1);
	matrix.setItem(1, vector2);
	matrix.setItem(2, vector3);
	matrix.setItem(3, vector4);
	matrix.setItem(4, vector5);
	matrix.setItem(5, vector6);
	matrix.setItem(6, vector7);
	matrix.setItem(7, vector8);

	Vector eye(4);
	eye.setItem(0, 500);
	eye.setItem(1, 500);
	eye.setItem(2, 0);
	eye.setItem(3, 1);

	Vector lookAt(4);
	lookAt.setItem(0, 500);
	lookAt.setItem(0, 500);
	lookAt.setItem(2, 1000);
	lookAt.setItem(3, 1);

	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){

				default:
					break;
				}
			}
		}

		application->SetColor(Color(0, 0, 0, 255));
		matrix.show3d(application, eye, lookAt);
		/*matrix.show2d(application);
		matrix2.show2d(application);*/

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}