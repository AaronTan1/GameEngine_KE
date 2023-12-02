#include "BaseComponent.h"  

namespace KanataEngine {

	BaseComponent::BaseComponent(GameObject* go) : gameObject(go) {}
	BaseComponent::~BaseComponent()
	{
		// Required for subclasses to work properly. 
	}

	void BaseComponent::awake() {}

	// !! Do the same for start, update and render !! 

	void BaseComponent::start() {}

	void BaseComponent::update(float deltaTime) {}

	void BaseComponent::render() {}

	void BaseComponent::destroy()
	{
		flaggedForDeletion = true;
	}
	bool BaseComponent::shouldDestroy()
	{
		return flaggedForDeletion;
	}

}



