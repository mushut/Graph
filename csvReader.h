/* Graph
 * Aki Sipovaara 2018
 */

#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include "graph.h"

class CsvReader
{
public:
	CsvReader(std::string inputFile);
	Graph* readFile(void);
	bool readRow(std::string *output);
private:
	std::string filename;
	std::ifstream input;
}
