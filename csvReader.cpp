/* Graph
 * Aki Sipovaara 2018
 */

#include "csvReader.h"

CsvReader::CsvReader(std::string inputFile)
{
	filename = inputFile;
}

Graph* CsvReader::readFile(void)
{
	Graph* result;
	std::string row;
	char line[256];

	input.open(filename, std::ifstream::in);

	// Use rows to make graph. TBD.
	while (input.getline(line, 256, '\n')) {
		row = line;
		row.empty();
	}

	input.close();

	// For testing. Remove when testing is done
	Graph temp(1);
	result = &temp;
	return result;
}
