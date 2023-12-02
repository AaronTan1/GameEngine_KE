#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <string>
#include "GameObject.h"
#include "BaseComponent.h"
#include "SpriteRendererComponent.h"

namespace KanataEngine {

    /**
    * @class ProgressBarComponent
    * @brief Contains classes and utilities for the KanataEngine application.
    *
    * The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
    * It includes a ProgressBarComponent class that represents a progress bar component for visual feedback on progress.
    * The class provides methods to set the initial position, progress value, target progress, bar width, and size.
    */

    class ProgressBarComponent : public BaseComponent
    {
    public:
        ProgressBarComponent(GameObject* go);
        ~ProgressBarComponent();

        virtual void awake();
        virtual void start();
        virtual void update(float deltaTime);
        virtual void render();

        void setInitialPosition(Vec2 pos);
        void setProgress(float value);
        void setTargetProgress(float value);
        void setBarWidth(float width);
        void setSize(Vec2 valSize);

        float progress;

    private:
        float targetProgress;

        // Calculate the width of the progress bar based on the progress
        float barWidth;
        Vec2 barSize;
        Vec2 initialPosition;
    };

}



