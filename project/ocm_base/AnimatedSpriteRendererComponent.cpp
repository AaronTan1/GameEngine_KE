#include "AnimatedSpriteRendererComponent.h"

namespace KanataEngine {

    AnimatedSpriteRenderer::AnimatedSpriteRenderer(GameObject* go, float initialX, float initialY, const std::string& texturePath) : SpriteRendererComponent(go, initialX, initialY, texturePath), frameDuration(0.1f), frameTimer(0.0f), animationSpeed(1.0f), currentFrameIndex(0), frameIndexLimit(0) {
    }

    AnimatedSpriteRenderer::~AnimatedSpriteRenderer() {
        for (Texture* texture : animationFrames) {
            TextureAllocator::deleteTexture(texture);
        }
        animationFrames.clear();
    }

    void AnimatedSpriteRenderer::addAnimationFrame(const std::string& texturePath) {
        Texture* texture = TextureAllocator::requestTexture(texturePath);
        animationFrames.push_back(texture);

    }

    void AnimatedSpriteRenderer::playAnimation(float deltaTime) {
        frameTimer += deltaTime * animationSpeed;

        if (frameTimer >= frameDuration) {
            currentFrameIndex = (static_cast<int64_t>(currentFrameIndex) + 1) % animationFrames.size();
            switchToFrame(currentFrameIndex);

            frameTimer = 0.0f;

            frameIndexLimit = currentFrameIndex;
        }
    }

    void AnimatedSpriteRenderer::setAnimationSpeed(float speed)
    {
        animationSpeed = speed;
    }

    void AnimatedSpriteRenderer::switchToFrame(int frameIndex) {
        if (frameIndex < 0 || frameIndex >= animationFrames.size()) {
            std::cout << "Invalid frame index: " << frameIndex << std::endl;
            return;
        }

        texture = animationFrames[frameIndex];
    }

}

