# Factory example

Let we have a base class containing type() method, and a factory that creates classes derived from the base by the given type like this:
```
auto obj = factory.make_object("foo");
if (obj) std::cout << obj->type(); // If the factory can create the object it is prints "foo"
```

Naive solution that I met contained ugly ifs like that:
```
// constants.h
const static std::string derived_type1;
const static std::string derived_type2;
...

// Factory implementation
if (type == derived_type1) return std::make_unique<Derived1>();
if (type == derived_type2) return std::make_unique<Derived2>();
// etc
```

This way is error-prone because we have to provide matching between constant in condition, type that passed to make_unique, and value returned by the type() method. This repo suggests another way - bind the constants to the type by template class and create object by the variadic template function.
