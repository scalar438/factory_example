#include "constants.hpp"

class Derived1;
template <> const std::string Types<Derived1>::type = "Derived1";

class Derived2;
template <> const std::string Types<Derived2>::type = "Derived2";

// If we forget to define type for some classes, we will get linker error
