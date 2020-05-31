#include <iostream>
#include <string>

class TestClass {
public:
	TestClass();
	std::string getName() const;
private:
	std::string name;
};