cmake_minimum_required(VERSION 3.20)
project(oosd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(student_lib STATIC
    src/Subject.cpp
    src/CoffeePot.cpp
    src/Person.cpp
)

target_include_directories(student_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_executable(app
    src/main.cpp
)

target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(app PRIVATE student_lib)