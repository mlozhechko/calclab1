cmake_minimum_required(VERSION 3.10)
project(calc1)

set(CMAKE_CXX_STANDARD 17)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(calc1 project/main.cpp project/system_solver.h project/system_solver.cpp)