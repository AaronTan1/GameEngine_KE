#pragma once
// DO NOT #include "GameObject.h"
class GameObject; 
// forward declaration that GameObject class exists.  

namespace KanataEngine {

	/**
	 * @class BaseComponent
	 * @brief Represents a base class for components that can be attached to GameObjects.
	 *
	 * The BaseComponent class serves as the foundation for creating components that can be attached to GameObjects.
	 * It provides virtual functions for various lifecycle events like awake, start, update, and render.
	 * The class also includes functions to manage component destruction and determine if the component should be destroyed.
	 * Derived classes can implement specific behavior for each lifecycle event.
	 */

	class BaseComponent
	{
	public:
		BaseComponent(GameObject* go);
		virtual ~BaseComponent() = 0; // pure virtual  

		virtual void awake();
		virtual void start();
		virtual void update(float deltaTime);
		virtual void render();
		void destroy();
		bool shouldDestroy();
	protected:
		GameObject* gameObject;
		bool flaggedForDeletion = false;
	};

}

