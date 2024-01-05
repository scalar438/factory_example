#include "plugin.hpp"
#include <factory_object_1.hpp>
#include <iostream>
#include <memory>

int main()
{
	{
		// Just for test
		auto ptr = Object1Factory::create("None");
		if (ptr)
		{
			std::cout << "Fail\n";
			return 0;
		}
	}

	{
		const std::string type = "FooBar";
		auto ptr = Object1Factory::create(type);
		if (ptr)
		{
			std::cout << "Fail, the object with type \"" << type << "\" has been created before plugin loading\n";
			return 0;
		}
		auto plugin = std::make_unique<Plugin>("dyn_lib");

		ptr = Object1Factory::create(type);
		if (!ptr)
		{
			std::cout << "Fail, the object with type \"" << type
			          << "\" hasn't been created after plugin loading\"";
			return 0;
		}

		std::cout << "Object type: " << ptr->type() << '\n'
		          << "Object class name: " << ptr->class_name() << '\n';

		// We have to destroy the object before unloading plugin
		ptr = std::unique_ptr<Object1>();

		plugin = std::unique_ptr<Plugin>();

		ptr = Object1Factory::create(type);
		if (ptr)
		{
			std::cout << "Fail, the object with type \"" << type
			          << "\" has been created after plugin unloading\n";
			return 0;
		}
		std::cout << "Everything is Ok\n";
	}
}