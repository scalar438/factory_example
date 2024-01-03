#include "../include/factory_object_2.hpp"

Object2Factory::Object2Factory()
{
	register_factory(this);
}

Object2Factory ::~Object2Factory()
{
	unregister_factory(this);
}