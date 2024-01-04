#include "../include/factory_object_1.hpp"

template class BasicFactory<Object1, Object1Factory>;

std::unordered_set<Object1Factory *> BasicFactory<Object1, Object1Factory>::s_factories;

std::mutex BasicFactory<Object1, Object1Factory>::s_mtx_factories;

Object1Factory::Object1Factory()
{
	register_factory(this);
}

Object1Factory ::~Object1Factory()
{
	unregister_factory(this);
}