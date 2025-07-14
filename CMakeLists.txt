cmake_minimum_required(VERSION 3.12)
project(raylib_web_example C)

# Require Emscripten
if(NOT EMSCRIPTEN)
    message(FATAL_ERROR "This project must be built with Emscripten. Run: source emsdk_env.sh && emcmake cmake .")
endif()

# Set C standard
set(CMAKE_C_STANDARD 99)

# Paths
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/extern/raylib)

# Include headers
include_directories(${INCLUDE_DIR})
include_directories(${RAYLIB_DIR}/src)

# Collect all .c files in src/
file(GLOB_RECURSE PROJECT_SOURCES ${SRC_DIR}/*.c)

# Compile each .c to its own .o file for parallel build
add_library(project_objects OBJECT ${PROJECT_SOURCES})

add_executable(index.html $<TARGET_OBJECTS:project_objects>)

target_link_libraries(index.html
    ${RAYLIB_DIR}/build/raylib/libraylib.a
)

target_link_options(index.html PRIVATE
    "-sUSE_GLFW=3"
    "-sASYNCIFY"
    "-sFORCE_FILESYSTEM=1"
    "-sALLOW_MEMORY_GROWTH=1"
    "-sFULL_ES2=1"
    "-sEXPORTED_FUNCTIONS=['_main']"
    "-sEXPORTED_RUNTIME_METHODS=['ccall','cwrap']"
)


set_target_properties(index.html PROPERTIES
    LINK_FLAGS "-O2"
)


# Set compile options
target_compile_definitions(index.html PRIVATE PLATFORM_WEB)
set_target_properties(index.html PROPERTIES LINK_FLAGS "-O2")

