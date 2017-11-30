#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Vector.h"
#include "Matrix.h"

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
	
	Vector vector1(2);
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
	Matrix matrix2(2, 2);
	matrix2.setItem(0, 0, 2);
	matrix2.setItem(0, 1, 0);
	matrix2.setItem(1, 0, 0);
	matrix2.setItem(1, 1, 2);
	Matrix matrix3 = matrix.scale(matrix2);

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
		matrix.show(application);
		matrix3.show(application);
		/*vector1.showLine(vector2, application);
		vector2.showLine(vector3, application);
		vector3.showLine(vector4, application);
		vector4.showLine(vector1, application);*/

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}