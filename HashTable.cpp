#include "HashTable.h"

HashTable::HashTable(int size) {
	//size fixed already fixed to 10000
	hash_function = make_shared<HashFunction>(); //using HashFunction object
}

shared_ptr<Node> HashTable::SetNode(shared_ptr<string> key, int value, shared_ptr<Node> next) {
	shared_ptr<Node> new_node = make_shared<Node>();
	new_node->key_ = key;
	new_node->value_ = value;
	new_node->next_ = next;
	return new_node;
}

void HashTable::Insert(std::shared_ptr<std::string> key, int value) {
	if (key == NULL) {
		return;
	}
	else {
		shared_ptr<Node> new_node = SetNode(key, value, NULL);
		int index = hash_function->Hash(key);
		if (Contains(key))
			Remove(key);

		if (table[index] == NULL) {
			table[index] = new_node;
			return;
		}
		else {
			shared_ptr<Node> curr = table[index];
			new_node->next_ = curr; //set the new node at the front of line
			table[index] = new_node;
		}
		return;
	}
}

bool HashTable::Contains(std::shared_ptr<std::string> key) {
	if (key == NULL) {
		return false;
	}
	else {
		int index = hash_function->Hash(key);
		shared_ptr<Node> curr = table[index];

		if (table[index] == NULL) {
			return false;
		}
		else if (table[index] != NULL) {
			if ((*curr->key_).compare(*key) == 0) { //check first node
				return true;
			}

			while (curr->next_ != NULL) { //check following nodes until there are no more
				if ((*curr->key_).compare(*key) == 0) {
					return true;
				}
				curr = curr->next_; //steps to next node
			}
			if ((*curr->key_).compare(*key) == 0) {
				return true;
			}
			return false; //no matches after checking
		}

		return false; //there is node at index to check
	}
}

int HashTable::Get(std::shared_ptr<std::string> key) {
	if (key == NULL) {
		return -1;
	}
	else {
		int index = hash_function->Hash(key);
		shared_ptr<Node> curr = table[index];

		if (table[index] == NULL) {
			return -1;
		}
		else if (table[index] != NULL) {
			if ((*curr->key_).compare(*key) == 0) { //check first node
				return curr->value_;
			}

			while (curr->next_ != NULL) { //check following nodes until there are no more
				if ((*curr->key_).compare(*key) == 0) {
					return curr->value_;
				}
				curr = curr->next_; //steps to next node
			}
			if ((*curr->key_).compare(*key) == 0) {
				return curr->value_;
			}
			return -1; //no matches after checking
		}

		return -1; //there is node at index to check
	}
}

void HashTable::Remove(std::shared_ptr<std::string> key) {
	if (key == NULL) {
		return;
	}
	else {
		int index = hash_function->Hash(key);
		shared_ptr<Node> curr = table[index];

		if (!Contains(key)) {
			return;
		}
		else if (curr->next_ != NULL) {
			if ((*curr->key_).compare(*key) == 0) { //first node w/ linked nodes
				table[index] = curr->next_;
				return;
			}
			while (curr->next_ != NULL && curr->next_->next_ != NULL) {
				if ((*curr->next_->key_).compare(*key) == 0) { //traverse through linked list
					curr->next_ = curr->next_->next_;
					return; //remove midway
				}
				curr = curr->next_;
			}
			if ((*curr->next_->key_).compare(*key) == 0) {
				curr->next_ = NULL;
				return; //remove last node
			}
		}
		else { //(curr->next_ == NULL)
			if ((*curr->key_).compare(*key) == 0) {
				table[index] = NULL; //remove first node
			}
			return;
		}
		return; //no removes
	}
}

Node::Node() {}

Node::Node(shared_ptr<string> key, int value, shared_ptr<Node> next) {
	key_ = key;
	value_ = value;
	next_ = next;
}
