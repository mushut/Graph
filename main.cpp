/* Graph
 * Aki Sipovaara 2018
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include "graph.h"

bool stringsMatch(std::string first, std::string second) {
	return first.compare(second);
}

// NEEDS FUNCTIONS AND OOP APPROACH!
// Graph data is read from a csv file given as an argument to the program.
int main(int argc, char** argv)
{
	std::cout << "Graph" << std::endl;

	std::ifstream input;
	input.open(*(argv + 1), std::ifstream::in);

	// New approach variables
	Graph graph(1);
	std::vector<std::vector<std::pair<std::string, std::string>>> nodesLinks;

	// Old approch variables
	std::string line;
	std::stringstream stream;	// row
	std::stringstream values;	// values
	std::string delimiter = ",";
	std::vector<std::string> data;
	std::vector<std::pair<std::string, std::string>> links;	// Are pairs needed actually?
	std::vector<Node> nodes;
	std::string tempString;

	// Read values from csv file
	while (std::getline(input, line)) {
		std::string value;
		std::string temp;
		std::string linkFrom;
		std::pair<std::string, std::string> linkPair;
		int index = 0;
		Node newNode(index);

		stream << line;
		while(std::getline(stream, temp, '\n')) {
			values << temp;
			while(std::getline(values, value, ',')) {		
				switch (index) {
					case 0:
						newNode.setId(value);
						linkFrom = value;
						index++;
						value.clear();
						break;
					case 1:
						newNode.setValue(std::stoi(value));
						index++;
						value.clear();
						break;
					default:
						// Save link data to links
						linkPair = std::make_pair(linkFrom, value);
						links.push_back(linkPair);
						index++;	
						value.clear();
				}
			}
	
			nodesLinks.push_back(links);
		
			nodes.push_back(newNode);
		}
	}

	input.close();

	// Create links according to csv file
	for (auto iterNode = nodes.begin(); iterNode != nodes.end(); ++iterNode) {
		for (auto iterator = nodesLinks.begin(); iterator != nodesLinks.end(); ++iterator) {
			for (auto iterLinks = iterator->begin(); iterLinks != iterator->end(); ++iterLinks) {
				std::pair<std::string, std::string> temp(*iterLinks);
				std::string from = temp.first;
				std::string to = temp.second;
	
				auto foundNode = find_if(nodes.begin(), nodes.end(), 
					[to](Node node)
						{
							std::string str(node.getId());
							return str.compare(to) == 0;
						});
				if (foundNode != nodes.end()) {
					iterNode->addLink(from, &*foundNode);
				}
			}
		}
	}

	for (auto iterator = nodes.begin(); iterator != nodes.end(); ++iterator) {
		graph.addNode(*iterator);
	}
	
	std::cout << graph.toString();

	return 0;
}
