#pragma once

#include <memory>
#include <string>

class Base;

template <class T> std::unique_ptr<Base> make_one(const std::string &type);

template <class T> class Types
{
	const static std::string type;

	// Friend does allow to acces to the constant only from corresponding classes.
	friend T;
	friend std::unique_ptr<Base> make_one<T>(const std::string &type);
};
