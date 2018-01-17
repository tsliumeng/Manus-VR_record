cmake_minimum_required(VERSION 3.1)
project(Manus_VR)

set(CMAKE_CXX_STANDARD 11)


add_executable(Manus_VR main.cpp)
target_link_libraries(Manus_VR libmanus.so)

