#project(test)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(beans)
add_subdirectory(Parser)

#找到所有cpp文件
aux_source_directory(. cppsrc)
aux_source_directory(${CMAKE_SOURCE_DIR}/test/beans/Singer singersrc)
aux_source_directory(${CMAKE_SOURCE_DIR}/test/beans/Song songsrc)

#引入本目录外的头文件
include_directories(${CMAKE_SOURCE_DIR}/test/beans)
include_directories(${CMAKE_SOURCE_DIR}/test/beans/Singer)
include_directories(${CMAKE_SOURCE_DIR}/test/beans/Song)
include_directories(${CMAKE_SOURCE_DIR}/test/Parser)
include_directories(${CMAKE_SOURCE_DIR}/json)

#message(${CMAKE_SOURCE_DIR}/json)
#find 工程外部 .a 但是自带的库不需要这个命令的
link_directories(${CMAKE_SOURCE_DIR}/libs)
#message(${CMAKE_SOURCE_DIR}/libs)

add_executable(exef ${cppsrc} ${singersrc} ${songsrc})
#引用 功能外部  .a 用""方式 手动加上 liblibjsoncpp.a
target_link_libraries(
        exef
        "jsoncpp"
        #ws2_32 用系统的库，直接这么些就ok了。
)
