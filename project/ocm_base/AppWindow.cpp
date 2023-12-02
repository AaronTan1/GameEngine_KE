#include "AppWindow.h"
#include <glad/glad.h>
#include <iostream>

namespace KanataEngine {

	GLFWwindow* AppWindow::window = nullptr; // Define the static member

	AppWindow::~AppWindow()
	{
		glfwTerminate();
	}

	void framebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		if (width == 0 || height == 0) return;

		glViewport(0, 0, width, height);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho(-width / 2, width / 2, -height / 2, height / 2, -1, 1);  // Center render in the view

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		std::cout << "Framebuffer size changed: " << width << "x" << height << std::endl;

		void* ptr = glfwGetWindowUserPointer(window);
		WindowData* data = static_cast<WindowData*>(ptr);
		data->callback("resize", nullptr);
	}



	int AppWindow::create(int width, int height, const char* title)
	{
		if (!glfwInit())
		{
			return -1;
		}

		// Set the minimum OpenGL version for next window creation
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

		window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		// Make this window the current OpenGL context
		// Without a valid context, we cannot use OpenGL API
		glfwMakeContextCurrent(window);

		// load gl functions 
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return -1;
		}

		data.width = width;
		data.height = height;
		data.title = title;
		glfwSetWindowUserPointer(window, &data);

		glfwSetWindowCloseCallback(window, [](GLFWwindow* w) {
			void* ptr = glfwGetWindowUserPointer(window);
			WindowData* data = static_cast<WindowData*>(ptr);

			data->callback("close", 0);
			});

		glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

		glViewport(0, 0, width, height);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho(-width / 2, width / 2, -height / 2, height / 2, -1, 1);  // Center render in the view

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// If this line is before glfwContextCurrent, it will crash!
		glClearColor(0.5, 0.5, 0.5, 1.0);

		return 1;
	}
	void AppWindow::swap_and_poll()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void AppWindow::setWindowEventCallback(const WindowEventCallbackFn& fn)
	{
		data.callback = fn;
	}

}




