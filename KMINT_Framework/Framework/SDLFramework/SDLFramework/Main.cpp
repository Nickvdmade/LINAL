#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include <time.h>
#include "Vector.h"
#include <complex>
#include "SpaceShip.h"
#include <chrono>
#include "Target.h"

std::chrono::system_clock::time_point bulletStepTime;
std::chrono::system_clock::time_point targetStepTime;
std::chrono::duration<double> bulletStepTimer;
std::chrono::duration<double> targetStepTimer;
double bulletStepDuration = 0.01;
double targetStepDuration = 0.01;

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

	Vector eye(4);
	eye.setItem(0, -500);
	eye.setItem(1, -200);
	eye.setItem(2, -300);
	eye.setItem(3, 1);

	Vector lookAt(4);
	lookAt.setItem(0, 100);
	lookAt.setItem(1, 100);
	lookAt.setItem(2, 200);
	lookAt.setItem(3, 1);

	SpaceShip spaceShip;
	std::vector<Bullet> bullets;
	Target target;

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
				case SDLK_LSHIFT:
					spaceShip.moveForward();
					break;
				case SDLK_a:
					spaceShip.turnHorizontal(true);
					break;
				case SDLK_d:
					spaceShip.turnHorizontal(false);
					break;
				case SDLK_w:
					spaceShip.turnVertical(true);
					break;
				case SDLK_s:
					spaceShip.turnVertical(false);
					break;
				case SDLK_q:
					spaceShip.roll(true);
					break;
				case SDLK_e:
					spaceShip.roll(false);
					break;
				case SDLK_SPACE:
					bullets.push_back(spaceShip.shoot());
					break;
				case SDLK_h:
					spaceShip.sightToggle();
					break;
				default:
					break;
				}
			}
		}

		application->SetColor(Color(0, 0, 0, 255));
		try
		{
			spaceShip.show(application, eye, lookAt);
			target.show(application, eye, lookAt);
			targetStepTimer = std::chrono::system_clock::now() - targetStepTime;
			if (targetStepTimer.count() > targetStepDuration)
			{
				target.update();
				targetStepTime = std::chrono::system_clock::now();
			}
			bulletStepTimer = std::chrono::system_clock::now() - bulletStepTime;
			for (auto i = bullets.begin(); i < bullets.end(); ++i)
			{
				auto& item = *i;
				if (bulletStepTimer.count() > bulletStepDuration)
				{
					item.update();
					bulletStepTime = std::chrono::system_clock::now();
				}
				item.show(application, eye, lookAt);
			}
		}
		catch(std::exception& ex)
		{
			std::cerr << ex.what() << std::endl;
		}
		/*matrix.show2d(application);
		matrix2.show2d(application);*/

		// For the background
		application->SetColor(Color(0, 0, 0, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}
