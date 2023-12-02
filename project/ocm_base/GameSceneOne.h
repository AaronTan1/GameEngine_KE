#include "GameObject.h"
#include "GameObjectCollection.h"
#include "BaseScene.h"
#include "SceneStateMachine.h"
#include "InputSystem.h"
#include "RenderComponent.h"
#include "SpriteRendererComponent.h"
#include <iostream>
#include <glad/glad.h>
#include <vector>
#include <random>

using namespace KanataEngine;

namespace SecondScene {

	/**
	* @class GameSceneOne
	* @brief Contains classes related to the second scene of the application.
	*
	* The SecondScene namespace encapsulates classes specific to the second scene of the application.
	* It defines a GameSceneOne class that inherits from BaseScene and showcases component interactions,
	* input handling, rendering, and managing game objects and their behaviors.
	*/

	class GameSceneOne : public BaseScene
	{
	public:
		float time = 0.0f;

		std::string getName() const override;

		void skipScene();

		void createGameObjectTwo();

	protected:
		void initialize() override;

		void on_activate() override;

		void on_update(float deltaTime) override;


	private:
		float newY = 0;
		float newX = 0;
		float rot = 0;
		float accumulatedXMovement = 0.0f;
		float accumulatedYMovement = 0.0f;
		float currentRot = 0;
		float targetRot = 0;

		InputSystem inputSystem;
		TransformComponent* transformComponent[9];


	};

}


