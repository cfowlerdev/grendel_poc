cmake_minimum_required(VERSION 3.21)

project(grendelpoc VERSION 0.1)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE HEADERS include/*.h)
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/libs
)

if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX .html)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-O2 -s USE_GLFW=3 -s WASM=1 -s USE_WEBGL2=1 -s STB_IMAGE=1 --bind --preload-file ${CMAKE_CURRENT_SOURCE_DIR}/assets@/assets")

else()
    find_package(OpenGL REQUIRED)
endif()
