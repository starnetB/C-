project(cplpl)

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

add_executable(384 384.cpp)
add_executable(385 385.cpp)
add_executable(386 386.cpp)
