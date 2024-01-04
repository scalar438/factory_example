#pragma once
#include "exp_macro.hpp"
#include <memory>
#include <mutex>
#include <type_traits>
#include <unordered_set>

template <class Base, class FactoryType> class FACTORY_SPEC BasicFactory
{
	// static_assert(std::is_base_of_v<BasicFactory<Base, FactoryType>, FactoryType>);

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
