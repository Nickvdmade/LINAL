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
#include "Camera.h"

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

	Camera camera;

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
				case SDLK_i:
					camera.moveForward();
					break;
				case SDLK_k:
					camera.moveBackward();
					break;
				case SDLK_j:
					camera.moveLeft();
					break;
				case SDLK_l:
					camera.moveRight();
					break;
				case SDLK_u:
					camera.turnLeft();
					break;
				case SDLK_o:
					camera.turnRight();
					break;
				case SDLK_PAGEUP:
					camera.moveCloser();
					break;
				case SDLK_PAGEDOWN:
					camera.moveFurther();
					break;
				default:
					break;
				}
			}
		}

		application->SetColor(Color(0, 0, 0, 255));
		try
		{
			Vector eye = camera.getEye();
			Vector lookAt = camera.getLookAt();
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
			return EXIT_FAILURE;
		}

		// For the background
		application->SetColor(Color(0, 0, 0, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}
