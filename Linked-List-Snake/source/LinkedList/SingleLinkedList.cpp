#include "LinkedList/SingleLinkedList.h"
#include "Player/BodyPart.h"
#include "Level/LevelView.h"

namespace LinkedList
{
	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}

	SingleLinkedList::~SingleLinkedList() = default;

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Direction direction)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
	}

	void SingleLinkedList::render()
	{
		Node* curr_node = head_node;

		while (curr_node != nullptr)
		{
			curr_node->body_part.render();
			curr_node = curr_node->next;
		}
	}

	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}

	void SingleLinkedList::insertNodeAtTail()
	{
		Node* new_node = createNode();
		Node* curr_node = head_node;

		if (curr_node == nullptr)
		{
			head_node = new_node;
			new_node->body_part.initialize(node_width, node_height, default_position, default_direction);
			return;
		}

		while (curr_node->next != nullptr)
		{
			curr_node = curr_node->next;
		}

		curr_node->next = new_node;
		new_node->body_part.initialize(node_width, node_height, getNewNodePosition(curr_node), curr_node->body_part.getDirection());

	}

	bool SingleLinkedList::processNodeCollision()
	{
		if (head_node == nullptr) return false;

		sf::Vector2i predicted_position = head_node->body_part.getNextPosition();

		Node* cur_node = head_node->next;
		while (cur_node != nullptr)
		{
			if (cur_node->body_part.getNextPosition() == predicted_position) return true;
			cur_node = cur_node->next;
		}

		return false;
	}

	sf::Vector2i SingleLinkedList::getNewNodePosition(Node* reference_node)
	{
		// Extract direction and position for new node calculation
		Direction reference_direction = reference_node->body_part.getDirection();
		sf::Vector2i reference_position = reference_node->body_part.getPosition();

		// Calculate new position based on reference node's direction
		switch (reference_direction)
		{
		case Direction::UP:
			return sf::Vector2i(reference_position.x, reference_position.y - 1);     //Decreases the y-coordinate by 1 (moves up)
			break;
		case Direction::DOWN:
			return sf::Vector2i(reference_position.x, reference_position.y + 1);     //Increases the y-coordinate by 1 (moves down)
			break;
		case Direction::LEFT:
			return sf::Vector2i(reference_position.x + 1, reference_position.y);    //Increases the x-coordinate by 1 (moves left).
			break;
		case Direction::RIGHT:
			return sf::Vector2i(reference_position.x - 1, reference_position.y);  //Decreases the x-coordinate by 1 (moves right).
			break;
		}

		return default_position;
	}

	void SingleLinkedList::updateNodeDirection(Direction direction_to_set)
	{
		Node* curr_node = head_node;

		while (curr_node != nullptr)
		{
			Direction prev_direction = curr_node->body_part.getDirection();
			curr_node->body_part.setDirection(direction_to_set);
			direction_to_set = prev_direction;
			curr_node = curr_node->next;
		}
	}

	void SingleLinkedList::updateNodePosition()
	{
		Node* curr_node = head_node;

		while (curr_node != nullptr)
		{
			curr_node->body_part.updatePosition();
			curr_node = curr_node->next;
		}
	}
}