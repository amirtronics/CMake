cmake_minimum_required(VERSION 3.9.3)


# set project properties
project(opencv_cpp)
message(STATUS "## invoking ${CMAKE_CURRENT_SOURCE_DIR}/CMakelist.txt")

find_package(OpenCV QUIET COMPONENTS core highgui imgproc imgcodecs videoio
                          OPTIONAL_COMPONENTS cudaimgproc)

set(CMAKE_CXX_STANDARD 11)


set(NEOAPI_ROOT_DIR "/opt/Baumer_neoAPI_1.3.0_lin_x86_64_cpp")
link_directories(${NEOAPI_ROOT_DIR}/lib)

include_directories(
SYSTEM
${NEOAPI_ROOT_DIR}/include
${OpenCV_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
opencv.cpp)

target_link_libraries(${PROJECT_NAME}
neoapi_cpp
${OpenCV_LIBS}
)

