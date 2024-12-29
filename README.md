# Factory example

Let's say we have a base class and a factory that creates classes derived from it, based on the given type, like this:
```cpp
auto obj = factory.make_object("foo"); // Trying to create an object of type "foo"
// Using the created object
if (obj) std::cout << obj->type();
```

A naive implementation of the 'make_object' method contains plenty of ugly ifs:
```cpp
// constants.h
const static std::string derived_type1;
const static std::string derived_type2;
...

// Factory implementation
std::unique_ptr<BaseObject> Factory::make_object(std::string type)
{
  if (type == derived_type1) return std::make_unique<Derived1>();
  if (type == derived_type2) return std::make_unique<Derived2>();
// etc
}
```
This is horrible, isn't it? 
This repository suggests an alternative approach that allows us to extend the factory dynamically
```cpp
{
   ...
   auto handle = dlopen("lib_which_can_create_my_object_type.so"); // That's it, we don't need to do anything else
   auto object = factory.make_object("my_object_type"); // Create an object
   ...
   dlclose(handle);
}
```
