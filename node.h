/* Graph
 * Aki Sipovaara 2018
 */

#include <string>
#include <unordered_map>

class Node
{
public:
	Node(void);
	int setId(std::string newId);
	std::string getId(void);
	int setValue(unsigned int newValue);
	unsigned int getValue(void);
	int addLink(std::string linkedId, Node* linkedPtr);
	// int removeLink(std::string removeId);
	std::string mapToString(void);
	std::string toString(void);
private:
	std::string id;
	unsigned int value;
	std::unordered_map<std::string, Node*> links;
};
