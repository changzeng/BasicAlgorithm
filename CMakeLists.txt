cmake_minimum_required(VERSION 3.13)
project(BasicAlgorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(BasicAlgorithm main.cpp basic_algorithm/heap.h basic_algorithm/heap.cpp bytedance/max_map.cpp
        basic_algorithm/tranverse_tree.cpp basic_algorithm/tranverse_tree.cpp basic_algorithm/graph_algorithm.cpp
        basic_algorithm/linked_list.cpp bytedance/distance_sort.cpp didi/russian_doll.cpp meituan/increase_decrease_find_max.cpp meituan/front_k_behind_k_avg.cpp meituan/exchange_get_max_number.cpp xiaomi/cards_order.cpp)