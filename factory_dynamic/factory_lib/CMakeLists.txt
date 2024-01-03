add_library(factory_lib SHARED factory_lib.cpp)

target_include_directories(factory_lib INTERFACE "include")

set_property(TARGET factory_lib PROPERTY CXX_STANDARD 20)

target_compile_definitions(factory_lib PRIVATE FACTORY_SHARED_LIB)