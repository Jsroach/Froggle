cmake_minimum_required(VERSION 3.8)
project(mcjj)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Board.h Piece.h Board.cpp Consonant.h Consonant.cpp Piece.cpp Vowel.cpp Vowel.h Player.cpp Player.h graphics.h game_graphics.cpp)
add_executable(mcjj ${SOURCE_FILES})