/* Graph
 * Aki Sipovaara 2018
 */

#include <iostream>
#include <ifstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include "node.h"

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
	std::vector<std::pair<std::string, std::string>> links;
	std::vector<Node> nodes;
	std::string tempString;
	while (std::getline(input, line) {
		Node newNode();

		// Parse csv data from file. One row equals one node data.
		stream << line;
		while (stream >> tempString) {
			data.push_back(tempString);

			if (stream.peek() == ',') {
				stream.ignore();
			}
		}

		// Construct object from parsed data and add links to vector
		newNode.setId(data[0]);
		newNode.setValue(std::stoi(data[1]));
		if (data.size() > 2) {
			for (int i = 2; i < data.size(); i++) {
				std::pair link(data[0],data[i]);
				links.push_back(link);
			}
		}

		nodes.push_back(newNode);
	}
	input.close();

	// Link nodes according to data
	// Objects must be searchable by id. Save pointers to objects.
	
	// Go through the links list element by element
	// Search nodes vector for element with id corresponding to links[0]
	// Search nodes vector for element with id corresponding to links[1] and save it's address
	// Add element to unordered_map for node
	// TBD

	return 0;
}
