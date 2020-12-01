cmake_minimum_required(VERSION 3.14)

project(HelloPrj)

add_executable(HelloPrj src/main.c src/sum.c)
target_include_directories(HelloPrj PRIVATE include)