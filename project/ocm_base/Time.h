#pragma once

namespace KanataEngine {

	/**
	* @class Time
	* @brief Contains classes and utilities for the KanataEngine application.
	*
	* The KanataEngine namespace encapsulates various classes and utilities that contribute to the KanataEngine application.
	* It includes a Time class that provides functions for managing time-related operations.
	*/

	class Time
	{
	public:
		static float process(float frameTime);
		static float getDeltaTime();

	private:
		static float time;
		static float prevTime;
		static float deltaTime;
	};

}




