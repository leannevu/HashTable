#include <memory>
#include <string>
#include "HashFunction.h"
#include <vector>
#include <iostream>
using namespace std;

struct Node {
	Node();
	Node(shared_ptr<string> key, int value, shared_ptr<Node> next);
	shared_ptr<string> key_;
	int value_;
	shared_ptr<Node> next_;
};

class HashTable {
public:
	//Public constructor, indicates how large to make the initial table.
	HashTable(int size);

	shared_ptr<Node> SetNode(shared_ptr<string> key, int value, shared_ptr<Node> next);

	//Insert an element in the table
	void Insert(std::shared_ptr<std::string> key, int value);

	//is an element present in the table
	bool Contains(std::shared_ptr<std::string> key);

	//Find an element in the index
	int Get(std::shared_ptr<std::string> key);

	//Remove a node referenced by std::string.
	void Remove(std::shared_ptr<std::string> key);

private:
	shared_ptr<HashFunction> hash_function;
	shared_ptr<Node> table[10000];
};