#include "LoadGameScene.h"

namespace LoadingScene {

	std::string LoadGameScene::getName() const
	{
		return "LoadGameScene";
	}

	void LoadGameScene::skipScene()
	{
		SceneStateMachine::loadScene(2);
	}

	void LoadGameScene::sceneLoadedChange()
	{
		if (progressBarComponent->progress >= 1.0f)
		{
			SceneStateMachine::loadScene(2);
		}
	}

	void LoadGameScene::initialize()
	{
		GameObject* go = new GameObject("ProgressBarObj");
		go->addComponent<ProgressBarComponent>();
		progressBarComponent = go->getComponent<ProgressBarComponent>();
		progressBarComponent->setInitialPosition({ -250.0f, -100.0f });
		progressBarComponent->setTargetProgress(100.0f);
		progressBarComponent->setSize({ 500.0f, 50.0f });
		progressBarComponent->setBarWidth(500.0f);

	}

	void LoadGameScene::on_activate()
	{
		glClearColor(1, 1, 1, 1);
	}

	void LoadGameScene::on_update(float deltaTime)
	{
		time += deltaTime;

		if (inputSystem.getKeyDown(GLFW_KEY_SPACE) && SceneStateMachine::sceneIndex == 1) {
			skipScene();
		}

		sceneLoadedChange();

	}


	void LoadGameScene::render()
	{
		progressBarComponent->render();
	}
}



