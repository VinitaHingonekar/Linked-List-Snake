#pragma once
#include "Level/LevelController.h"
#include "Level/LevelConfig.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;
		LinkedListType current_linked_list_type;

		void createLevelController();
		void destroy();

		void spawnLevelElements(LevelNumber level_to_load);


	public:
		LevelService();
		~LevelService();

		void initialize();
		void render();
		void update();
		void createLevel(LinkedListType linked_list_type);

		void spawnPlayer();
		void spawnFood();

		float getCellWidth();
		float getCellHeight();

		void setCurrentLevelNumber(LevelNumber level_to_load);
		LevelNumber getCurrentLevel();
	};
}