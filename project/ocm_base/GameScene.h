#pragma once
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

namespace FirstScene {

	/**
	* @namespace GameScene
	* @brief Contains classes related to the first scene of the application.
	*
	* The FirstScene namespace encapsulates classes specific to the first scene of the application.
	* It defines a GameScene class that inherits from BaseScene and demonstrates component interactions,
	* input handling, rendering, and managing game objects and their behaviors.
	*/

	class GameScene : public BaseScene
	{
	public:
		float time = 0.0f;

		std::string getName() const override;

		void skipSceneOne();

		InputSystem inputSystem;

	protected:
		void initialize() override;

		void on_activate() override;

		void on_update(float deltaTime) override;

	};


	/**
	* @class Something_Component
	* @brief Contains classes and utilities for the KanataEngine application.
	*
	* The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
	* It includes classes related to managing textures and texture allocation.
	*/

	class Something_Component : public BaseComponent {
	public:
		Something_Component(GameObject* go) : BaseComponent(go), inputSystem(inputSystem)
		{
			std::cout << "Created Something_Component on " << gameObject->getName().c_str() << std::endl;
		}

		~Something_Component() {
			std::cout << "Destroying Something_Component on " << gameObject->getName().c_str() << std::endl;
		}

		InputSystem inputSystem;
		TransformComponent* transformComponent = gameObject->getComponent<TransformComponent>();
		//RenderComponent* renderComponent = gameObject->getComponent<RenderComponent>();

		void update(float deltaTime) override {
			time += deltaTime;

			//check Comp
			if (inputSystem.getKeyDown(GLFW_KEY_4))
			{
				gameObject->addedComponents();
			}

			//destroy gameObj
			if (inputSystem.getKeyDown(GLFW_KEY_0))
			{
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				gameObject->destroy();
			}

			//horizontal move
			if (inputSystem.getKey(GLFW_KEY_A))
			{
				accumulatedXMovement -= 200.0f * deltaTime;
			}
			if (inputSystem.getKey(GLFW_KEY_D))
			{
				accumulatedXMovement += 200.0f * deltaTime;
			}

			//rotate
			if (inputSystem.getKeyDown(GLFW_KEY_Q))
			{
				rot = 70.0f;
			}
			if (inputSystem.getKeyDown(GLFW_KEY_E))
			{
				rot = -70.0f;
			}
			if (inputSystem.getKeyDown(GLFW_KEY_R))
			{
				rot = 0.0f;
			}

			//vertical move

			if (inputSystem.getKey(GLFW_KEY_W))
			{
				accumulatedYMovement += 200.0f * deltaTime;
			}
			if (inputSystem.getKey(GLFW_KEY_S))
			{
				accumulatedYMovement -= 200.0f * deltaTime;
			}

			//float currentY = transformComponent->getY();

			//if (currentY >= -1.0f && currentY <= 1.0f) {
			//	newY = sinf(time) * 200.0f;
			//}
			//else {
			//	newY = sinf(time) * -200.0f;
			//}

			newX = accumulatedXMovement;
			newY = accumulatedYMovement;


			/*transformComponent->setRotation(rot * time);*/
			transformComponent->setRotation(fmodf(transformComponent->getRotation() + rot * deltaTime, 360.0f));
			transformComponent->setX(newX);
			transformComponent->setY(newY);

		}

		void render() override
		{
			//renderComponent->setRGB(1, 0, 0, 1);
		}

	private:
		float time = 0;
		float newY = 0;
		float newX = 0;
		float rot = 0;
		float accumulatedXMovement = 0.0f;
		float accumulatedYMovement = 0.0f;
		float currentRot = 0;
		float targetRot = 0;
	};


	/**
	* @class EmptyObj_Component
	* @brief Contains classes and utilities for the KanataEngine application.
	*
	* The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
	* It includes classes related to managing textures and texture allocation.
	*/

	class EmptyObj_Component : public BaseComponent {
	public:
		EmptyObj_Component(GameObject* go) : BaseComponent(go), inputSystem(inputSystem)
		{
			std::cout << "Created Empty_GameObject_Component on " << gameObject->getName().c_str() << std::endl;
		}

