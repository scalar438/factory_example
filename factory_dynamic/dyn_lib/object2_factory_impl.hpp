#pragma once
#include <factory_object_2.hpp>

class Object2FactoryImpl : public Object2Factory
{
public:
	std::unique_ptr<Object2> create_object(const std::string &object_type) override;

	std::unique_ptr<Object2> create_object(const std::string &object_type,
	                                       const std::string &object_sub_type) override;
};