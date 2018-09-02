/* Graph
 * Aki Sipovaara 2018
 */

#include "node.h"

Node::Node(void)
{
	id = "No id";
	value = 0;
	idNumber = -1;
	// links init?
}

Node::Node(int newIdIndex)
{
	id = "No id";
	value = 0;
	idNumber = newIdIndex;
	// links init?
}

int Node::setId(std::string newId)
{
	id = newId;

	return 0;
}

std::string Node::getId(void)
{
	return id;
}

int Node::setValue(unsigned int newValue)
{
	value = newValue;
	
	return 0;
}

unsigned int Node::getValue(void)
{
	return value;
}

int Node::addLink(std::string linkedId, Node* linkedPtr)
{
	auto pair = std::make_pair(linkedId, linkedPtr);
	links.insert(pair);

	return 0;
}

std::string Node::toString(void)
{
	std::string result;

	result = id + ", " + std::to_string(value);
	for (auto& iterator : links) {
		result += ", " + iterator.second->getId();	// Not sure if works
	}

	return result;
}
