cmake_minimum_required(VERSION 3.24)
project(project_library)

set(CMAKE_CXX_STANDARD 17)

add_executable(project_library src/main.cpp src/Book.cpp include/Book.h src/Library.cpp include/Library.h include/FantasyBook.h src/FantasyBook.cpp)
