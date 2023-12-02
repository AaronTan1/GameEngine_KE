#include "ResourceAllocator.h"
#include "texture_utils.h"

namespace KanataEngine {

    Texture::Texture(std::string path, unsigned int id, unsigned int width, unsigned int height)
        : name(path), texture_ID(id), width(width), height(height) {}

    unsigned int Texture::getWidth() const {
        return width;
    }

    unsigned int Texture::getHeight() const {
        return height;
    }

    Texture* Texture::createTexture(std::string path) {
        unsigned int id = KanataEngine::loadTexture(path);
        int width = 0;
        int height = 0;

        if (id > 0) {
            Texture* tex = new Texture(path, id, width, height);
            return tex;
        }

        return nullptr;
    }

    void Texture::bind() {
        glBindTexture(GL_TEXTURE_2D, texture_ID);
    }

    void Texture::increaseRefCount() {
        refCount++;
    }

    void Texture::decreaseRefCount() {
        refCount--;
    }

    const int Texture::getRefCount() const {
        return refCount;
    }

    std::unordered_map<std::string, Texture*> TextureAllocator::textureMap;

    Texture* TextureAllocator::requestTexture(const std::string& texturePath) {
        auto it = textureMap.find(texturePath);
        if (it != textureMap.end()) {
            it->second->refCount++;
            std::cout << "Reusing texture: " << texturePath << " refCount is now " << it->second->refCount << std::endl;
            return it->second;
        }

        Texture* texture = Texture::createTexture(texturePath);
        if (texture) {
            textureMap[texturePath] = texture;
            texture->increaseRefCount();
            return texture;
        }

        return nullptr;
    }

    void TextureAllocator::deleteTexture(Texture* texture) {
        if (texture && texture->getRefCount() > 0) {
            texture->decreaseRefCount();
            if (texture->getRefCount() == 0) {
                std::cout << texture->name << " refCount is " << texture->refCount << ", safe to delete" << std::endl;
                auto it = textureMap.find(texture->name);
                if (it != textureMap.end()) {
                    delete it->second;
                    textureMap.erase(it);
                }
            }
        }
    }

}

