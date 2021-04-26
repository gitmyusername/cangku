#一个文件夹对应一个CMakeLists.txt

cmake_minimum_required(VERSION 3.2)

#当前cmake.txt所在目录的名字
project(firstcmake)

set(Boost_USE_STATIC_LIBS ON)
set(CMAKE_VERBOSE_MAKEFILEON ON)

add_subdirectory(json)
#add_subdirectory(libs)
add_subdirectory(test)