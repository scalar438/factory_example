#include <iostream>

#include "base.hpp"
#include "factory.hpp"

int main()
{
	Factory f;

	{
		auto x = f.create_class("Derived1");
		if (x) std::cout << x->type();
	}

	{
		auto x = f.create_class("Derived2");
		if (x) std::cout << x->type();
	}
}