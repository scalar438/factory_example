add_subdirectory(main_program)

add_subdirectory(factory_lib)

add_subdirectory(dyn_lib)

set_target_properties(main_program factory_lib dyn_lib
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/factory_dynamic/bin_all"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/factory_dynamic/bin_all"
)