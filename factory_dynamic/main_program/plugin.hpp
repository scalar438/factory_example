#pragma once

#include <filesystem>

class Plugin
{
public:
	Plugin(std::filesystem::path dll_name);
	~Plugin();

private:
	struct Pimpl;
	std::unique_ptr<Pimpl> pimpl;
};