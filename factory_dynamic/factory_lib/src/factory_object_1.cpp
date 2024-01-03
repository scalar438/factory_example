#include "../include/factory_object_1.hpp"

Object1Factory::Object1Factory()
{
	register_factory(this);
}

Object1Factory ::~Object1Factory()
{
	unregister_factory(this);
}