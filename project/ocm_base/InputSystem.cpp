#include "InputSystem.h"
#include <unordered_map>

namespace KanataEngine {

#pragma region Containers

	//Key Maps
	static std::unordered_map<int, bool> key_states = {

		//Alphabets
		{ GLFW_KEY_A, false },
		{ GLFW_KEY_B, false },
		{ GLFW_KEY_C, false },
		{ GLFW_KEY_D, false },

		{ GLFW_KEY_E, false },
		{ GLFW_KEY_F, false },
		{ GLFW_KEY_G, false },
		{ GLFW_KEY_H, false },

		{ GLFW_KEY_I, false },
		{ GLFW_KEY_J, false },
		{ GLFW_KEY_K, false },
		{ GLFW_KEY_L, false },

		{ GLFW_KEY_M, false },
		{ GLFW_KEY_N, false },
		{ GLFW_KEY_O, false },
		{ GLFW_KEY_P, false },

		{ GLFW_KEY_Q, false },
		{ GLFW_KEY_R, false },
		{ GLFW_KEY_S, false },
		{ GLFW_KEY_T, false },

		{ GLFW_KEY_U, false },
		{ GLFW_KEY_V, false },
		{ GLFW_KEY_W, false },
		{ GLFW_KEY_X, false },

		{ GLFW_KEY_Y, false },
		{ GLFW_KEY_Z, false },

		//Numbers
		{ GLFW_KEY_0, false },
		{ GLFW_KEY_1, false },
		{ GLFW_KEY_2, false },
		{ GLFW_KEY_3, false },
		{ GLFW_KEY_4, false },
		{ GLFW_KEY_5, false },
		{ GLFW_KEY_6, false },
		{ GLFW_KEY_7, false },
		{ GLFW_KEY_8, false },
		{ GLFW_KEY_9, false },

		//Arrows
		{ GLFW_KEY_UP, false },
		{ GLFW_KEY_DOWN, false },
		{ GLFW_KEY_LEFT, false },
		{ GLFW_KEY_RIGHT, false },

		//Misc
		{ GLFW_KEY_APOSTROPHE, false },
		{ GLFW_KEY_SPACE, false },
		{ GLFW_KEY_BACKSLASH, false },
		{ GLFW_KEY_BACKSPACE, false },
		{ GLFW_KEY_MINUS, false },
		{ GLFW_KEY_EQUAL, false },
		{ GLFW_KEY_COMMA, false },
		{ GLFW_KEY_LEFT_ALT, false },
		{ GLFW_KEY_RIGHT_ALT, false },
		{ GLFW_KEY_TAB, false },
		{ GLFW_KEY_RIGHT_SHIFT, false },
		{ GLFW_KEY_LEFT_SHIFT, false },
		{ GLFW_KEY_ESCAPE, false }
	};

	static std::unordered_map<int, bool> previous_key_states = key_states;

	//Mouse Maps
	static std::unordered_map<int, bool> mouse_states = {
		{ GLFW_MOUSE_BUTTON_1, false },
		{ GLFW_MOUSE_BUTTON_2, false }
	};

	static std::unordered_map<int, bool> previous_mouse_states = mouse_states;

#pragma endregion Containers

	const Vector2 InputSystem::getMousePosition()
	{
		return mousePos;
	}

	void InputSystem::processInput(GLFWwindow* window)
	{

		glfwGetCursorPos(window, &mousePos.x, &mousePos.y);

		for (auto& prev_state : previous_key_states)
		{
			prev_state.second = key_states[prev_state.first];
		}

		for (auto& state : key_states)
		{
			state.second = glfwGetKey(window, state.first);
		}

		for (auto& prev_mState : previous_mouse_states)
		{
			prev_mState.second = mouse_states[prev_mState.first];
		}

		for (auto& mState : mouse_states)
		{
			mState.second = glfwGetMouseButton(window, mState.first);
		}
	}

	bool InputSystem::getKeyDown(int key)
	{
		auto itK = key_states.find(key);
		auto itP = previous_key_states.find(key);

		if (itK->second && !itP->second && itK != key_states.end() && itP != previous_key_states.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool InputSystem::getKey(int key)
	{
		auto itK = key_states.find(key);
		auto itP = previous_key_states.find(key);

		if (itK->second && itP->second && itK != key_states.end() && itP != previous_key_states.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool InputSystem::getKeyUp(int key)
	{
		auto itK = key_states.find(key);
		auto itP = previous_key_states.find(key);

		if (!itK->second && itP->second && itK != key_states.end() && itP != previous_key_states.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool InputSystem::getMouseKeyDown(int key)
	{
		auto itMK = mouse_states.find(key);
		auto itMP = previous_mouse_states.find(key);

		if (itMK->second && !itMP->second && itMK != mouse_states.end() && itMP != previous_mouse_states.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool InputSystem::getMouseKey(int key)
	{
		auto itMK = mouse_states.find(key);
		auto itMP = previous_mouse_states.find(key);

		if (itMK->second && itMP->second && itMK != mouse_states.end() && itMP != previous_mouse_states.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool InputSystem::getMouseKeyUp(int key)
	{
		auto itMK = mouse_states.find(key);
		auto itMP = previous_mouse_states.find(key);

		if (!itMK->second && itMP->second && itMK != mouse_states.end() && itMP != previous_mouse_states.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//extras (works but unused)
	bool InputSystem::getAnyKeyDown(int key)
	{
		if (key <= 2)
		{
			auto itMK = mouse_states.find(key);
			auto itMP = previous_mouse_states.find(key);

			if (itMK->second && !itMP->second && itMK != mouse_states.end() && itMP != previous_mouse_states.end())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (key > 2)
		{
			auto itK = key_states.find(key);
			auto itP = previous_key_states.find(key);

			if (itK->second && !itP->second && itK != key_states.end() && itP != previous_key_states.end())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	bool InputSystem::getAnyKey(int key)
	{
		if (key <= 2)
		{
			auto itMK = mouse_states.find(key);
			auto itMP = previous_mouse_states.find(key);

			if (itMK->second && itMP->second && itMK != mouse_states.end() && itMP != previous_mouse_states.end())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (key > 2)
		{
			auto itK = key_states.find(key);
			auto itP = previous_key_states.find(key);

			if (itK->second && itP->second && itK != key_states.end() && itP != previous_key_states.end())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

}










