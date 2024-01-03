#include "object2_factory_impl.hpp"
#include "object2_impl.hpp"
#include <memory>

namespace
{
Object2FactoryImpl factory_instance;
}

std::unique_ptr<Object2> Object2FactoryImpl::create_object(const std::string &object_type)
{
	if (object_type == "Qwe") return std::make_unique<Object2General>();
	return nullptr;
}

std::unique_ptr<Object2> Object2FactoryImpl ::create_object(const std::string &object_type,
                                                            const std::string &object_sub_type)
{
	if (object_type == "Qwe")
	{
		if (object_sub_type == "Rty") return std::make_unique<Object2Specific>();
		return std::make_unique<Object2General>();
	}
	return nullptr;
}
