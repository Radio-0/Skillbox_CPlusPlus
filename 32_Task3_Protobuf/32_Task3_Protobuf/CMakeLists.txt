# CMakeList.txt: проект CMake для 32_Task3_Protobuf; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (32_Task3_Protobuf "32_Task3_Protobuf.cpp" "32_Task3_Protobuf.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 32_Task3_Protobuf PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
