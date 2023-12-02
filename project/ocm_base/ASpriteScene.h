#pragma once
#include "GameObject.h"
#include "GameObjectCollection.h"
#include "BaseScene.h"
#include "SceneStateMachine.h"
#include "AnimatedSpriteRendererComponent.h"
#include "SpriteRendererComponent.h"
#include "InputSystem.h"
#include <iostream>

using namespace KanataEngine;

namespace AnimationShowcaseScene {

	/**
	 * @class ASpriteScene
	 * @brief Represents a specific scene in the application showcasing animated sprites and user input.
	*
	* The ASpriteScene class is derived from BaseScene and is designed to demonstrate animated sprite rendering and user input handling.
	 * It initializes and manages various properties related to sprite movement, rotation, and animation.
	 * The scene showcases different sprite images, both background and animated, to create a visually appealing animation showcase.
	 */

	class ASpriteScene : public BaseScene
	{
	public:
		std::string getName() const override;

		void skipScene();

	protected:
		void initialize() override;

		void ObjScale();

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

		bool isMovingHorizontally = false;
		bool isMovingVertically = false;

		InputSystem inputSystem;
		TransformComponent* transformComponent;
		AnimatedSpriteRenderer* animatedSpriteRenderer[4];
		SpriteRendererComponent* spriteRendererCompoenent;

		std::vector<std::string> bgSprites{
			"../assets/grass.jpg",
		};

		std::vector<std::string> sprites = {
			"../assets/kanata2D/front1.png",
			"../assets/kanata2D/front2.png",
			"../assets/kanata2D/front3.png",
			"../assets/kanata2D/back1.png",
			"../assets/kanata2D/back2.png",
			"../assets/kanata2D/back3.png",
			"../assets/kanata2D/left1.png",
			"../assets/kanata2D/left2.png",
			"../assets/kanata2D/left3.png",
			"../assets/kanata2D/right1.png",
			"../assets/kanata2D/right2.png",
			"../assets/kanata2D/right3.png",
		};

	};

}



