/* Graph
 * Aki Sipovaara 2018
 */

#include <vector>
#include <string>
#include "node.h"

class Graph
{
public:
	Graph(void);
	Graph(int newId);
	int getId(void);
	int addNode(Node newNode);
	int removeNode(std::string removedNode);
	Node* getNode(std::string nodeName);
	std::string toString(void);
private:
	int id;
	std::vector<Node> nodes;	// If large graphs are analyzed another container could be
					// more efficient (removing nodes could be faster)
};
