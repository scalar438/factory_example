#pragma once
#include "basic_factory.hpp"
#include <memory>
#include <string>

class Object1
{
public:
	~Object1() {}
	virtual std::string type() const = 0;

	virtual std::string class_name() const = 0;
};

class Object1Factory : public BasicFactory<Object1, Object1Factory>
{
public:
	Object1Factory() { register_factory(this); }
	~Object1Factory() { unregister_factory(this); }

	virtual std::unique_ptr<Object1> create_object(const std::string &object_type) = 0;
};