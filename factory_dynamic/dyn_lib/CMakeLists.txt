add_library(dyn_lib SHARED 
            object1_factory_impl.cpp object1_impl.cpp
            object2_factory_impl.cpp object2_impl.cpp)

target_link_libraries(dyn_lib PUBLIC factory_lib)

set_property(TARGET dyn_lib PROPERTY CXX_STANDARD 20)