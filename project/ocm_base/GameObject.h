#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "BaseComponent.h"
#include "TransformComponent.h"

using namespace KanataEngine;

/**
 * @class GameObject
 * @brief Represents a game object that can hold components and manage their lifecycle.
 *
 * The GameObject class serves as a container for components and manages their lifecycle.
 * It provides functions to add, retrieve, and run components' lifecycle methods like awake, start, update, and render.
 * The class also includes functions for managing the game object's destruction and querying its destruction status.
 * Components can be added using templates to provide flexibility in initialization.
 */

	class GameObject
	{
	public:
		GameObject(std::string newName = "");
		~GameObject();


		std::string getName() const;

		std::vector<std::string> imagePaths;

		template<typename T>
		/*
		template <
		typename T,
		typename = typename std::enable_if<std::is_base_of<BaseComponent, T>::value>::type
		>
		*/
		T* addComponent() {
			// Create instance of T, expecting that T has a constructor that takes GameObject*
			T* newComponent = new T(this);

			// Add the instance of T to componentsToAdd
			componentsJustAdded.push_back(newComponent);
			// Also add it to components
			components.push_back(newComponent);
			return newComponent;
		}

		template <
			typename T,
			typename = typename std::enable_if<std::is_base_of<BaseComponent, T>::value>::type
		>
			T* getComponent() {
			// iterate the vector to find component that matches
			// the type.
			for (auto& c : components) {
				// find component that matches the type.
				// return the first item found.
				T* tryCast = dynamic_cast<T*>(c);
				if (tryCast != nullptr) {
					return tryCast;
				}
			}
			// if nothing found, return null (0)
			return nullptr;
		}

		//for add component SpriteRendererComponent specifically
		template <typename T, typename... Args>
		T* addComponent(Args&&... args) {
			// Create instance of T using the provided arguments
			T* newComponent = new T(this, std::forward<Args>(args)...);

			// Add the instance of T to componentsToAdd
			componentsJustAdded.push_back(newComponent);
			// Also add it to components
			components.push_back(newComponent);
			return newComponent;
		}

		void runComponentAwake();
		void runComponentStart();
		void runComponentUpdate(float deltaTime);
		void runComponentRender();

		void destroy();
		bool shouldDestroy();

		void addedComponents();

	protected:
		std::string name;

		// for tutorial, positioning and rotation is in GameObject, for simplicity.     
		// for assignment 3, positioning and rotation MUST be in TransformComponent     
	/*	float x, y, rotation;*/

	private:

		std::vector<BaseComponent*> components;
		std::vector<BaseComponent*> componentsJustAdded;

		bool flaggedForDeletion = false;

		static void addToCollection(GameObject* go);
	};





