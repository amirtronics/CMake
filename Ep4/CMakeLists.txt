cmake_minimum_required(VERSION 3.16.3)

project(OLAS VERSION 1.0)

add_executable(${PROJECT_NAME} main.cpp)


option(USE_ADDER "A simple library for adding 2 floats." ON)

if(USE_ADDER)
    add_subdirectory(Adder)

    list(APPEND EXTRA_LIBS adder)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/Adder")

    target_include_directories(${PROJECT_NAME} 
        PUBLIC adder
    )

    target_link_directories(${PROJECT_NAME} 
        PUBLIC adder
    )
endif()


configure_file(OLASConfig.h.in OLASConfig.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# adder use logic

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
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDES}
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/src
    ${EXTRA_LIBS}
)

target_link_libraries(${PROJECT_NAME} adder glfw)