#include "object1_factory_impl.hpp"
#include "object1_impl.hpp"
#include <memory>

namespace
{
Object1FactoryImpl factory_instance;
}



std::unique_ptr<Object1> Object1FactoryImpl::create_object(const std::string &object_type)
{
	if (object_type == "FooBar") return std::make_unique<Object1InDyn1>();
	return nullptr;
};