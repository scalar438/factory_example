#pragma once
#include "basic_factory.hpp"
#include "exp_macro.hpp"
#include <memory>
#include <string>

// The same as for Object1 and it's factory class

class Object2
{
public:
	virtual ~Object2() {}
	virtual std::string type() const     = 0;
	virtual std::string sub_type() const = 0;

	virtual std::string class_name() const = 0;
};

class FACTORY_SPEC Object2Factory : public BasicFactory<Object2, Object2Factory>
{
public:
	Object2Factory();
	~Object2Factory();

	// If we have several ways to create the object, declare all possible methods here
	virtual std::unique_ptr<Object2> create_object(const std::string &object_type) = 0;

	virtual std::unique_ptr<Object2> create_object(const std::string &object_type,
	                                               const std::string &object_sub_type) = 0;
};