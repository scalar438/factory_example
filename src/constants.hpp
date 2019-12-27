#pragma once

#include <string>
#include <memory>

class Base;

template<class T>
std::unique_ptr<Base> create_class(const std::string& type);

template<class T> class Types
{
	const static std::string type;
	friend T;
	friend std::unique_ptr<Base> create_class<T>(const std::string& type);
};
