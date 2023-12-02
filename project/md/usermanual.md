# User Manual {#usermanual}

## Introduction

Welcome to the user manual for Kanata Engine! This manual will guide you through the process of using the engine to create scenes, custom components, and assemble them into a complete game.

## Table of Contents
1. [Introduction](#introduction)
2. [Creating Scenes](#creating-scenes)
3. [Custom Components](#custom-components)
4. [Assembling Game Elements](#assembling-elements)
5. [Core Game Engine Components](#core-game-engine-components) 
   - [TransformComponent](#transformcomponent)
   - [SpriteRenderer](#spriterenderer)
   - [ProgressBar](#progressbar)
   - [AnimatedSpriteRenderer](#animatedspriterenderer)
   - [Resource Management](#resource-management)
6. [Conclusion](#conclusion)

## Introduction {#introduction}

Kanata Engine is a useful game development framework that provides tools and features to make your game development process smoother and more efficient. Whether you're a seasoned developer or just getting started, this manual will help you harness the capabilities of the engine.

## Creating Scenes {#creating-scenes}

Scenes are the building blocks of your game. They represent different levels, menus, or gameplay segments. Here's how you can create scenes using Kanata Engine:

1. Define a New Scene Class
2. Add the Scene to the Scene State Machine
3. Implement Scene-Specific Logic
4. Transitions Between Scenes

```cpp
// 1. To create a new scene, you'll need to define a new class that inherits from the BaseScene class. This class will encapsulate the logic, assets, and elements specific to the scene you're creating.

	// Example: MyScene.h
	#include "BaseScene.h"
	
	class MyScene : public BaseScene {
	public:
	    MyScene() {} // Constructor

	    std::string getName() const override {
	        return "MyScene"; // Return the name of the scene
	    }

	protected:
	    void initialize() override {
	        // Initialize assets, game objects, and other scene-specific elements here
	    }
	};
```

```cpp

```

```cpp
// 2. Use the addScene() method from the SceneStateMachine class to add the newly created scene class. This ensures that your scene is properly managed by the engine.

	// Adding the scene to SceneStateMachine
	MyScene* myScene = SceneStateMachine::addScene<MyScene>();
```

```cpp

```

```cpp
// 3. Inside your scene class, implement the necessary functions such as initialize(), on_activate(), on_deactivate(), on_update(), and on_render(). These functions allow you to define how the scene behaves during different stages of its lifecycle.

	// MyScene.cpp
	void MyScene::initialize() {
	    // Initialize assets, game objects, and other scene-specific elements here
	}

	void MyScene::on_activate() {
	    // Activate logic specific to this scene
	}

	void MyScene::on_deactivate() {
	    // Deactivate logic specific to this scene
	}

	// ... Other scene-specific functions
```

```cpp

```

```cpp
// 4. You can transition between scenes by using the loadScene() method provided by the SceneStateMachine class. This allows you to switch from one scene to another based on specific events or conditions.

	// Transitioning to MyScene by name
	SceneStateMachine::loadScene("MyScene");
```

By following these steps, you can create, manage, and transition between different scenes in your game using the BaseScene and SceneStateMachine classes provided by the Kanata Engine.

## Custom Components {#custom-components}

Custom components allow you to add unique behaviors and functionality to your game objects. Follow these steps to create and add custom components:

 - Define a New Component Class: Create a new class that inherits from the BaseComponent class. This will serve as the foundation for your custom component. Make sure to include the necessary headers and forward declarations.

```cpp
#pragma once
#include "BaseComponent.h"
#include <iostream> // Include other headers if needed

namespace KanataEngine {

    class CustomComponent : public BaseComponent {
    public:
        CustomComponent(GameObject* go);
        ~CustomComponent();

        virtual void awake();
        virtual void start();
        virtual void update(float deltaTime);
        virtual void render();
    };

}
```

```cpp

```

 - Implement Constructor and Destructor: Implement the constructor and destructor for your custom component. Pass the GameObject* parameter to the base constructor.

```cpp
#include "CustomComponent.h"

namespace KanataEngine {

    CustomComponent::CustomComponent(GameObject* go) : BaseComponent(go) {
        // Custom initialization if needed
    }

    CustomComponent::~CustomComponent() {
        // Custom cleanup if needed
    }

    // Implement the rest of the component's methods...
}
```

```cpp

```

 - Define Custom Behavior: Inside your custom component class, implement the methods (awake(), start(), update(), render(), etc.) to define the behavior of your component. Customize these methods according to the functionality your component should provide.

```cpp
void CustomComponent::awake() {
    // Initialize resources or perform actions upon awakening
}

void CustomComponent::start() {
    // Perform setup or initialization tasks when the component starts
}

void CustomComponent::update(float deltaTime) {
    // Implement component-specific update logic
}

void CustomComponent::render() {
    // Implement rendering logic if necessary
}
```

```cpp

```

 - Add Custom Component to GameObject: When creating a GameObject, you can attach your custom component to it. For example, if you want to add CustomComponent to a GameObject named myObject:

```cpp
// Create a GameObject
GameObject* myObject = new GameObject();

// Attach CustomComponent to the GameObject
CustomComponent* customComponent = new CustomComponent(myObject);

// Optionally, add more components if needed
// myObject->addComponent(...);

// Add the GameObject to the scene or perform other actions
```

```cpp

```

 - Integrate Custom Component in the Game: After creating and attaching your custom component to a GameObject, integrate it into your game logic. You can manipulate and interact with the component through the GameObject it's attached to.
By following these steps, you can create and integrate custom components into KanataEngine to extend the functionality and behavior of your game objects.

---

## Assembling Game Elements {#assembling-elements}

Now that you have scenes and custom components, it's time to bring everything together to create your game. Follow these steps:

1. Create and design multiple scenes to represent different parts of your game.
2. Populate scenes with game objects and customize their properties using the "Inspector" panel.
3. Attach appropriate components to game objects to give them behaviors.
4. Use scripting to implement interactions, animations, and game logic.
5. Define the flow of your game by transitioning between scenes using triggers or scripts.

Remember, Kanata Engine offers a range of features beyond what's covered in this manual. Explore the documentation and experiment with different components to unleash the full potential of your game development.

---

## Core Game Engine Components {#core-game-engine-components}

### TransformComponent {#transformcomponent}

The Transform Component, an essential part of the OCM system, handles transformations within the game. Key features of the Transform Component include:

   1. GameObject Creation: Create a GameObject that requires spatial properties to be managed, such as position and rotation.

   2. Component Attachment: Attach a TransformComponent to the GameObject. This is typically done during the GameObject's initialization.

   3. Accessing and Modifying: Use the provided accessor methods (getX(), getY(), getRotation()) to retrieve the current position and rotation values of the GameObject.

   4. Position and Rotation Adjustments: Utilize the mutator methods (setX(), setY(), setRotation()) to set or change the position and rotation of the GameObject as needed.

   5. Lifecycle Integration: The TransformComponent integrates into the GameObject's lifecycle by providing empty implementations of lifecycle hooks (awake(), start(), update(), and render()). Developers can extend these methods if specific behavior is required at different stages.

   6. Render Transformations: During the rendering phase, apply the GameObject's position and rotation by utilizing the retrieved values from the TransformComponent. This ensures that the GameObject is displayed correctly within the 2D space.

   Functionalities of Transform Component include:
      - Position (XY), rotation (Z), and scaling (XY) properties.
      - Accessible via `setXXX()` and `getXXX()` methods.
      - Automatically added to GameObjects upon creation, providing fundamental transformation capabilities.

### SpriteRenderer {#spriterenderer}

The SpriteRenderer component provides the following features:
   Utilizes transform values from the Transform component.

   1. Color tinting and opacity control. The default is white color with opacity of 1.0.
      - `setColour(r, g, b)`
      - `setColour(Vec3)`
      - `setOpacity(a)`

   2. Custom sprite size setting. The default is the loaded texture size.
      - `setSize(w, h)`
      - `setSize(Vec2)`

   3. Sprite pivot adjustment. The default is (x:0.5, y:0.5).
      - `setPivot(x, y)`
      - `setPivot(Vec2)`

### AnimatedSpriteRenderer {#animatedspriterenderer}

The AnimatedSpriteRenderer component is a specialization of the SpriteRendererComponent that allows for displaying animations by switching between different texture frames over time. It's used to render animated sprites in a game.

   1. AnimatedSpriteRenderer(GameObject* go, float initialX, float initialY, const std::string& texturePaths): Constructor that takes a GameObject, initial position (initialX and initialY), and a path to the initial texture. It initializes various properties such as animation speed, frame index, and frame duration.

   2. addAnimationFrame(const std::string& texturePath): This function allows you to add additional frames to the animation. It takes the path to a texture and adds it to the list of animation frames.

   3. playAnimation(float deltaTime): This function advances the animation by switching to the next frame based on the elapsed time (deltaTime). It calculates the frame index to switch to and updates the frame timer accordingly. The animation speed can be adjusted using setAnimationSpeed(float speed).

   4. setAnimationSpeed(float speed): This function allows you to set the speed of the animation playback.

   5. switchToFrame(int frameIndex): This function switches the current displayed texture to the one specified by the given frameIndex.

   6. ~AnimatedSpriteRenderer(): Destructor that cleans up the allocated animation frames' textures and clears the animation frames vector.


### Resource Management {#resource-management}

Resource allocation is managed through the ResourceAllocator class template. This allows different kinds of resource allocators to exist without needing explicit code creation.
   This allows Textures and Sprites be requested and allocated before they are displayed or called within the game screen.

   1. Texture Creation: Create textures using the Texture::createTexture() method by passing the file path of the texture. This method loads the texture and returns a Texture object.

   2. Binding Textures: To use a texture in rendering, call the bind() method on a Texture object. This binds the OpenGL texture for rendering.

   3. Requesting Textures: To request a texture, call the TextureAllocator::requestTexture() method, passing the texture's file path. This checks if the texture has been loaded before and reuses it if found.

   4. Deleting Textures: When a texture is no longer needed, call TextureAllocator::deleteTexture() and pass the Texture object to be deleted. The allocator manages the reference count and deletes the texture when its reference count reaches zero.

   5. Reference Counting: The Texture class maintains a reference count. Every time a texture is requested or reused, its reference count increases. When a texture is deleted, its reference count decreases. Textures with a reference count of zero are safe to be deleted.

   6. Resource Management: The TextureAllocator maintains an internal map (textureMap) that stores loaded textures. This map allows for quick retrieval of existing textures and efficient management of memory.

   By utilizing the ResourceAllocator, you can streamline texture loading and management, preventing duplicate loading and ensuring proper deallocation of resources, leading to more efficient memory usage in your game or application.


### ProgressBar {#progressbar}
The ProgressBarComponent class offers functionality for creating and managing progress bars within the Kanata Engine environment:
   Uses OpenGL to draw two rectangles: one for the background of the progress bar and another to indicate the current progress level. The position, size, and color of these rectangles are determined by the initialPosition, barSize, and barWidth values, respectively.

   1. Creates an instance of ProgressBarComponent and associates it with the specified GameObject. There is no default value for a pointer parameter go.
      - `ProgressBarComponent(GameObject* go)`
      - `~ProgressBarComponent()`

   2. Sets the value of the progress bar. The default value for them are all set to 0.0f.
      - `setInitialPosition(Vec2 pos)`
      - `setProgress(float value)`
      - `setTargetProgress(float value)`

   3. Adjusts the size of the progress bar. The default value for it are also set to 0.0f;
     - `setBarWidth(float width)`
      - `setSize(Vec2 valSize)`

## Conclusion {#conclusion}

Thank you for choosing Kanata Engine! If you have any questions or need further assistance, refer to the full documentation or reach out to our support team.

---

## Game Object & Component Model (OCM) System

The Game Object & Component Model (OCM) System is an architectural design pattern employed by Kanata Engine. This system aims to enhance flexibility and maintainability by separating game objects from their behaviors (components). Instead of relying on complex inheritance hierarchies, OCM encourages a composition-based approach. Game objects are constructed by combining various components, each contributing specific functionality. This modular approach allows for greater modularity, extensibility, and ease of collaboration among developers.

The OCM system brings multiple advantages to game development, including:

- **Modularity**: Components can be shared among different objects, reducing redundancy and promoting modular design.
- **Flexibility**: Objects gain functionalities through the combination of components, eliminating the need for complex class hierarchies.
- **Extensibility**: Introducing new functionality involves creating and attaching components, streamlining the development process.
- **Collaboration**: Developers can work on distinct components concurrently, ensuring smoother collaboration within teams.
- **Maintainability**: Isolating changes to specific components simplifies maintenance without affecting the overall object structure.

Kanata Engine's OCM System revolutionizes game development by offering a versatile and efficient methodology for building complex game behaviors.

---