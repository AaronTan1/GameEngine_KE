#include "ASpriteScene.h"

namespace AnimationShowcaseScene {

	std::string ASpriteScene::getName() const
	{
		return "ASpriteScene";
	}

	void ASpriteScene::skipScene()
	{
		SceneStateMachine::loadScene(0);
	}

	void ASpriteScene::initialize()
	{
		rot = 0.0f;

		// Create background object
		GameObject* bgObj = new GameObject("backgroundObj");
		spriteRendererCompoenent = bgObj->addComponent<SpriteRendererComponent>(0.0f, 0.0f, bgSprites[0]);
		spriteRendererCompoenent->setSize({ 500.0f, 500.f });

		// Create the animated sprite object
		GameObject* characterObj = new GameObject("CharacterAnimatedSpriteObj");
		transformComponent = characterObj->getComponent<TransformComponent>();

		animatedSpriteRenderer[0] = characterObj->addComponent<AnimatedSpriteRenderer>(-100.0f, 100.0f, sprites[0]);  // Pass the entire vector of animation paths
		animatedSpriteRenderer[1] = characterObj->addComponent<AnimatedSpriteRenderer>(100.0f, 100.0f, sprites[3]);
		animatedSpriteRenderer[2] = characterObj->addComponent<AnimatedSpriteRenderer>(100.0f, -100.0f, sprites[6]);
		animatedSpriteRenderer[3] = characterObj->addComponent<AnimatedSpriteRenderer>(-100.0f, -100.0f, sprites[9]);

		for (int i = 0; i <= 2; i++)
		{
			animatedSpriteRenderer[0]->addAnimationFrame(sprites[i]);
		}

		for (int i = 3; i <= 5; i++)
		{
			animatedSpriteRenderer[1]->addAnimationFrame(sprites[i]);
		}

		for (int i = 6; i <= 8; i++)
		{
			animatedSpriteRenderer[2]->addAnimationFrame(sprites[i]);
		}

		for (int i = 9; i <= 11; i++)
		{
			animatedSpriteRenderer[3]->addAnimationFrame(sprites[i]);
		}


		for (int i = 0; i <= 3; i++)
		{
			// Set the pivot, size, and initial animation frame
			animatedSpriteRenderer[i]->setSize({ 100.0f, 100.0f });
			animatedSpriteRenderer[i]->setPivot({ 0.5f, 0.5f });
		}
	}

	void ASpriteScene::ObjScale()
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


			for (int i = 0; i <= 3; i++)
			{
				animatedSpriteRenderer[i]->setSize(newSize);
			}

		}

		currentTime += 0.1f;
	}

	void ASpriteScene::on_activate()
	{
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	}

	void ASpriteScene::on_update(float deltaTime)
	{

		if (inputSystem.getKeyDown(GLFW_KEY_SPACE))
		{
			skipScene();
		}

		animatedSpriteRenderer[0]->playAnimation(deltaTime * 0.5f);
		animatedSpriteRenderer[1]->playAnimation(deltaTime * 0.5f);
		animatedSpriteRenderer[2]->playAnimation(deltaTime * 0.5f);
		animatedSpriteRenderer[3]->playAnimation(deltaTime * 0.5f);

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

		//scaling
		if (inputSystem.getKey(GLFW_KEY_9))
		{
			ObjScale();
		}

		transformComponent->setRotation(fmodf(transformComponent->getRotation() + rot * deltaTime, 360.0f));
		transformComponent->setX(newX);
		transformComponent->setY(newY);

	}

}


