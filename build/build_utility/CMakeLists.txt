cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++0x -pthread")
set(CMAKE_BUILD_TYPE Release)

project(mdu)

find_package( Boost 1.57.0 COMPONENTS system filesystem )
include(FindCurses)
include_directories(${Boost_INCLUDE_DIRS})


set(SOURCES
    ../../daemon/utility.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
