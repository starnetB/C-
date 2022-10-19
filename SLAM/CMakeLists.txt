cmake_minimum_required(VERSION 3.2)
project(EigenMatrix)

find_package(Eigen3 REQUIRED)

include_directories("/usr/include/eigen3")

add_executable(test eigenMatrix.cpp)