set(main_program_sources)
list(APPEND main_program_sources main.cpp)

if (WIN32)
    list(APPEND main_program_sources plugin_win.cpp)
ELSE()
    list(APPEND main_program_sources plugin_lin.cpp)
ENDIF(WIN32)

add_executable(main_program ${main_program_sources})

if (WIN32)
    target_compile_definitions(main_program PRIVATE UNICODE)
ENDIF(WIN32)

target_link_libraries(main_program PRIVATE factory_lib)

set_property(TARGET main_program PROPERTY CXX_STANDARD 20)