		~EmptyObj_Component() {
			std::cout << "Destroying Empty_GameObject_Component on " << gameObject->getName().c_str() << std::endl;
		}

		std::vector<std::string> sprites = {
			"../assets/kanata.png",
			"../assets/kanata2.png",
		};

		SpriteRendererComponent* spriteGameObject[3];

		void createGameObjectOne()
		{
			// Array to store the SpriteRendererComponents
			std::vector<SpriteRendererComponent*> spriteRendererComponents(8);

			for (int i = 0; i < spriteRendererComponents.size(); ++i)
			{
				GameObject* go = new GameObject("SpawnedObj " + std::to_string(i + 1));
				go->addComponent<Something_Component>();

				if (i >= 0 && i <= 3)
				{
					go->addComponent<SpriteRendererComponent>(-300.0f + i * 200.0f, 200.0f, sprites[0]);

					spriteRendererComponents[i] = go->getComponent<SpriteRendererComponent>();

					//Set opacity for each SpriteRendererComponent 
					float opacity = 1.0f - (i * 0.2f); // Adjust opacity based on index
					spriteRendererComponents[i]->setOpacity(opacity);
					spriteRendererComponents[i]->setSize({ 150.0f, 150.0f });

					if (i == 0) { //gets a reference
						spriteGameObject[0] = spriteRendererComponents[i];
					}
				}
				else if (i >= 4 && i <= 8) {

					go->addComponent<SpriteRendererComponent>(-1110.0f + i * 200.0f, -100.0f, sprites[1]);
					spriteRendererComponents[i] = go->getComponent<SpriteRendererComponent>();
					spriteRendererComponents[i]->setSize({ 200.0f, 200.0f });
					spriteRendererComponents[i]->setPivot({ 0.0f, 0.5f });

					if (i == 4) {
						spriteRendererComponents[i]->setColour({ 1.0f, 0.0f, 0.0f });
					}
					else if (i == 5) {
						spriteRendererComponents[i]->setColour({ 0.0f, 1.0f, 0.0f });
					}
					else if (i == 6)
					{
						spriteRendererComponents[i]->setColour({ 0.0f, 0.0f, 1.0f });

					}

					if (i == 7) { //gets a reference
						spriteGameObject[1] = spriteRendererComponents[i];
					}

				}

			}
		}

		void gameObjectChange()
		{
			//opacity change
			if (spriteGameObject[0] != nullptr)
			{
				float currentTime = time;
				float frequency = 0.5f;
				float amplitude = 0.5f;

				opacity = 0.5f + amplitude * sinf(2.0f * 3.14159f * frequency * currentTime);

				spriteGameObject[0]->setOpacity(opacity);
			}

			if (spriteGameObject[1] != nullptr)
			{
				// Generate random RGB values for color tinting
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_real_distribution<float> dis(0.0f, 1.0f);

				float red = dis(gen);
				float green = dis(gen);
				float blue = dis(gen);

				spriteGameObject[1]->setColour({ red, green, blue });
			}
		}

		void gameObjectRevert()
		{
			spriteGameObject[0]->setOpacity(1.0f);
			spriteGameObject[1]->setColour({ 1.0f, 1.0f, 1.0f });
		}

		void update(float deltaTime) override
		{
			time += deltaTime;

			if (inputSystem.getKeyDown(GLFW_KEY_1))
			{
				createGameObjectOne();
			}


			if (inputSystem.getKey(GLFW_KEY_MINUS))
			{
				gameObjectChange();
			}

		}

		//void render() override {

		//	//unused
		//	//renderComponent->setRGB(0, 0, 0);
		//	//
		//	//renderComponent->render();
		//}

	private:
		float time = 0;
		float opacity = 0.0f;
		InputSystem inputSystem;
		RenderComponent* renderComponent = gameObject->getComponent<RenderComponent>();
		//SpriteRendererComponent* spriteRendererComponent[4];

		// Get the active game objects
		//const std::unordered_set<GameObject*>& activeGameObjects = GameObjectCollection::getActiveGameObjects();

	};

}



