cmake_minimum_required(VERSION 3.13.0)
project(practice)

add_executable(practice)
target_sources(practice PRIVATE "main.cpp")

add_subdirectory ("doctest")
