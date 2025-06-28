cmake_minimum_required(VERSION 3.10)

project(HelloWorld)
set(CMAKE_CXX_STANDARD 17)


# Use pkg-config to find GTKmm
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(Calculator main.cpp 
                 calculator.cpp calculator.h)
target_link_libraries(Calculator ${GTKMM_LIBRARIES} tinyexpr)
