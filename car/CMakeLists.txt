# cmake_minimum_required(VERSION <specify CMake version here>)
project(car)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(car
		Car/CarMovement.cpp
		Car/CarMovement.h
		Car/D2Vector.h)
