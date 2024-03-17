cmake_minimum_required(VERSION 3.13.0)
project(practice)

add_executable(practice)
target_sources(practice PRIVATE "main.cpp")
set_property(TARGET practice PROPERTY CXX_STANDARD 20)


add_subdirectory ("doctest")
