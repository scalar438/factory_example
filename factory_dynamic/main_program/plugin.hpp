#pragma once

#include <exception>
#include <filesystem>
#include <memory>

class PluginLoadException : public std::runtime_error
{
public:
	PluginLoadException(std::string plugin_name)
	    : std::runtime_error("Couldn't load plugin " + plugin_name)
	{}
};

class Plugin
{
public:
	Plugin(const std::string &dll_name);
	~Plugin();

private:
	struct Pimpl;
	std::unique_ptr<Pimpl> pimpl;
};