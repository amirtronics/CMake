cmake_minimum_required(VERSION 3.16.3)


add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(Adder)

# #       DOWNLOAD ALL THE SUBMODULES
# find_package(Git QUIET)
# if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# # Update submodules as needed
#     options(GIT_SUBMODULE "Check submodules during build" ON)
#     if(GIT_SUBMODULE)
#         message(STATUS "Submodule udpate")
#         execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recusrive
#                         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#                         RESULT_VARIABLE GIT_SUBMOD_RESULT)
#         if(NOT GIT_SUBMOD_RESULT EQUAL "0")
#             message(FATAL_ERROR "git submodule update --init faield with ${GIT_SUBMOD_ERSULT}, please")
#         endif()
#     endif()
# endif()


# #           CHECK ALL THE SUBMODULES
# if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
#     message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed.")
# endif()


add_subdirectory(external/glfw)


target_include_directories(${PROJECT_NAME} 
    PUBLIC Adder 
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE mearlymath_m
    PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} mearlymath_m glfw)