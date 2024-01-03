add_executable(main_program main.cpp plugin.cpp)
target_link_libraries(main_program PRIVATE factory_lib)

set_property(TARGET main_program PROPERTY CXX_STANDARD 20)
