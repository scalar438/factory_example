#include "plugin.hpp"
#include <dlfcn.h>


struct Plugin::Pimpl
{
	void *handle;
};

Plugin::Plugin(std::filesystem::path dll_name) : pimpl(std::make_unique<Pimpl>())
{
	auto handle = dlopen(dll_name.c_str(), RTLD_NOW);
	if (!handle) throw PluginLoadException(dll_name.generic_string());
	pimpl->handle = handle;
}

Plugin::~Plugin()
{
	dlclose(pimpl->handle);
}