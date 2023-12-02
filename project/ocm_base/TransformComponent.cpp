#include "TransformComponent.h"
#include "BaseComponent.h"

namespace KanataEngine {

	TransformComponent::TransformComponent(GameObject* go) : BaseComponent(go), x(0.0f), y(0.0f), rotation(0.0f)
	{
		std::cout << "TransformComponent constructor called!" << std::endl;
	}

	TransformComponent::~TransformComponent() {
	}

	void TransformComponent::awake()
	{
	}

	void TransformComponent::start()
	{
	}

	void TransformComponent::update(float deltaTime)
	{
	}

	void TransformComponent::render()
	{
	}

	float TransformComponent::getX() const
	{
		return x;
	}

	float TransformComponent::getY() const
	{
		return y;
	}

	float TransformComponent::getRotation() const
	{
		return rotation;
	}

	void TransformComponent::setX(float value)
	{
		x = value;
	}

	void TransformComponent::setY(float value)
	{
		y = value;
	}

	void TransformComponent::setRotation(float value)
	{
		rotation = value;
	}

}

