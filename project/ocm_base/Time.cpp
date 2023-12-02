#include "Time.h"
#include <glfw/glfw3.h>

namespace KanataEngine {

	float Time::time = 0.0f;
	float Time::prevTime = 0.0f;
	float Time::deltaTime = 0.0f;

	float Time::process(float frameTime)
	{
		time = glfwGetTime();
		deltaTime = time - prevTime;

		//FRAME LIMITING
		while (deltaTime < frameTime)
		{
			time = glfwGetTime();
			deltaTime = time - prevTime;
		}

		prevTime = time; // cache the current time for next update.

		/*std::cout << "dt: " << deltaTime << std::endl;*/

		return time;
	}

	float Time::getDeltaTime()
	{
		return deltaTime;
	}

}







