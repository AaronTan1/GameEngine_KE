#pragma once
#include <string>
#include <vector>
#include "GameObject.h"


namespace KanataEngine {

	/**
	* @class BaseScene
	* @brief Represents a base class for scenes in the application.
	*
	* The BaseScene class provides a framework for creating scenes in the application.
	* It defines functions for activating, deactivating, updating, and rendering scenes.
	* The class also includes virtual functions that allow derived classes to provide custom logic for scene initialization,
	* activation, deactivation, updating, and rendering.
	* Subclasses must implement the pure virtual function `getName()` to provide a unique name for the scene.
	*/

	class BaseScene
	{
	public:

		void activate();
		void deactivate();
		void update(float deltaTime);
		void render();

		virtual std::string getName() const = 0;

	protected:
		// pure virtual
		virtual void initialize() = 0;

		// virtual functions that are called by defined functions above
		// to allow subclasses to provide custom logic
		virtual void on_activate() {};
		virtual void on_deactivate() {};
		virtual void on_update(float deltaTime) {};
		virtual void on_render() {};
	};

}

