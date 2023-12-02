#pragma once
#include <iostream>
#include "GameObject.h"
#include "BaseComponent.h"

namespace KanataEngine {

	/**
	* @class TransformComponent
	* @brief Contains classes and utilities for the KanataEngine application.
	*
	* The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
	* It includes a TransformComponent class that represents a component for managing object transformations.
	*/

	class TransformComponent : public BaseComponent
	{
	public:

		TransformComponent(GameObject* go);
		~TransformComponent();

		virtual void awake();
		virtual void start();
		virtual void update(float deltaTime);
		virtual void render();

		float getX() const;
		float getY() const;
		float getRotation() const;

		void setX(float value);
		void setY(float value);
		void setRotation(float value);

	protected:
		float x, y, rotation;

	};

}

