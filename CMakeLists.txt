cmake_minimum_required(VERSION 3.16)
project(DataStructure_Algorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        DataStructure_Algorithm
        main.cpp
        Algorithm/Jump_N_Step.hpp
        Algorithm/Max_Sum_of_Sub_Array.hpp
)
