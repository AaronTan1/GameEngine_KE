/**
 * @mainpage Kanata Game Engine Documentation
 *
 * @section intro Introduction
 * Welcome to the documentation for Kanata Engine! This game engine is designed to provide developers with a flexible framework for creating games. It offers various features to streamline the game development process.
 *
 * @section author Author Information
 * - Name: [Aaron Tan]
 * - Student ID: [0129389]
 *
 * @section engine_desc Engine Description
 * Kanata Engine is a lightweight and user-friendly game engine that aims to simplify game development. It provides a range of tools to help developers create scenes, design custom components, and seamlessly integrate them into their games.
 *
 * @section attribution Attribution and Acknowledgement
 * This game engine utilizes the following third-party libraries and sources:
 * - [Library/Source 1]: [https://github.com/nothings/stb/blob/master/stb_image.h]
 * - [Library/Source 2]: [https://www.zerochan.net/2849889]
 * - [Library/Source 3]: [https://danbooru.donmai.us/posts/5946453]
 * - ...
 */

#include "Application.h"

using namespace KanataEngine;

int main() {
	Application app;
	app.initialize(1000, 600, "A3_0129389_GEAD");
	app.run();
	app.shutdown();
}