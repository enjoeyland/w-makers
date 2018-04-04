# cmake_minimum_required(VERSION <specify CMake version here>)
project(car)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(car
        CarMovement.cpp
        CarMovement.h
        D2Vector.h CarMovementAnalog.cpp CarMovementAnalog.h CarMovementDigital.cpp CarMovementDigital.h)
