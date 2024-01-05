add_library(factory_lib SHARED src/factory_object_1.cpp src/factory_object_2.cpp)

target_include_directories(factory_lib INTERFACE "include")

set_property(TARGET factory_lib PROPERTY RUNTIME_OUTPUT_DIRECTORY "../main_program")

set_property(TARGET factory_lib PROPERTY CXX_STANDARD 20)

target_compile_definitions(factory_lib PRIVATE FACTORY_SHARED_LIB)