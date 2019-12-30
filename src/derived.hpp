#pragma once
#include "base.hpp"

class Derived1 : public Base
{
public:
    const std::string &type() const override;
};

class Derived2 : public Base
{
public:
    const std::string &type() const override;
};
