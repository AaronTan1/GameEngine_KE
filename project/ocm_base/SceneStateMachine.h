#pragma once
#include "BaseScene.h"
#include <unordered_map>
#include <iostream>

namespace KanataEngine {

	/**
	* @class SceneStateMachine
	* @brief Contains classes and utilities for the KanataEngine application.
	*
	* The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
	* It includes a SceneStateMachine class responsible for managing scenes and their transitions.
	*/

	class SceneStateMachine
	{
	public:
		SceneStateMachine() = delete; // disallow construction of class instance

		template<typename T, typename = typename std::enable_if<std::is_base_of<BaseScene, T>::value>::type>
		static T* addScene() {
			T* newScene = new T();

			auto pair = std::make_pair(newScene->getName(), newScene);

			std::pair < std::unordered_map<std::string, BaseScene*>::iterator, bool > result = scenes.insert(pair);

			// result.first = the (std::string + Scene*) pair
			// result.second = whether the insertion is successful or not.
			//   If successful, pair.first will point o the newly inserted pair.
			//   If not successful, pair.first will point to existing pair inside the map.

			// if successfuly adding the new pair
			if (result.second) {
				std::cout << "Log about something here - SceneStateMachine::addScene" << std::endl;

				// For challenge (see below)
				unsigned int currentId = sceneIdCounter;
				sceneIdCounter++;

				return newScene;
			}
			else {
				std::cout << "Log about something here - SceneStateMachine::addScene" << std::endl;
				delete newScene;
				return nullptr;
			}
		}

		//static void loadScene(const std::string name);
		static void update(float deltaTime);
		static void render();
		static void dispose();

		// Challenge:
		// Add functionality to load scene by index. The index is 0-based, and is ordered by
		// addScene calls.
		// Refer to Unity for how they do loadScene by index.
		static void loadScene(const unsigned int index);

		static unsigned int sceneIndex;

	private:
		// sceneMap
		static std::unordered_map<std::string, BaseScene*> scenes;

		// currentScene
		static BaseScene* currentScene;

		// sceneIdCounter
		static unsigned int sceneIdCounter;

	};


}

