#include "plugin.hpp"
#include <Windows.h>


struct Plugin::Pimpl
{
	HMODULE handle;
};

Plugin::Plugin(const std::string &lib_name) : pimpl(std::make_unique<Pimpl>())
{
	auto dll_name = lib_name + ".dll";
	auto hlib     = LoadLibraryA(dll_name.c_str());
	if (hlib == NULL) throw PluginLoadException(dll_name);
	pimpl->handle = hlib;
}

Plugin::~Plugin()
{
	FreeLibrary(pimpl->handle);
}