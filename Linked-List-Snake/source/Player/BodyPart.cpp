#include "../../include/Player/BodyPart.h"
#include "../../include/UI/UIElement/ImageView.h"
#include "../../include/Global/Config.h"

namespace Player
{
	using namespace UI;
	using namespace Global;

	BodyPart::BodyPart()
	{
		createBodyPartImage();
		grid_position = sf::Vector2i(0, 0);
	}

	BodyPart::~BodyPart()
	{
		destroy();
	}

	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		direction = dir;
		grid_position = pos;

		initializeBodyPartImage();
	}

	//void BodyPart::update();

	void BodyPart::render()
	{
		bodypart_image->render();
	}

	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new UIElement::ImageView();
	}

	void BodyPart::initializeBodyPartImage()
	{
		bodypart_image->initialize(Config::snake_body_texture_path, bodypart_width, bodypart_height, getBodyPartScreenPosition());
		bodypart_image->setOriginAtCentre();
	}

	void BodyPart::destroy()
	{
		delete(bodypart_image);
	}
}