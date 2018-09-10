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
	input.open(input, std::ifstream::in);

	while (

	input.close();

	return result;
}

bool CsvReader::readRow(std::string *output)
{
	bool result;
	char line[256];

	input.getline(line, 256, '\n');

	// Assign value to output
	// TBD
	
	return result;
}
