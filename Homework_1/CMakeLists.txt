cmake_minimum_required(VERSION 3.27...3.28)

project(builder_1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR})
add_executable( builder_1 main.cpp sql_query_builder.cpp)