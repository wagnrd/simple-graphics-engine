cmake_minimum_required(VERSION 3.16)
project(simple_graphics_engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(
        INCLUDES

        includes/engine.hpp
        includes/node.hpp
        includes/component.hpp
        includes/system.hpp
        includes/components/transform.hpp
        includes/components/mover.hpp
        includes/components/camera.hpp
        includes/systems/null_renderer.hpp
        includes/systems/text_renderer/text_renderer.hpp
        includes/systems/text_renderer/text_screen.hpp
        includes/systems/text_renderer/displays/console_display.hpp
        libs/thread-pool/thread_pool.hpp
)

set(
        SOURCES

        src/main.cpp
        src/engine.cpp
        src/node.cpp
        src/components/mover.cpp
        src/components/camera.cpp
        src/systems/text_renderer/text_renderer.cpp
        src/systems/text_renderer/displays/console_display.cpp
)

add_subdirectory(libs/glm)

find_package(Threads REQUIRED)

add_executable(
        simple_graphics_engine

        ${SOURCES}
        ${INCLUDES}
)

target_link_libraries(
        simple_graphics_engine PRIVATE

        Threads::Threads
        glm
)