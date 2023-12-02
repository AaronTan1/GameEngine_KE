#include "GameObjectCollection.h"
#include "GameObject.h"
#include <iostream>

namespace KanataEngine {

	std::unordered_set<GameObject*> GameObjectCollection::gameObjects;
	std::unordered_set<GameObject*> GameObjectCollection::gameObjectsToAdd;

	// This function is used by Scene
	void GameObjectCollection::add(GameObject* go)
	{
		// Add GameObject to gameObjectsToAdd
		if (gameObjects.find(go) == gameObjects.end() && gameObjectsToAdd.find(go) == gameObjectsToAdd.end())
		{
			gameObjectsToAdd.insert(go);
		}
	}

	GameObject* GameObjectCollection::add(std::string name)
	{
		// Create GameObject given the name.
		// Add GameObject to gameObjectsToAdd
		// Return GameObject
		GameObject* newGameObject = new GameObject(name);

		gameObjectsToAdd.insert(newGameObject);
		return newGameObject;
	}

	void GameObjectCollection::update(float deltaTime)
	{
		// 1. Remove any gameObject in gameObjects array that are flagged for removal
		// 2. For all gameObjects that are newly added (gameObjectsToAdd), run its awake
		// 3. For all gameObjects that are newly added (gameObjectsToAdd), run its start
		// 4. Move all elements from gameObjectToAdd to gameObjects, and then clear gameObjectsToAdd
		// 		Hint: 'insert' function
		// 5. For each gameObject in gameObjects, call gameObject.update(deltaTime)
		// NOTE: Steps 2, 3 and 4 ONLY NEEDS TO EXECUTE IF gameObjectsToAdd is not empty
		// Otherwise, it is a waste of execution time.

		for (auto it = gameObjects.begin(); it != gameObjects.end();)
		{
			if ((*it)->shouldDestroy())
			{

				delete (*it);
				it = gameObjects.erase(it);
			}
			else
			{
				++it;
			}
		}

		if (!gameObjectsToAdd.empty())
		{
			for (GameObject* go : gameObjectsToAdd)
			{
				go->runComponentAwake();
				go->runComponentStart();
				gameObjects.insert(go);
			}
			gameObjectsToAdd.clear();
		}

		for (GameObject* go : gameObjects)
		{
			go->runComponentUpdate(deltaTime);
		}

	}

	void GameObjectCollection::render()
	{
		// For each gameObject in gameObjects, call gameObject.render()

		for (GameObject* go : gameObjects)
		{
			go->runComponentRender();
		}

	}

	// This function is to be called when the current scene is being deactivated or destroyed.
	// With SceneStateMachine:
	// - current scene is deactivated before changing to a different scene.
	void GameObjectCollection::dispose()
	{
		// delete all element in gameObjects
		// delete all element in gameObjects

		for (GameObject* go : gameObjects)
		{
			go->destroy();
		}
		gameObjects.clear();

		// clear gameObjects array
		// clear gameObjectsToAdd array

		for (GameObject* go : gameObjectsToAdd)
		{
			go->destroy();
		}
	}

	GameObject* GameObjectCollection::find(std::string name)
	{
		// Search GameObject by name in gameObjects
		for (GameObject* go : GameObjectCollection::gameObjects)
		{
			if (go->getName() == name)
			{
				std::cout << "GameObject Found: " << name << std::endl;
				return go;
			}
		}

		std::cout << "GameObject Not Found" << std::endl;

		return nullptr;
	}

	void GameObjectCollection::inspectGameObjects()
	{
		std::cout << "Inspecting Game Objects:" << std::endl;

		for (GameObject* go : GameObjectCollection::gameObjects)
		{
			std::cout << " - " << go->getName() << std::endl;
		}
	}

	const std::unordered_set<GameObject*>& GameObjectCollection::getActiveGameObjects()
	{
		return gameObjects;
	}

}

