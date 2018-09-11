/* Graph
 * Aki Sipovaara 2018
 */

#include "csvReader.h"

CsvReader::CsvReader(std::string inputFile)
{
	input = inputFile;
}

Graph* CsvReader::readFile(void)
{
	Graph* result;
	std::string *row;
	input.open(input, std::ifstream::in);

	while (readRow(row)) {
		// Do something with row
	}

	input.close();

	return result;
}

bool readRow(std::string *output)
{
	bool result;
	char line[256];

	input.getline(line, 256, '\n');

	// Assign value to output
	// TBD
	
	return result;
}
