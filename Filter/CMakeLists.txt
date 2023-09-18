cmake_minimum_required(VERSION 3.16.3)

project(ButterworthFilterExample)

# Find the ButterworthFilter library
find_package(ButterworthFilter REQUIRED)

# Source files
set(SOURCES
    main.cpp
)

# Create an executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the ButterworthFilter library
target_link_libraries(${PROJECT_NAME} PRIVATE ButterworthFilter)

# Set C++ standard
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)