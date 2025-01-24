#pragma once
#include "exp_macro.hpp"
#include <memory>
#include <mutex>
#include <type_traits>
#include <unordered_set>

// The class contains the basis code for every factory
// It shouldn't be used by the end user (i.e plugin's author) directly. 
// It's supposed to be used only if you want to declare a new factory for the new object type
template <class Base, class FactoryType> class FACTORY_SPEC BasicFactory
{
public:
	template <class... Args> static std::unique_ptr<Base> create(Args... args)
	{
		std::lock_guard l(s_mtx_factories);

		for (auto f : s_factories)
		{
			auto res = f->create_object(std::forward<Args>(args)...);
			if (res) return res;
		}
		return nullptr;
	}

protected:
	void register_factory(FactoryType *factory)
	{
		std::lock_guard l(s_mtx_factories);
		s_factories.insert(factory);
	}

	void unregister_factory(FactoryType *factory)
	{
		std::lock_guard l(s_mtx_factories);
		s_factories.erase(factory);
	}

private:
	static std::unordered_set<FactoryType *> s_factories;

	static std::mutex s_mtx_factories;
};

#ifndef _MSC_VER
template <class Base, class FactoryType>
std::unordered_set<FactoryType *> BasicFactory<Base, FactoryType>::s_factories;

template <class Base, class FactoryType>
std::mutex BasicFactory<Base, FactoryType>::s_mtx_factories;
#endif