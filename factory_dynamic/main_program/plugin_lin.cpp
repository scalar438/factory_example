#include "plugin.hpp"
#include <dlfcn.h>


struct Plugin::Pimpl
{
	void *handle;
};

Plugin::Plugin(const std::string &dll_name) : pimpl(std::make_unique<Pimpl>())
{
	std::filesystem::path dll_path = "./lib" + dll_name + ".so";
	auto handle                    = dlopen(dll_path.c_str(), RTLD_NOW);
	if (!handle) throw PluginLoadException(dll_path.generic_string());
	pimpl->handle = handle;
}

Plugin::~Plugin()
{
	dlclose(pimpl->handle);
}