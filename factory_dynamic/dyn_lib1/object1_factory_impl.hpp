#pragma once
#include <factory_object_1.hpp>

class Object1FactoryImpl : public Object1Factory
{
public:
	std::unique_ptr<Object1> create_object(const std::string &object_type) override;
};