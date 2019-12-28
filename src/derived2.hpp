#pragma once
#include "base.hpp"

class Derived2 : public Base
{
public:
    const std::string &type() const override;
};
