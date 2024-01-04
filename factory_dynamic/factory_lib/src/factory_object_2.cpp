#include "../include/factory_object_2.hpp"

#ifdef _MSC_VER
std::unordered_set<Object2Factory *> BasicFactory<Object2, Object2Factory>::s_factories;

std::mutex BasicFactory<Object2, Object2Factory>::s_mtx_factories;
#endif

Object2Factory::Object2Factory()
{
	register_factory(this);
}

Object2Factory ::~Object2Factory()
{
	unregister_factory(this);
}