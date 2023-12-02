#pragma once
#include "BaseScene.h"
#include "SceneStateMachine.h"
#include <iostream>
#include <glad/glad.h>
#include "InputSystem.h"
#include "GameObject.h"
#include "GameObjectCollection.h"
#include "SpriteRendererComponent.h"

using namespace KanataEngine;

namespace SplashArtScene {

	/**
	* @class SplashScene
	* @brief Contains classes related to the splash art scene of the application.
	*
	 * The SplashArtScene namespace encapsulates classes specific to the splash art scene of the application.
	* It defines a SplashScene class that inherits from BaseScene and showcases loading behavior,
	* input handling, rendering, and managing game objects and their behaviors related to the splash art display.
	*/

	/**
	* @class Test_Foo_Component
	* @brief Contains classes related to the splash art scene of the application.
	*
	* The SplashArtScene namespace encapsulates classes specific to the splash art scene of the application.
	* It defines a SplashScene class that inherits from BaseScene and showcases loading behavior,
	* input handling, rendering, and managing game objects and their behaviors related to the splash art display.
	*/

	class SplashScene : public BaseScene
	{
	public:
		float time = 0.0f;

		std::string getName() const override;

		void skipScene();

		void loadGameObj();

	protected:
		void initialize() override;

		void on_activate() override;

		void on_update(float deltaTime) override;

		void on_render() override;

	private:
		SpriteRendererComponent* spriteRendererComponent[3];

		InputSystem inputSystem;

		std::vector<std::string> sprites = {
			"../assets/kanataSA.jpg",
			"../assets/details.png",
			"../assets/title.png",
		};

	};

	class Test_Foo_Component : public BaseComponent {
	public:
		Test_Foo_Component(GameObject* go) : BaseComponent(go) {
			std::cout << "Created Test_Foo_Component on " << gameObject->getName().c_str() << std::endl;
		}

		~Test_Foo_Component() {
			std::cout << "Destroying Test_Foo_Component on " << gameObject->getName().c_str() << std::endl;
		}

	};

}



