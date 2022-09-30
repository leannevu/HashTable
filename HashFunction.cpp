#include <memory>
#include <string>
#include "HashFunction.h"

HashFunction::HashFunction() {}

int HashFunction::Hash(shared_ptr<string> key) {
	string dereferenced_key = *key;
	int seed = 182;

	if ((*key).compare("") == 0) {
		return 0;
	}

	unsigned int hash = 0;
	for (int i = 0; i < dereferenced_key.length(); i++)
	{
		hash = (hash * seed) + dereferenced_key[i];
	}
	return hash % 10000;
}