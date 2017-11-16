cmake_minimum_required(VERSION 3.8)
project(mcjj)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Board.h Piece.h Board.cpp)
add_executable(mcjj ${SOURCE_FILES})