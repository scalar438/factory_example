#include "object2_impl.hpp"
#include <string>

Object2General::Object2General() {}

std::string Object2General::type() const
{
	return "Qwe";
}

std::string Object2General::sub_type() const
{
	return "Unknown";
}

std::string Object2General::class_name() const
{
	return "Object2General";
}

// Object2Specific
Object2Specific::Object2Specific() {}

std::string Object2Specific::type() const
{
	return "Qwe";
}

std::string Object2Specific::sub_type() const
{
	return "Rty";
}

std::string Object2Specific::class_name() const
{
	return "Object2Specific";
}
