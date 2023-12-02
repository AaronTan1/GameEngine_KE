#include "GameScene.h"

namespace FirstScene {

	std::string GameScene::getName() const
	{
		return "GameScene";
	}

	void GameScene::skipSceneOne()
	{
		SceneStateMachine::loadScene(3);
	}

	void GameScene::initialize()
	{
		GameObject* go = new GameObject("EmptyObj");
		go->addComponent<EmptyObj_Component>();
	}

	void GameScene::on_activate()
	{
		glClearColor(0, 0.25, 0, 1);
	}

	void GameScene::on_update(float deltaTime)
	{
		time += deltaTime;

		if (inputSystem.getKeyDown(GLFW_KEY_SPACE)) {
			skipSceneOne();
		}
	}

}
