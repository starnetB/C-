project(parse_osm)

cmake_minimum_required(VERSION 3.2)

# Settings.
# ---------
# set(TARGET optimizationExample CACHE TYPE STRING)
set(TARGET osmparser)

# set install path
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install) 

# 加载头文件依赖
include_directories(
                include       
)
# OpenSim uses C++11 language features.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(virtual_inline virtual_inline.cpp)
add_executable(assert_sizeof_pragma assert_sizeof_pragma.cpp)
add_executable(enmu enmu.cpp)
add_executable(l_r_reference reference/l_r_reference.cpp)
add_executable(move reference/move.cpp)
add_executable(perfect reference/perfect.cpp)
#add_executable(dt dt.cpp)
add_executable(shape_virdeco shape_virdeco.cpp)
add_executable(allsort NK/allsort.cpp)
add_executable(spstack NK/spstack.cpp)
add_executable(SqQueQue NK/SqQueQue.cpp)
add_executable(CirSq NK/CirSq.cpp)
add_executable(SqStack NK/cc/SqStack.cpp)





