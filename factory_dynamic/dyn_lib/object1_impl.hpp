#pragma once
#include <factory_object_1.hpp>

// Implementation for the Object1. Objects of this class will be returned from the factory
class Object1InDyn1 : public Object1
{
public:
	Object1InDyn1();

	std::string type() const override;

	std::string class_name() const override;
};