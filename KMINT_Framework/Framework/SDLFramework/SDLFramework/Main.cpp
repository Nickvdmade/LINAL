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
	
	Vector vector1(100, 50);
	Vector vector2(100, 100);
	Vector vector3(50, 100);
	Vector vector4(50, 50);
	Matrix matrix(4);
	matrix.setPoint(0, 100, 50);
	matrix.setPoint(1, 100, 100);
	matrix.setPoint(2, 50, 100);
	matrix.setPoint(3, 50, 50);

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