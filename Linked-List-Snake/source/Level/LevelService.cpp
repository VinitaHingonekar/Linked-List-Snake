#include "../../include/Level/LevelService.h" 
#include "Global/ServiceLocator.h"

namespace Level
{
	using namespace Global;

	LevelService::LevelService()
	{
		level_controller = nullptr;

		createLevelController();
	}

	LevelService::~LevelService()
	{
		destroy();
	}

	void LevelService::createLevelController()
	{
		level_controller = new LevelController();
	}

	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::destroy()
	{
		delete(level_controller);
	}

	void LevelService::createLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
		spawnPlayer();
	}

	void LevelService::spawnPlayer()
	{
		ServiceLocator::getInstance()->getPlayerService()->spawnPlayer();
	}

	float LevelService::getCellWidth()
	{
		return level_controller->getCellWidth();
	}

	float LevelService::getCellHeight()
	{
		return level_controller->getCellHeight();
	}
}
