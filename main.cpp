/* Graph
 * Aki Sipovaara 2018
 */

#include <iostream>
#include <ifstream>
#include <string>
#include "node.h"

// Graph data is read from a csv file given as an argument to the program.
int main(int argc, char** argv)
{
	std::cout << "Graph" << std::endl;

	std::ifstream input;
	input.open(*(argv + 1), std::ifstream::in);

	std::string line;
	std::string delimiter = ",";
	while (std::getline(input, line) {
		Node newNode();

		// Parse csv data from file. One row equals one node data.
	}
	input.close();

	return 0;
}
