cmake_minimum_required(VERSION 3.10)

project(YourProjectName)

add_executable(pointer_exe pointer.cpp)

target_link_libraries(pointer_exe PRIVATE stdc++)

set_property(TARGET pointer_exe PROPERTY CXX_STANDARD 11)
