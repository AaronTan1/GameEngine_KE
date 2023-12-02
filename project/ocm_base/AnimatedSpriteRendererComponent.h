#pragma once
#include "SpriteRendererComponent.h"
#include <vector>

namespace KanataEngine{

    /**
    * @class AnimatedSpriteRenderer
    * @brief The AnimatedSpriteRenderer component maintains a collection of textures representing different frames of the animation.
    *
    * This class adds a new animation frame and then uses the playAnimation function to calculate when to switch to the next frame based on the frame timer and the animation's speed.
    * This component is especially useful for creating dynamic and visually appealing animations in games.
    */

    class AnimatedSpriteRenderer : public SpriteRendererComponent {
    public:
        AnimatedSpriteRenderer(GameObject* go, float initialX, float initialY, const std::string& texturePaths);
        ~AnimatedSpriteRenderer();

        void addAnimationFrame(const std::string& texturePath);
        void playAnimation(float deltaTime);
        void setAnimationSpeed(float speed);
        void switchToFrame(int frameIndex);

        int frameIndexLimit;

    private:
        std::vector<Texture*> animationFrames;
        float frameDuration;
        float frameTimer;
        float animationSpeed;
        int currentFrameIndex;
    };

}

