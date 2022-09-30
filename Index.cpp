#include "Index.h"
#include <iostream>

Index::Index() {
	hash = make_shared<HashTable>(10000);
}

void Index::Insert(std::shared_ptr<std::string> key, int value) {
	hash->Insert(key, value);
}

int Index::Find(std::shared_ptr<std::string> key) {
	return hash->Get(key);
}

void Index::Remove(std::shared_ptr<std::string> key) {
	hash->Remove(key);
}
