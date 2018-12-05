cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++0x -pthread")
set(CMAKE_BUILD_TYPE Release)

project(monitor_daemon)

find_package( Boost 1.57.0 COMPONENTS system filesystem )
find_package (Threads)
find_package(Curses)
include_directories(${Boost_INCLUDE_DIRS})


set(SOURCES
    ../../daemon/daemon.cpp
    ../../stat-grabbers/grabbers/cpustatgrabber.cpp
    ../../stat-grabbers/grabbers/diskstatgrabber.cpp
    ../../stat-grabbers/grabbers/fstatgrabber.cpp
    ../../stat-grabbers/grabbers/memstatgrabber.cpp
    ../../stat-grabbers/grabbers/netdevgrabbers.cpp
    ../../stat-grabbers/grabbers/statgrabber.cpp
    ../../stat-grabbers/savers/fstatsaver.cpp
    ../../stat-grabbers/savers/printstatsaver.cpp
    ../../stat-grabbers/savers/statsaver.cpp
    ../../stat-grabbers/setup/stringutilities.cpp
    ../../stat-grabbers/setup/supervisor.cpp
    ../../stat-grabbers/statdata/cpustatisticdata.cpp
    ../../stat-grabbers/statdata/diskstatisticdata.cpp
    ../../stat-grabbers/statdata/memstatisticdata.cpp
    ../../stat-grabbers/statdata/netdevstatisticdata.cpp
    ../../stat-grabbers/statdata/statisticdata.cpp
)

include_directories(
    ../../stat-grabbers/grabbers/
    ../../stat-grabbers/savers/
    ../../stat-grabbers/setup/
    ../../stat-grabbers/statdata/
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${LIBCONFIG_LIBRARIES})
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (${PROJECT_NAME} ${CURSES_LIBRARIES})
target_link_libraries(${PROJECT_NAME} -lconfig -lconfig++)
target_include_directories(${PROJECT_NAME} PUBLIC ${LIBCONFIG_INCLUDE_DIR})
