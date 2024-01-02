#include "object1_impl.hpp"
#include <string>

Object1InDyn1::Object1InDyn1() {}

std::string Object1InDyn1::type() const
{
	return "FooBar";
}

std::string Object1InDyn1::class_name() const
{
	return "Object1InDyn1";
}