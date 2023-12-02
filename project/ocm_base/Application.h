#pragma once
#include "AppWindow.h"
#include "Time.h"

#include "SceneStateMachine.h"
#include "GameObjectCollection.h"
#include "GameObject.h"
#include "BaseScene.h"

#include "SplashScene.h"
#include "LoadGameScene.h"
#include "GameScene.h"
#include "GameSceneOne.h"
#include "ASpriteScene.h"

#include <iostream>
#include <glad/glad.h>
#include <string>
#include <sstream>

#include "InputSystem.h"

using namespace SplashArtScene;


namespace KanataEngine {

	/**
	* @class Application
	* @brief Manages the main application loop, scenes, and input.
	*
	* The Application class is responsible for initializing the application, running the main loop, and handling various events.
	* It maintains a collection of scenes and handles window events. It also manages the target frame rate and frame time calculation.
	*/

	enum class WindowsEvent {
		eventUnknown,
		eventClose,
		eventFramebufferResize
	};

	class Application
	{
	public:
		InputSystem inputSystem;

		void frameTimeCalculation(unsigned int targetFrameRate);
		void window_close_callback(::GLFWwindow* window);
		static void setTargetFrameRate(unsigned int targetFrameRate);
		void onReceiveWindowEvent(WindowsEvent eventT, void* payload);

		int initialize(int width, int height, const char* title);
		void run();
		void shutdown();

		SplashScene splashScene;
		SceneStateMachine* sceneStateMachine;
		GameObjectCollection* gameObjectcollection{};

	private:
		AppWindow* window;
		::GLFWwindow* windows;
		Time* timer;
		bool isRunning;

	};

}



