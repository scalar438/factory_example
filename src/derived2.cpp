#include "derived2.hpp"
#include "constants.hpp"

const std::string& Derived2::type() const
{
	return Types<Derived2>::type;
}
