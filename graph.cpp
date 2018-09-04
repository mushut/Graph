/* Graph
 * Aki Sipovaara 2018
 */

#include "graph.h"
#include <algorithm>
#include <iterator>

bool myPredicate(Node first, std::string second) {
	return (first.getId() == second);
}

Graph::Graph(void)
{
}

Graph::Graph(int newId)
{
	id = newId;
}

int Graph::getId(void)
{
	return id;
}

int Graph::addNode(Node newNode)
{
	nodes.push_back(newNode);

	return 0;
}

int Graph::removeNode(std::string removedNode)
{
	for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
		if (iter->getId() == removedNode) {
			nodes.erase(iter);
			break;
		}
	}

	return 0;
}

Node* Graph::getNode(std::string nodeName)
{
	std::vector<std::string> searchNode;
	searchNode.push_back(nodeName);
	auto searchIterator = std::search (nodes.begin(), nodes.end(), searchNode.begin(), searchNode.end(), myPredicate);
	if (searchIterator != nodes.end()) {
		return &*searchIterator;
	}
	else {
		return NULL;
	}
}

std::string Graph::toString(void)
{
	std::string result = "";
	for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
		result += iter->toString() + "\n";
	}

	return result;
}
