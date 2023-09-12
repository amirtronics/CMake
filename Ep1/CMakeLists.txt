cmake_minimum_required(VERSION 3.16.3)

project(OLAS)

add_executable(${PROJECT_NAME} main.cpp)


add_subdirectory(Adder)
add_subdirectory(./../external/glfw)

target_include_directories(${PROJECT_NAME} PUBLIC Adder)

target_link_directories(${PROJECT_NAME} PRIVATE mearlymath_m)

target_link_libraries(${PROJECT_NAME} mearlymath_m)