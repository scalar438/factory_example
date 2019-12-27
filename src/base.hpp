#pragma once
#include <string>

class Base
{
public:
	virtual ~Base() = default;
	virtual const std::string& type() const = 0;
};
