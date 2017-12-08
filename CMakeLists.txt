cmake_minimum_required(VERSION 3.7)
project(MCJJ)

#set(CMAKE_CXX_STANDARD 14)

#set(SOURCE_FILES main.cpp Board.h Piece.h Board.cpp Consonant.h Consonant.cpp Piece.cpp Vowel.cpp Vowel.h Player.cpp Player.h graphics.h game_graphics.cpp)
#add_executable(mcjj ${SOURCE_FILES})

#Graphics text below

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(FREEGLUT_INCLUDE_DIRS "C:/Program\ Files/Common\ Files/freeglut/include")
set(FREEGLUT_LIBRARY_DIRS "C:/Program\ Files/Common\ Files/freeglut/lib")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fpermissive")

find_package (OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR}  ${FREEGLUT_INCLUDE_DIRS})
link_directories(${FREEGLUT_LIBRARY_DIRS})

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(main.cpp ${SOURCE_FILES})

target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} m freeglut)





