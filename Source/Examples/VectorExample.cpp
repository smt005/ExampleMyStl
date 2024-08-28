
#include "HeadersExample.h"
#include "../../mystl/vector.h"

template <typename VecT, int count = 5>
void FunForEmplaceBack()
{
	std::cout << "FunForEmplaceBack(" << typeid(VecT).name() << ", " << count << ")" << std::endl;

	VecT v;
	std::cout << "sizeof(" << typeid(VecT).name() << ") == " << sizeof(v) << " (" << (sizeof(v) / 8) << ")" << std::endl;

	for (size_t i = 0; i < count; ++i) {
		v.emplace_back(i);
		std::cout << std::endl << std::endl;
	}
	std::cout << "size: " << v.size() << std::endl;

	for (size_t i = 0; i < count; ++i) {
		std::cout << v[i] << std::endl;
	}
}

void Fun01()
{
	//std::cout << "\n\nSTD" << std::endl;
	//FunForEmplaceBack<std::vector<int>>();

	//std::cout << "\n\nMY STD" << std::endl;
	//FunForEmplaceBack<mystd::vector<int>>();

	try {
		std::cout << "\n\nSTD" << std::endl;
		FunForEmplaceBack<std::vector<TestClass>>();
	}
	catch (...) {
		std::cout << "\n\naccept" << std::endl;
	}

	try {
		std::cout << "\n\nMY STD" << std::endl;
		FunForEmplaceBack<mystd::vector<TestClass>>();
	}
	catch (...) {
		std::cout << "\n\naccept" << std::endl;
	}
}

void VectorExample()
{
	Fun01();
}
