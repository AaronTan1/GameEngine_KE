#pragma once
#include <iostream>
#include <glad/glad.h>
#include "GameObject.h"
#include "BaseComponent.h"
#include "TransformComponent.h" 

namespace KanataEngine {

    /**
    * @class RenderComponent
    * @brief Contains classes and utilities for the KanataEngine application.
    *
    * The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
    * It includes a RenderComponent class that represents a rendering component for managing visual rendering properties.
    * The class provides methods to set the color (RGB) of the rendered object and interacts with TransformComponent for transformations.
    */

    class RenderComponent : public BaseComponent
    {
    public:
        RenderComponent(GameObject* go);
        ~RenderComponent();

        virtual void awake();
        virtual void start();
        virtual void update(float deltaTime);
        virtual void render();

        void setRGB(float r, float g, float b, float a);

    private:

        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        float a = 0.0f;

        TransformComponent* transformComponent;
    };

}

