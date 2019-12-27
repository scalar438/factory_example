project(factory)

add_executable(factory main.cpp base.hpp 
       derived1.hpp derived1.cpp 
       derived2.hpp derived2.cpp 
       factory.hpp factory.cpp
       constants.hpp constants.cpp)