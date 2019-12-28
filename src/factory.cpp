#include "factory.hpp"

#include "constants.hpp"

#include "derived1.hpp"
#include "derived2.hpp"

#include <memory>

template <class T> std::unique_ptr<Base> create_class(const std::string &type)
{
	if (Types<T>::type == type) return std::make_unique<T>();
	return nullptr;
}

template <class... Args> std::unique_ptr<Base> create_all(const std::string &type)
{
	for (auto func : {create_class<Args>...})
	{
		if (auto ptr = func(type)) return ptr;
	}
	return nullptr;
}

std::unique_ptr<Base> Factory::create_class(const std::string &type)
{
	return create_all<Derived1, Derived2>(type);
}
