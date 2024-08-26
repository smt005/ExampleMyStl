
#include "HeadersExample.h"
#include "../../mystl/vector.h"

template <typename VecT, int count = 5>
void FunForEmplaceBack()
{
	std::cout << "FunForEmplaceBack(" << typeid(VecT).name() << ", " << count << ")" << std::endl;

	VecT v;

	for (size_t i = 0; i < count; ++i) {
		v.emplace_back(i);
	}
	std::cout << "size: " << v.size() << std::endl;

	for (size_t i = 0; i < count; ++i) {
		std::cout << v[i] << std::endl;
	}
}

void VectorExample()
{
	std::cout << "\n\nSTD" << std::endl;
	FunForEmplaceBack<std::vector<int>>();

	std::cout << "\n\nMY STD" << std::endl;
	FunForEmplaceBack<mystd::vector<int>>();

	std::cout << "\n\nSTD" << std::endl;
	FunForEmplaceBack<std::vector<TestClass>>();

	std::cout << "\n\nMY STD" << std::endl;
	FunForEmplaceBack<mystd::vector<TestClass>>();
}
