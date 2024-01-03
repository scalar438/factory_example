#pragma once
#include <factory_object_1.hpp>

class Object1InDyn1 : public Object1
{
public:
	Object1InDyn1();

	std::string type() const override;

	std::string class_name() const override;
};