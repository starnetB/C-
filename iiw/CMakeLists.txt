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
add_executable(zeban 递归/zeban.cpp)
add_executable(singleton DesignerMode/Singleton/singleton.cpp)
include_directories( DesignerMode/AbstractFactoryPattern)
add_executable(abstractfatory DesignerMode/AbstractFactoryPattern/abstract.cpp
                              DesignerMode/AbstractFactoryPattern/Factory.cpp)
add_executable(observer DesignerMode/ObserverPattern/observer.cpp)
                              
add_executable(train0 train/train0.cpp)                         
add_executable(train1 train/train1.cpp)
add_executable(train2 train/train2.cpp)
add_executable(train3 train/train3.cpp)
add_executable(train4 train/train4.cpp)


