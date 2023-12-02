#include "GameObject.h"
#include "GameObjectCollection.h"
//#include "RenderComponent.h"
#include "SpriteRendererComponent.h"

	GameObject::GameObject(std::string newName) : name(newName)
	{
		std::cout << "GameObject constructor called for: " << name << std::endl;

		addToCollection(this);

		TransformComponent* transformComponent = this->addComponent<TransformComponent>();
		//RenderComponent* renderComponent = this->addComponent<RenderComponent>();


		//std::vector<std::string> imagePaths = {
		//	"../assets/kanata.png",
		//};

		//if (name == "test_in_splash_gameobject")
		//{
		//	renderComponent->setRGB(0.25, 0, 0, 1);
		//	renderComponent->render();
		//}
		//else if (name == "EmptyObj" ||name == "SpawnedOne" || name == "SpawnedTwo")
		//{
		//	renderComponent->setRGB(0, 0.25, 0, 1);
		//	renderComponent->render();
		//}

	}

	GameObject::~GameObject()
	{
		std::cout << "GameObject destructor called for: " << name << std::endl;

		for (auto component : components)
		{
			delete component;
		}

		components.clear();
		std::cout << name << " is Deleted." << std::endl;
	}

	void GameObject::runComponentAwake()
	{
		if (componentsJustAdded.size() == 0)
			return;

		for (auto newComponent : componentsJustAdded)
		{
			newComponent->awake();
		}
	}

	void GameObject::runComponentStart()
	{
		if (componentsJustAdded.size() == 0)
			return;

		for (auto newComponent : componentsJustAdded)
		{
			newComponent->start();
		}

		componentsJustAdded.clear();
	}

	void GameObject::runComponentUpdate(float deltaTime)
	{
		components.erase(std::remove_if(components.begin(), components.end(), [](BaseComponent* component)
			{
				if (component->shouldDestroy())
				{
					delete component;
					return true;
				}
				return false;
			}),
			components.end());// erase 2nd parameter 

		for (auto component : components)
		{
			component->update(deltaTime);
		}
	}

	void GameObject::runComponentRender()
	{

		for (auto component : components)
		{
			// Check if the component is a SpriteRendererComponent
			if (SpriteRendererComponent* spriteRendererComponent = dynamic_cast<SpriteRendererComponent*>(component))
			{
				spriteRendererComponent->draw();
			}
			else
			{
				component->render();
			}

		}
	}

	std::string GameObject::getName() const
	{
		return name;
	}

	void GameObject::destroy()
	{
		flaggedForDeletion = true;
	}
	bool GameObject::shouldDestroy()
	{
		return flaggedForDeletion;
	}

	void GameObject::addToCollection(GameObject* go)
	{
		GameObjectCollection::add(go);
	}

	void GameObject::addedComponents()
	{
		std::cout << "Components added to GameObject '" << name << "':" << std::endl;

		for (auto component : components)
		{
			const std::type_info& typeInfo = typeid(*component);
			std::cout << " - " << typeInfo.name() << std::endl;
		}
	}











