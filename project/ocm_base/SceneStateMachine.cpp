#include "SceneStateMachine.h"

namespace KanataEngine {

	std::unordered_map<std::string, BaseScene*> SceneStateMachine::scenes;
	BaseScene* SceneStateMachine::currentScene;
	unsigned int SceneStateMachine::sceneIdCounter;
	unsigned int SceneStateMachine::sceneIndex;

	/*void SceneStateMachine::loadScene(const std::string name)
	{
		// 1. Look for the scene matching the name
		// 2. If found:
		//    a. Deactivate currentScene, if there is one (Note: there won't be one on launch!)
		//    b. Point currentScene to the new scene.
		//    c. Activate the new scene.
		// 3. Otherwise, log error

		auto it = scenes.find(name);

		if (it != scenes.end())
		{
			if (currentScene != nullptr)
			{
				currentScene->deactivate();
			}

			currentScene = it->second;
			currentScene->activate();
		}
		else
		{
			std::cout << "Error: Scene not found - SceneStateMachine::loadScene" << std::endl;
		}

	}*/

	void SceneStateMachine::update(float deltaTime)
	{
		// Update current scene if there is one.
		if (currentScene != nullptr)
		{
			currentScene->update(deltaTime);
		}
	}

	void SceneStateMachine::render()
	{
		// Render current scene if there is one.
		if (currentScene != nullptr)
		{
			currentScene->render();
		}
	}

	void SceneStateMachine::dispose()
	{
		// for each scene in scenes
		// deactivate the scene
		// delete the scene
		for (auto& scen : scenes)
		{
			BaseScene* scene = scen.second;
			scene->deactivate();

			delete scene;
		}

		// set currentScene to nullptr for safety.
		currentScene = nullptr;
	}

	void SceneStateMachine::loadScene(const unsigned int index)
	{
		// 1. Look for the scene matching the name
		// 2. If found:
		//    a. Deactivate currentScene, if there is one (Note: there won't be one on launch!)
		//    b. Point currentScene to the new scene.
		//    c. Activate the new scene.
		// 3. Otherwise, log error

		if (index < scenes.size())
		{
			auto it = scenes.begin();
			std::advance(it, index);
			sceneIndex = index;

			BaseScene* newScene = it->second;

			if (currentScene != nullptr)
			{
				currentScene->deactivate();
			}

			currentScene = newScene;
			currentScene->activate();
		}
		else
		{
			std::cout << "Error: Scene not found - SceneStateMachine::loadScene" << std::endl;
		}

	}

}

