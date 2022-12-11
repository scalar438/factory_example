#pragma once
#include <memory>

#include "base.hpp"

class Factory
{
public:
	std::unique_ptr<Base> make_object(const std::string &type);
};
