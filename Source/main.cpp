
#include <iostream>
#include "Examples/HeadersExample.h"

int main() {
	std::cout << "START" << std::endl;

	VectorExample();

	char chars[32];
	std::cin >> chars;
	std::cout << "END: " << chars << std::endl;
}
