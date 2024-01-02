#pragma once
#include <type_traits>
#include <unordered_set>

template <class Base, class FactoryType> class FactoryBase
{
	static_assert(std::is_base_of_v<FactoryBase<Base, FactoryType>, FactoryType>);

public:
	FactoryBase() {}

	void register_factory(FactoryType *factory) { s_factories.insert(factory); }

	void unregister_factory(FactoryType *factory) { s_factories.erase(factory); }

	template <class... Args> std::unique_ptr<Base> create(Args... args)
	{
		for (auto f : s_factories)
		{
			auto res = f->create_object(std::forward(args)...);
			if (res) return res;
		}
	}

private:
	static std::unordered_set<FactoryType *> s_factories;
};