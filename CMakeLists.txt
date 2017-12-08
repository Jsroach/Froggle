cmake_minimum_required(VERSION 3.8)
project(mcjj)

#set(CMAKE_CXX_STANDARD 14)

#set(SOURCE_FILES main.cpp Board.h Piece.h Board.cpp Consonant.h Consonant.cpp Piece.cpp Vowel.cpp Vowel.h Player.cpp Player.h graphics.h game_graphics.cpp)
#add_executable(mcjj ${SOURCE_FILES})

#Graphics text below

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fpermissive")

find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(main.cpp ${SOURCE_FILES})
target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} m dl pthread)