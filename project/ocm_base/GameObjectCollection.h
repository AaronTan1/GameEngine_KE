#pragma once
#include <string>
#include <vector>
#include <unordered_set>

class GameObject;

namespace KanataEngine {

	/**
	* @class GameObjectCollection
	* @brief Provides a collection to manage game objects and their lifecycle.
	*
	* The GameObjectCollection class is a static class that manages game objects and their lifecycle.
	* It allows adding, updating, rendering, and disposing of game objects.
	* The class provides functionalities to find game objects by name and inspect the active game objects.
	*/

	// GameObjectCollection is static
	class GameObjectCollection
	{
	public:
		GameObjectCollection() = delete; // disallow construction of class instance*

		static void add(GameObject* go);
		static GameObject* add(std::string name);

		static void update(float deltaTime);
		static void render();
		static void dispose();

		// Challenge: implement this (implemented)
		static GameObject* find(std::string name);

		void inspectGameObjects();

		static const std::unordered_set<GameObject*>& getActiveGameObjects();

	private:
		static std::unordered_set<GameObject*> gameObjects;
		static std::unordered_set<GameObject*> gameObjectsToAdd;

		bool markedForRemoval = false;
	};

}


