#include <iostream>

#include "tuple.h"


using namespace experimental;

class foo {
public:
	int i = -100;
};

int main() {

	Tuple t;

	int a = 1;
	t.push_back(a);
	
	t.push_back(1);

	std::string s = "Arash";
	t.push_back(s);

	double d = 3.1415;
	t.push_back(d);

	t.push_back(3.1415);

	t.push_back(foo());


	std::cout << t[0].type().name() << std::endl;
	std::cout << t[1].type().name() << std::endl;
	std::cout << t[2].type().name() << std::endl;
	std::cout << t[3].type().name() << std::endl;
	std::cout << t[4].type().name() << std::endl;
	std::cout << t[5].type().name() << std::endl;
	
	try {
		std::cout << t[0].cast<double>() << std::endl;
	}

	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	



	

	
	

	getchar();
}