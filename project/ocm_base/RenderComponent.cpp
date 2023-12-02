#include "RenderComponent.h"

namespace KanataEngine {

	RenderComponent::RenderComponent(GameObject* go) : BaseComponent(go) {
		transformComponent = go->getComponent<TransformComponent>();
		if (!transformComponent) {
			std::cerr << "RenderComponent: TransformComponent not found!" << std::endl;
		}
	}

	RenderComponent::~RenderComponent() {
	}

	void RenderComponent::setRGB(float rVal, float gVal, float bVal, float aVal)
	{
		r = rVal;
		g = gVal;
		b = bVal;
	}

	void RenderComponent::awake() {}

	void RenderComponent::start() {}

	void RenderComponent::update(float deltaTime) {}

	void RenderComponent::render() {

		if (!transformComponent) {
			std::cout << "RenderComponent: TransformComponent not available!" << std::endl;
			return;
		}

		/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/

		glPushMatrix();

		glRotatef(transformComponent->getRotation(), 0, 0, 1);
		glTranslatef(transformComponent->getX(), transformComponent->getY(), 0);


		glBegin(GL_QUADS);
		glColor4f(r, g, b, a);

		glVertex3f(-100, 100, 0);
		glVertex3f(-100, -100, 0);
		glVertex3f(100, -100, 0);
		glVertex3f(100, 100, 0);

		glEnd();

		glPopMatrix();

	}

}

