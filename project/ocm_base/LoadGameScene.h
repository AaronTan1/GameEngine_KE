#pragma once
#include "GameObject.h"
#include "GameObjectCollection.h"
#include "BaseScene.h"
#include "SceneStateMachine.h"
#include "InputSystem.h"
#include "RenderComponent.h"
#include "SpriteRendererComponent.h"
#include "ProgressBarComponent.h"
#include <iostream>
#include <glad/glad.h>
#include <vector>
#include <random>

namespace LoadingScene{

	/**
	* @class LoadGameScene
	* @brief Contains classes related to the loading scene of the application.
	*
	* The LoadingScene namespace encapsulates classes specific to the loading scene of the application.
	* It defines a LoadGameScene class that inherits from BaseScene and showcases loading behavior,
	* input handling, rendering, and managing game objects and their behaviors related to the loading process.
	*/

	class LoadGameScene : public BaseScene
	{
	public:
		float time = 0.0f;

		std::string getName() const override;

		void skipScene();

		void sceneLoadedChange();


	protected:
		void initialize() override;

		void on_activate() override;

		void on_update(float deltaTime) override;

		void render();

	private:
		ProgressBarComponent* progressBarComponent;
		InputSystem inputSystem;

	};

}



