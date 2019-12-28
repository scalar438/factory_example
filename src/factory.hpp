#pragma once
#include <memory>

#include "base.hpp"

class Factory
{
public:
    std::unique_ptr<Base> create_class(const std::string &type);
};
