#pragma once
#include "factory_basic.hpp"
#include <memory>
#include <string>

class Object2
{
public:
	~Object2() {}
	virtual std::string type() const     = 0;
	virtual std::string sub_type() const = 0;

	virtual std::string class_name() const = 0;
};

class Object2Factory : public BasicFactory<Object2, Object2Factory>
{
public:
	Object2Factory() { register_factory(this); }
	~Object2Factory() { unregister_factory(this); }

	virtual std::unique_ptr<Object2> create_object(const std::string &object_type) = 0;
};