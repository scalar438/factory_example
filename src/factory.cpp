#include "factory.hpp"

#include "constants.hpp"

#include "derived.hpp"

#include <memory>

template <class T> std::unique_ptr<Base> make_one(const std::string &type)
{
	if (Types<T>::type == type) return std::make_unique<T>();
	return nullptr;
}

template <class... Args> std::unique_ptr<Base> make_all(const std::string &type)
{
	for (auto func : {make_one<Args>...})
	{
		if (auto ptr = func(type)) return ptr;
	}
	return nullptr;
}

std::unique_ptr<Base> Factory::make_object(const std::string &type)
{
	return make_all<Derived1, Derived2>(type);
}
