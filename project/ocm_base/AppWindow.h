#pragma once

#include <functional>
#include <string>
#include <glfw/glfw3.h>

	// forward declare instead of including glfw library
	// to not expose glfw to Application.

namespace KanataEngine {

	/**
	* @class AppWindow
	* @brief Represents an application window and provides window management functionality.
	*
	* The AppWindow class encapsulates the creation and management of an application window using GLFW.
	* It provides functions to create a window, swap buffers, and set window event callbacks.
	* The class also defines a WindowEventCallbackFn type for handling window events and a WindowData structure to hold window-related data.
	*/

	/**
	* @struct WindowData
	* @brief Represents an application window and provides window management functionality.
	*
	* The AppWindow class encapsulates the creation and management of an application window using GLFW.
	* It provides functions to create a window, swap buffers, and set window event callbacks.
	* The class also defines a WindowEventCallbackFn type for handling window events and a WindowData structure to hold window-related data.
	*/

	typedef std::function<void(std::string, void*)> WindowEventCallbackFn;

	struct WindowData {
		int width = 0;
		int height = 0;
		std::string title;
		WindowEventCallbackFn callback;
	};

	class AppWindow
	{
	public:
		~AppWindow(); // destructor
		int create(int width, int height, const char* title);
		void swap_and_poll();
		void setWindowEventCallback(const WindowEventCallbackFn& fn);
		static GLFWwindow* window;


	private:

		GLFWwindow* internalWindow;
		WindowData data;
	};

	}





