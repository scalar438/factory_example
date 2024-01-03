#pragma once
#include <factory_object_2.hpp>

class Object2General : public Object2
{
public:
	Object2General();

	std::string type() const override;

	std::string sub_type() const override;

	std::string class_name() const override;
};

class Object2Specific : public Object2
{
public:
	Object2Specific();

	std::string type() const override;

	std::string sub_type() const override;

	std::string class_name() const override;
};