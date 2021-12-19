cmake_minimum_required(VERSION 3.21)
project(mapdownloader)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Boost COMPONENTS system REQUIRED)

add_library(mapdownloader mapdownloader.cpp)
target_link_libraries(mapdownloader
        curl
        crypto
        ${Boost_LIBRARIES}
        )

add_executable(test_main test_main.cpp)
target_link_libraries(test_main mapdownloader)