cmake_minimum_required(VERSION 2.8.4)

#arduino setting
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/Platform/Arduino.cmake)

project(car)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(CMAKE_CXX_STANDARD 11)
set(gtest_SOURCE_DIR C:/joey/Lib/googletest-master/googletest)
set(arduino_mock_SOURCE_DIR C:/joey/Lib/arduino-mock-master)

#### Uncomment below additional settings as needed.
#set(${CMAKE_PROJECT_NAME}_SKETCH Car/car.ino)
#set(${CMAKE_PROJECT_NAME}_BOARD uno)
# set(${CMAKE_PROJECT_NAME}_PORT /dev/ttyACM0)
# set(mega.build.mcu atmega2560)
# set(mega.upload.protocol wiring)
# set(mega.upload.speed 115200)
# set(uno.build.core 1)

#generate_arduino_firmware(${CMAKE_PROJECT_NAME})



set(Servo_RECURSE True)

include_directories(.)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#include_directories(Lib/mthread)
include_directories(${arduino_mock_SOURCE_DIR}/include/arduino-mock ${arduino_mock_SOURCE_DIR})
#link_directories(${arduino_mock_SOURCE_DIR})

add_executable(car
		Car/CarMovement.cpp
		Car/CarMovement.h
		Car/CoordinateSystem.cpp
		Car/CoordinateSystem.h
		Car/util.cpp
		Car/util.h
		Car/Scaner.cpp
		Car/Scaner.h
		Car/InstrumentErrorCorrection.cpp
		Car/InstrumentErrorCorrection.h Car_tests/test_CarMovement.cpp main.cpp Car/CarPropertyFinder.cpp Car/CarPropertyFinder.h Car/Car.cpp Car/Car.h Car/ScanDataAnalyst.cpp Car/ScanDataAnalyst.h Car_tests/test_CarPropertyFinder.cpp Car/Controller.cpp Car/Controller.h Car/Counter.cpp Car/Counter.h Car/ObserverPattern.cpp Car/ObserverPattern.h Car/inoSetting.cpp)


target_link_libraries(car gtest gtest_main)
#target_link_libraries(car mthread Lib/mthread)
target_link_libraries(car arduino-mock/ )
