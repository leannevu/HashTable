#include <memory>
#include <string>
using namespace std;

class HashFunction {
public:
	//Public Constructor
	HashFunction();

	//Compute hash for an arbitrarily long string
	int Hash(std::shared_ptr<std::string>);

};