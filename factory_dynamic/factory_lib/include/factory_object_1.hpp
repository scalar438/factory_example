#pragma once
#include "basic_factory.hpp"
#include "exp_macro.hpp"
#include <memory>
#include <string>

// A base object constructed by the factory
class Object1
{
public:
	virtual ~Object1() {}
	virtual std::string type() const = 0;

	virtual std::string class_name() const = 0;
};

// The basic factory class for Object1. The end user should derive their classes from it
class FACTORY_SPEC Object1Factory : public BasicFactory<Object1, Object1Factory>
{
protected:
	// User shouldn't create the factory manually, so make them protected
	Object1Factory();
	~Object1Factory();

public:
	virtual std::unique_ptr<Object1> create_object(const std::string &object_type) = 0;
};
