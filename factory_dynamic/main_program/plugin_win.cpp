#include "plugin.hpp"
#include <Windows.h>


struct Plugin::Pimpl
{
	HMODULE handle;
};

Plugin::Plugin(std::filesystem::path dll_name) : pimpl(std::make_unique<Pimpl>())
{
	auto hlib = LoadLibrary(dll_name.c_str());
	if (hlib == NULL) throw PluginLoadException(dll_name.generic_string());
	pimpl->handle = hlib;
}

Plugin::~Plugin()
{
	FreeLibrary(pimpl->handle);
}