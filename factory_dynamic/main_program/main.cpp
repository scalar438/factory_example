#include <factory_object_1.hpp>
#include <iostream>

int main()
{
	auto ptr = Object1Factory::create("None");
//	if (ptr) std::cout << "Fail\n";
}