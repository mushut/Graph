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
#include "node.h"

// NEEDS FUNCTIONS AND OOP APPROACH!
// Graph data is read from a csv file given as an argument to the program.
int main(int argc, char** argv)
{
	std::cout << "Graph" << std::endl;

	std::ifstream input;
	input.open(*(argv + 1), std::ifstream::in);

	std::string line;
	std::stringstream stream;
	std::string delimiter = ",";
	std::vector<std::string> data;
	std::vector<std::pair<std::string, std::string>> links;	// Are pairs needed actually?
	std::vector<Node> nodes;
	std::string tempString;

	// Try std::getline(input, value, ',')
	while (std::getline(input, line)) {
		std::string value;
		std::string linkFrom;
		std::pair<std::string, std::string> linkPair;
		int index = 0;
		Node newNode(index);

		stream << line;
		while(std::getline(stream, value, ',')) {
			switch (index) {
				case 0:
					newNode.setId(value);
					linkFrom = value;
					index++;
					break;
				case 1:
					newNode.setValue(std::stoi(value));
					index++;
					break;
				default:
					// Save link data to links
					linkPair(linkFrom, value);
					links.push_back(linkPair);
					index++;	
			}
		}
		
		// This must be done outside the while loop (at first there are no nodes...)
		// Go through links and make node references accordingly
		for (auto iterator = links.begin(); iterator != links.end(); ++iterator) {
			std::pair<std::string, std::string> temp(*iterator);
			std::string from = temp.first;
			std::string to = temp.second;

			auto foundNode = find_if(nodes.begin(), nodes.end(), [&to](Node& tempNode) {return tempNode.getId() == to;});
			if (foundNode != nodes.end()) {
				newNode.addLink(to, &*foundNode);
			}
		}

		nodes.push_back(newNode);
	}

	for (auto iterator = nodes.begin(); iterator != nodes.end(); ++iterator) {
		std::cout << iterator->toString() << std::endl;
	}
	
	input.close();

	return 0;
}
