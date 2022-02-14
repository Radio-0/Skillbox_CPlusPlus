cmake_minimum_required(VERSION 3.17)
project("25_Task2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 16)

add_subdirectory(25_Task2_Sim_Computer 25_Task2_Sim_Computer.cpp kbd.h gpu.h cpu.h disk.h ram.h gpu.cpp cpu.cpp disk.cpp ram.cpp kbd.cpp)