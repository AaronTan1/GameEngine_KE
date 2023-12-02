#include "Application.h"

namespace KanataEngine {

	static float frameTime = 0.0f;
	unsigned int targetFrameRate = 120;
	bool isRunning = true;
	float r = 0.0f, g = 1.0f, b = 1.0f;
	float x = 0.0f, y = 0.0f;

	int Application::initialize(int width, int height, const char* title)
	{
		isRunning = true;
		window = new AppWindow();

		setTargetFrameRate(targetFrameRate);
		int result = window->create(width, height, title);

		if (result)
		{
			window->setWindowEventCallback([this](std::string eventT, void* payload)
				{
					WindowsEvent event = WindowsEvent::eventUnknown;

					if (eventT == "close") {
						event = WindowsEvent::eventClose;
					}

					if (eventT == "resize") {
						event = WindowsEvent::eventFramebufferResize;
					}

					onReceiveWindowEvent(event, payload);
				});
		}

		return result;
	}

	void Application::run()
	{
		// Scene Creation ------------------------------------------
		sceneStateMachine->addScene<SplashArtScene::SplashScene>();
		sceneStateMachine->addScene<LoadingScene::LoadGameScene>();
		sceneStateMachine->addScene<FirstScene::GameScene>();
		sceneStateMachine->addScene<SecondScene::GameSceneOne>();
		sceneStateMachine->addScene<AnimationShowcaseScene::ASpriteScene>();
		sceneStateMachine->loadScene(0); // SplashArt Scene first
		// ---------------------------------------------------------
		// 
		//GameObject* gameObject = new GameObject ("StorageObj"); tested

		// Application Loop
		// Loop as long as the window's close button is not clicked
		while (isRunning)
		{
			// Timing --------------------------------------------------------------
			float time = timer->process(frameTime);
			float deltaTime = timer->getDeltaTime();

			frameTimeCalculation(targetFrameRate);
			setTargetFrameRate(targetFrameRate);

			// ---------------------------------------------------------------------

			// Input Processing ----------------------------------------------------
			windows = glfwGetCurrentContext();
			inputSystem.processInput(windows);
			// ---------------------------------------------------------------------

			// Updates -------------------------------------------------------------
#pragma region Input
		//Close
			if (inputSystem.getKeyDown(GLFW_KEY_ESCAPE))
			{
				std::cout << "Window Close Input!" << std::endl;
				isRunning = false;
			}

			//Inspect & Find GameObject
			if (inputSystem.getKeyDown(GLFW_KEY_2))
			{
				gameObjectcollection->inspectGameObjects();
			}

			if (inputSystem.getKeyDown(GLFW_KEY_3))
			{
				gameObjectcollection->find("Spawned");
			}

			//A Key, 20 FPS
			if (inputSystem.getKeyDown(GLFW_KEY_Z))
			{
				targetFrameRate = 20;
				std::cout << "User just pressed A key, setting frame limit to " << targetFrameRate << " FPS" << std::endl;
			}
			else if (inputSystem.getKey(GLFW_KEY_Z))
			{
				std::cout << "User is holding A key" << std::endl;
			}
			else if (inputSystem.getKeyUp(GLFW_KEY_Z))
			{
				std::cout << "User just released A key" << std::endl;
			}

			//S Key, 60 FPS
			if (inputSystem.getKeyDown(GLFW_KEY_X))
			{
				targetFrameRate = 60;
				std::cout << "User just pressed S key, setting frame limit to " << targetFrameRate << " FPS" << std::endl;
			}

			//D Key, 0 FPS
			if (inputSystem.getKeyUp(GLFW_KEY_C))
			{
				targetFrameRate = 0;
				std::cout << "User just released D key, uncapping frame limit" << std::endl;
			}

			//Mouse Buttons & Positions

			//left
			if (inputSystem.getMouseKeyDown(GLFW_MOUSE_BUTTON_1))
			{
				std::cout << "User just pressed left mouse button, cursor located at " << inputSystem.mousePos.x << ", " << inputSystem.mousePos.y << std::endl;
			}
			else if (inputSystem.getMouseKey(GLFW_MOUSE_BUTTON_1))
			{
				std::cout << "User is holding left mouse button, cursor located at " << inputSystem.mousePos.x << ", " << inputSystem.mousePos.y << std::endl;
			}
			else if (inputSystem.getMouseKeyUp(GLFW_MOUSE_BUTTON_1))
			{
				std::cout << "User just released left mouse button, cursor located at " << inputSystem.mousePos.x << ", " << inputSystem.mousePos.y << std::endl;
			}

			//right
			if (inputSystem.getMouseKeyDown(GLFW_MOUSE_BUTTON_2))
			{
				std::cout << "User just pressed right mouse button, cursor located at " << inputSystem.mousePos.x << ", " << inputSystem.mousePos.y << std::endl;
			}
			else if (inputSystem.getMouseKey(GLFW_MOUSE_BUTTON_2))
			{
				std::cout << "User is holding right mouse button, cursor located at " << inputSystem.mousePos.x << ", " << inputSystem.mousePos.y << std::endl;
			}
			else if (inputSystem.getMouseKeyUp(GLFW_MOUSE_BUTTON_2))
			{
				std::cout << "User just released right mouse button, cursor located at " << inputSystem.mousePos.x << ", " << inputSystem.mousePos.y << std::endl;
			}

			//Other mapped keys
			//Q key
			if (inputSystem.getKeyDown(GLFW_KEY_Q))
			{
				std::cout << "User just pressed Q key" << std::endl;
			}
			else if (inputSystem.getKey(GLFW_KEY_Q))
			{
				std::cout << "User is holding Q key" << std::endl;
			}
			else if (inputSystem.getKeyUp(GLFW_KEY_Q))
			{
				std::cout << "User just released Q key" << std::endl;
			}

			//E key
			if (inputSystem.getKeyDown(GLFW_KEY_E))
			{
				std::cout << "User just pressed E key" << std::endl;
			}
			else if (inputSystem.getKey(GLFW_KEY_E))
			{
				std::cout << "User is holding E key" << std::endl;
			}
			else if (inputSystem.getKeyUp(GLFW_KEY_E))
			{
				std::cout << "User just released E key" << std::endl;
			}

			//R key
			if (inputSystem.getKeyDown(GLFW_KEY_R))
			{
				std::cout << "User just pressed R key" << std::endl;
			}
			else if (inputSystem.getKey(GLFW_KEY_R))
			{
				std::cout << "User is holding R key" << std::endl;
			}
			else if (inputSystem.getKeyUp(GLFW_KEY_R))
			{
				std::cout << "User just released R key" << std::endl;
			}

			//T key
			if (inputSystem.getKeyDown(GLFW_KEY_T))
			{
				std::cout << "User just pressed T key" << std::endl;
			}
			else if (inputSystem.getKey(GLFW_KEY_T))
			{
				std::cout << "User is holding T key" << std::endl;
			}
			else if (inputSystem.getKeyUp(GLFW_KEY_T))
			{
				std::cout << "User just released T key" << std::endl;
			}


			//extras (works but unused)
			//Any Key & Mouse
			//if (inputSystem.getAnyKeyDown(GLFW_KEY_W))
			//{
			//	std::cout << "Just Pressed W" << std::endl;
			//}

			//if (inputSystem.getAnyKey(GLFW_KEY_W))
			//{
			//	std::cout << "Pressing W" << std::endl;
			//}

			//if (inputSystem.getAnyKeyDown(GLFW_MOUSE_BUTTON_2))
			//{
			//	std::cout << "Just Pressed MB2" << std::endl;
			//}

			//if (inputSystem.getAnyKey(GLFW_MOUSE_BUTTON_2))
			//{
			//	std::cout << "Pressing MB2" << std::endl;
			//}

#pragma endregion Updates

		//comment to use initialize's title  (FPS counter)
		//std::stringstream ss;
		//ss << "FPS: " << 1.0f / deltaTime << std::endl;
		//glfwSetWindowTitle(windows, ss.str().c_str());

		// ---------------------------------------------------------------------

		// Scene Update -----------------------------------------------
			SceneStateMachine::update(deltaTime);
			/*std::cout << "Scene ind: " << sceneStateMachine->sceneIndex << std::endl;*/

			// ---------------------------------------------------------------------

			// Rendering -----------------------------------------------------------

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			SceneStateMachine::render();

			// ---------------------------------------------------------------------
			window->swap_and_poll();
		}
	}

	void Application::shutdown()
	{
		delete window;
	}

	void Application::frameTimeCalculation(unsigned int targetFrameRate)
	{
		frameTime /= targetFrameRate;
	}

	void Application::setTargetFrameRate(unsigned int targetFrameRate)
	{
		frameTime = targetFrameRate > 0 ? 1.0f / targetFrameRate : 0.0f;
	}

	void Application::window_close_callback(::GLFWwindow* window)
	{
		std::cout << "Window Close Callback!" << std::endl;
		isRunning = false;
	}


	void Application::onReceiveWindowEvent(WindowsEvent eventT, void* payload)
	{
		if (eventT == WindowsEvent::eventClose)
		{
			std::cout << "Window Close Event!" << std::endl;
			isRunning = false;
		}
		if (eventT == WindowsEvent::eventFramebufferResize)
		{
			std::cout << "Framebuffer Resize!" << std::endl;
		}
	}

}




