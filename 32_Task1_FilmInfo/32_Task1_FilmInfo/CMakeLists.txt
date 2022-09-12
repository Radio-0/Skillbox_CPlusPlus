# CMakeList.txt: проект CMake для 32_Task1_FilmInfo; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (32_Task1_FilmInfo "32_Task1_FilmInfo.cpp")

target_link_libraries(32_Task1_FilmInfo PRIVATE nlohmann_json::nlohmann_json)