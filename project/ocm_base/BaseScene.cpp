#include "BaseScene.h"
#include "GameObjectCollection.h"

// NOTE: For gameObject related calls, use GameObjectCollection!

namespace KanataEngine {

	// Called when changed to this scene.
	void BaseScene::activate() {
		// 1. Call initialize
		initialize();

		// 2. Call the relevant virtual function
		on_activate();
	}

	// Called before changing to different scene.
	void BaseScene::deactivate() {
		// 1. Dispose all gameObjects
		GameObjectCollection::dispose();

		// 2. Call the relevant virtual function
		on_deactivate();
	}

	void BaseScene::update(float deltaTime) {
		// 1. Update all gameObjects
		GameObjectCollection::update(deltaTime);

		// 2. Call the relevant virtual function
		on_update(deltaTime);
	}

	void BaseScene::render() {
		// 1. Render all gameObjects
		GameObjectCollection::render();

		// 2. Call the relevant virtual function
		on_render();
	}

}

