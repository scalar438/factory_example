#include "derived1.hpp"
#include "constants.hpp"

const std::string& Derived1::type() const
{
	return Types<Derived1>::type;
}
