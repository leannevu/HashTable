#include <memory>
#include <string>
#include "HashTable.h"
using namespace std;

class Index {
public:
	//public constructor
	Index();

	//Insert an element in the index, associate the integer value with the element
	void Insert(std::shared_ptr<std::string> key, int value);

	//Find an element in the index
	int Find(std::shared_ptr<std::string> key);

	//Remove an element from the index
	void Remove(std::shared_ptr<std::string> key);

private:
	int size = 10000;
	shared_ptr<HashTable> hash;

};