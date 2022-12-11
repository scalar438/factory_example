#include "derived.hpp"
#include "constants.hpp"

const std::string &Derived1::type() const
{
	return Types<Derived1>::type;
}

const std::string &Derived2::type() const
{
	// We cannot use neither Derived1 nor any other class here by mistake.
	return Types<Derived2>::type;
}
