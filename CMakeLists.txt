cmake_minimum_required(VERSION 2.6)
project(Snakes)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(Snakes ${SOURCES})

set_property(TARGET Snakes PROPERTY CXX_STANDARD 17)
target_link_libraries(Snakes ${CURSES_LIBRARIES})
# TODO: Run -Werror in CI.
target_compile_options(Snakes PRIVATE -Wall -Wextra)
