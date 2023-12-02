#pragma once
#include <glfw/glfw3.h>

namespace KanataEngine {

	/**
	* @class InputSystem
	* @brief Contains classes and utilities for the KanataEngine application.
	*
	* The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
	* It includes an InputSystem class to handle input processing and provides functions to query key and mouse button states.
	* Additionally, it defines a Vector2 struct to represent 2D coordinates.
	*/

	/**
	* @class Vector2
	* @brief Contains classes and utilities for the KanataEngine application.
	*
	* The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
	* It includes an InputSystem class to handle input processing and provides functions to query key and mouse button states.
	* Additionally, it defines a Vector2 struct to represent 2D coordinates.
	*/

	struct Vector2
	{
		double x;
		double y;
	};

	class InputSystem
	{
	public:
		void processInput(::GLFWwindow* window);
		bool getAnyKey(int key);
		bool getAnyKeyDown(int key);
		bool getKey(int key);
		bool getKeyDown(int key);
		bool getKeyUp(int key);
		bool getMouseKey(int Key);
		bool getMouseKeyDown(int key);
		bool getMouseKeyUp(int key);
		Vector2 mousePos;

	private:
		const Vector2 getMousePosition();
	};


}
