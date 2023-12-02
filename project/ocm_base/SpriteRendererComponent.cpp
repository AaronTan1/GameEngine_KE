#include "SpriteRendererComponent.h"

namespace KanataEngine {

    SpriteRendererComponent::SpriteRendererComponent(GameObject* go, float initialX, float initialY, const std::string& texturePath) : BaseComponent(go), initialX(initialX), initialY(initialY), x(0.0f), y(0.0f), color{ 1.0f, 1.0f, 1.0f }, opacity(1.0f), size{ 150.0f, 150.0f }, pivot{ 0.5f, 0.5f }, texture(nullptr) {

        texture = TextureAllocator::requestTexture(texturePath);
        transformComponent = go->getComponent<TransformComponent>();

        if (!transformComponent) {
            std::cerr << "SpriteRenderer couldn't find TransformComponent on the GameObject." << std::endl;
        }
    }

    SpriteRendererComponent::~SpriteRendererComponent() {
        TextureAllocator::deleteTexture(texture);
    }

    void SpriteRendererComponent::setColour(float r, float g, float b) {
        color = Vec3{ r, g, b };
    }

    void SpriteRendererComponent::setColour(Vec3 newColor) {
        color = newColor;
    }

    void SpriteRendererComponent::setOpacity(float alpha) {
        opacity = alpha;
    }

    void SpriteRendererComponent::setSize(float width, float height) {
        size = Vec2{ width, height };
    }

    void SpriteRendererComponent::setSize(Vec2 newSize) {
        size = newSize;
    }

    void SpriteRendererComponent::setPivot(float x, float y) {
        pivot = Vec2{ x, y };
    }

    void SpriteRendererComponent::setPivot(Vec2 newPivot) {
        pivot = newPivot;
    }

    void SpriteRendererComponent::draw() {

        glPushMatrix();

        glTranslatef(initialX + transformComponent->getX(), initialY + transformComponent->getY(), 0);
        glRotatef(transformComponent->getRotation(), 0, 0, 1);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_TEXTURE_2D);

        texture->bind();

        glBegin(GL_QUADS);

        glColor4f(color.r, color.g, color.b, opacity);

        float adjustedX = -pivot.x * size.x;
        float adjustedY = -pivot.y * size.y;

        glTexCoord2f(0.0f, 1.0f); glVertex3f(adjustedX, adjustedY + size.y, 0);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(adjustedX, adjustedY, 0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(adjustedX + size.x, adjustedY, 0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(adjustedX + size.x, adjustedY + size.y, 0);

        glEnd();

        glDisable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);

        glPopMatrix();
    }

}


