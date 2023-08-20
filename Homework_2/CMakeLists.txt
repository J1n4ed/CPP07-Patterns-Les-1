cmake_minimum_required(VERSION 3.26)

project(builder_1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR})
add_executable( builder_1 main.cpp sql_query_builder.cpp)