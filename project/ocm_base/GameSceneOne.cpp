#include "GameSceneOne.h"

namespace SecondScene {

	// Array to store the SpriteRendererComponents
	std::vector<SpriteRendererComponent*> spriteRenderComponents(9);

	std::vector<std::string> sprite = {
		"../assets/kanata2.png",
	};

	std::string GameSceneOne::getName() const
	{
		return "GameSceneOne";
	}

	void GameSceneOne::skipScene()
	{
		SceneStateMachine::loadScene(4);
	}

	void GameSceneOne::createGameObjectTwo()
	{

		for (int i = 0; i < spriteRenderComponents.size(); ++i)
		{
			GameObject* go = new GameObject("ShowcaseMoveObj " + std::to_string(i + 1));
			transformComponent[i] = go->getComponent<TransformComponent>();

			if (i >= 0 && i <= 2)
			{
				go->addComponent<SpriteRendererComponent>(-300.0f + i * 300.0f, 200.0f, sprite[0]);
				spriteRenderComponents[i] = go->getComponent<SpriteRendererComponent>();
				spriteRenderComponents[i]->setSize({ 150.0f, 150.0f });

			}
			else if (i >= 3 && i <= 5)
			{
				go->addComponent<SpriteRendererComponent>(-1280.0f + i * 300.0f, 0.0f, sprite[0]);
				spriteRenderComponents[i] = go->getComponent<SpriteRendererComponent>();
				spriteRenderComponents[i]->setPivot({ 0.0f, 0.5f });
				spriteRenderComponents[i]->setSize({ 150.0f, 150.0f });
			}
			else if (i >= 6 && i <= 8)
			{
				go->addComponent<SpriteRendererComponent>(-2100.0f + i * 300.0f, -300.0f, sprite[0]);
				spriteRenderComponents[i] = go->getComponent<SpriteRendererComponent>();
				spriteRenderComponents[i]->setPivot({ 0.5f, 0.0f });
				spriteRenderComponents[i]->setSize({ 150.0f, 150.0f });
			}

		}
	}

	void ObjScale()
	{
		static float currentTime = 0.0f;

		for (int i = 0; i < 9; i++)
		{
			Vec2 newSize = { 150.0f, 150.0f };

			float minSize = 100.0f;
			float maxSize = 200.0f;
			float scaleAmplitude = (maxSize - minSize) * 0.5f;
			float scaleFrequency = 0.5f;

			float scaleOffset = scaleAmplitude * sinf(scaleFrequency * currentTime);
			newSize.x = minSize + scaleAmplitude + scaleOffset;
			newSize.y = minSize + scaleAmplitude + scaleOffset;

			spriteRenderComponents[i]->setSize(newSize);
		}

		currentTime += 0.1f;
	}

	void GameSceneOne::initialize()
	{
		rot = 0.0f;
		createGameObjectTwo();
	}

	void GameSceneOne::on_activate()
	{
		glClearColor(0.3f, 0.3f, 0.5f, 1.0f);
	}

	void GameSceneOne::on_update(float deltaTime)
	{
		time += deltaTime;

		if (inputSystem.getKeyDown(GLFW_KEY_SPACE))
		{
			skipScene();
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
			rot = 90.0f;
		}
		if (inputSystem.getKeyDown(GLFW_KEY_E))
		{
			rot = -90.0f;
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

		newX = accumulatedXMovement;
		newY = accumulatedYMovement;

		//scaling
		if (inputSystem.getKey(GLFW_KEY_9))
		{
			ObjScale();
		}

		for (int i = 0; i < 9; ++i)
		{
			// Apply rotation and movement to each transform component
			transformComponent[i]->setRotation(fmodf(transformComponent[i]->getRotation() + rot * deltaTime, 360.0f));
			transformComponent[i]->setX(newX);
			transformComponent[i]->setY(newY);
		}

	}

}








