#pragma once
#include "basic_factory.hpp"
#include "exp_macro.hpp"
#include <memory>
#include <string>

class Object1
{
public:
	virtual ~Object1() {}
	virtual std::string type() const = 0;

	virtual std::string class_name() const = 0;
};

class FACTORY_SPEC Object1Factory : public BasicFactory<Object1, Object1Factory>
{
public:
	Object1Factory();
	~Object1Factory();

	virtual std::unique_ptr<Object1> create_object(const std::string &object_type) = 0;
};