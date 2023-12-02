#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <string>
#include "GameObject.h"
#include "BaseComponent.h"
#include "ResourceAllocator.h" 
#include "TransformComponent.h"

namespace KanataEngine {

    /**
    * @class SpriteRendererComponent
    * @brief Contains classes and utilities for the KanataEngine application.
    *
    * The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
    * It includes a SpriteRendererComponent class that represents a component for rendering sprites.
    * The class provides methods to draw sprites, set colors, opacity, size, and pivot points.
    * Additionally, it defines Vec2 and Vec3 structs to represent 2D coordinates and RGB colors.
    */

    /**
    * @struct Vec3
    * @brief Contains classes and utilities for the KanataEngine application.
    *
    * The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
    * It includes classes related to managing textures and texture allocation.
    */

    /**
    * @struct Vec2
    * @brief Contains classes and utilities for the KanataEngine application.
    *
    * The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
    * It includes classes related to managing textures and texture allocation.
    */

    struct Vec3 {
        float r;
        float g;
        float b;
    };

    struct Vec2 {
        float x;
        float y;
    };

    class SpriteRendererComponent : public BaseComponent {
    public:

        SpriteRendererComponent(GameObject* go, float x, float y, const std::string& texturePath);
        ~SpriteRendererComponent();

        virtual void draw();
        void setColour(float r, float g, float b);
        void setColour(Vec3 color);
        void setOpacity(float alpha);
        void setSize(float width, float height);
        void setSize(Vec2 size);
        void setPivot(float x, float y);
        void setPivot(Vec2 pivot);
        Texture* texture;

    private:
        float initialX;
        float initialY;
        float x;
        float y;
        Vec3 color;
        float opacity;
        Vec2 size;
        Vec2 pivot;

        TransformComponent* transformComponent;
    };

}



