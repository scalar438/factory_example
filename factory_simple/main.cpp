#include <iostream>

#include "base.hpp"
#include "factory.hpp"

int main()
{
	Factory f;

	{
		auto x = f.make_object("Derived1");
		if (x) std::cout << x->type();
	}

	{
		auto x = f.make_object("Derived2");
		if (x) std::cout << x->type();
	}
}
