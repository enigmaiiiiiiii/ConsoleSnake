cmake_minimum_required(VERSION 3.20)
project(ConsoleSnake)

set(CMAKE_CXX_STANDARD 23)

AUX_SOURCE_DIRECTORY(. gamesrc)

add_executable(Console ${gamesrc})
