cmake_minimum_required(VERSION 3.13)
project(BasicAlgorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(BasicAlgorithm main.cpp heap.h heap.cpp bytedance/max_map.cpp)