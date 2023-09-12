cmake_minimum_required(VERSION 3.16.3)
project(mearlymath_m)
add_library(mearlymath_m adder.cpp)
set_target_properties(mearlymath_m PROPERTIES PUBLIC_HEADER adder.h)
install(TARGETS mearlymath_m LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)
