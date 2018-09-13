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
private:
	std::string filename;
	std::ifstream input;
};
