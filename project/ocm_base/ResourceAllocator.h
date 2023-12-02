#pragma once
#include <string>
#include <unordered_map>
#include <iostream>

namespace KanataEngine {

    /**
    * @class TextureAllocator
    * @brief Contains classes and utilities for the KanataEngine application.
    *
    * The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
    * It includes classes related to managing textures and texture allocation.
    */

    /**
    * @class Texture
        * @brief Contains classes and utilities for the KanataEngine application.
    *
    * The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
    * It includes classes related to managing textures and texture allocation.
    */

    class Texture {
    public:
        static Texture* createTexture(std::string path);
        void bind();
        void increaseRefCount();
        void decreaseRefCount();
        const int getRefCount() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;

        unsigned int refCount = 0;
        std::string name;

    private:
        Texture(std::string path, unsigned int id, unsigned int width, unsigned int height);

        unsigned int texture_ID;
        unsigned int width;
        unsigned int height;
    };

    class TextureAllocator {
    public:
        static Texture* requestTexture(const std::string& texturePath);
        static void deleteTexture(Texture* texture);

    private:
        static std::unordered_map<std::string, Texture*> textureMap;
    };

}

