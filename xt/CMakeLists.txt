project(parse_osm)

cmake_minimum_required(VERSION 3.2)

# Settings.
# ---------
# set(TARGET optimizationExample CACHE TYPE STRING)
set(TARGET osmparser CACHE TYPE STRING)

# set install path
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install) 

# 加载头文件依赖
include_directories(
                include       
)
# OpenSim uses C++11 language features.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(malloc_free malloc_free.cpp)
add_executable(new_delete new_delete.cpp)
add_executable(reference reference.cpp)
add_executable(reference2 reference2.cpp)
add_executable(return_reference return_reference.cpp)
add_executable(function_reference function_reference.cpp)
add_executable(friend_fun friend_fun.cpp)
add_executable(friend_class friend_class.cpp)
add_executable(congxie 重载/congxie.cpp)
add_executable(fspluss_sub 重载/fspluss_sub.cpp)
add_executable(stack_dh 重载/stack_dh.cpp)
add_executable(fangkuohao 重载/fangkuohao.cpp)
add_executable(yuankuohao 重载/yuankuohao.cpp)
add_executable(plusplus 重载/plusplus.cpp)





