# CMakeList.txt: проект CMake для CMakeProject1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.

add_executable (CMakeProject1 CMakeProject1.cpp include/kbd.h include/gpu.h include/cpu.h include/disk.h include/ram.h src/gpu.cpp src/cpu.cpp src/disk.cpp src/ram.cpp src/kbd.cpp)
target_include_directories(CMakeProject1 PUBLIC include)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
