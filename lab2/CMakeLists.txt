cmake_minimum_required(VERSION 3.25)
project(lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab2 main.c treap_tree.h test.cpp treap_tree.c main.h)
