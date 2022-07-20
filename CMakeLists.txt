cmake_minimum_required(VERSION 3.16)
project(DataStructure_Algorithm)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        DataStructure_Algorithm
        main.cpp

        # Algorithm/Problem/Jump_N_Step.hpp
        # Algorithm/Problem/Max_Sum_of_Sub_Array.hpp
        # Algorithm/Problem/Match_The_Same_Birthday.hpp
        Algorithm/Problem/yanghui_tri.hpp

        # Algorithm/Sort/insert_sort.hpp
        Algorithm/Sort/radix_sort_jr.hpp
)
