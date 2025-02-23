#pragma once
#include "../UI/UIElement/ImageView.h"
#include "Direction.h"
#include <vector>

namespace Player
{
	class BodyPart
	{
	protected:
		UI::UIElement::ImageView* bodypart_image;

		sf::Vector2i grid_position;
		Direction direction;
		Direction previous_direction;

		float bodypart_width;
		float bodypart_height;

	private:
		void destroy();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		//void update();
		void render();

		void createBodyPartImage();
		void initializeBodyPartImage();
		sf::Vector2f getBodyPartScreenPosition();
		float getRotationAngle();

		void updatePosition();

		sf::Vector2i getNextPosition();
		sf::Vector2i getPrevPosition();

		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionUp();
		sf::Vector2i getNextPositionRight();
		sf::Vector2i getNextPositionLeft();

		void setDirection(Direction direction);
		void setPosition(sf::Vector2i position);
		Direction getDirection();
		sf::Vector2i getPosition();

		Direction getPreviousDirection();

	};
}