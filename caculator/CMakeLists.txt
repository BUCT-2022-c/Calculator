cmake_minimum_required(VERSION 3.5)

project (Calculator VERSION 1.0)

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True) 
set(SOURCES
    src/caculator.cpp
    src/calendar.cc
    src/else.cc
    src/get_time.cc
    src/history.cc
    src/matrix.cc
    src/resource.cc
    src/truth_table.cc
    src/ui.cc
    src/write_history.cc
    )

add_executable(calculator ${SOURCES})
# add_subdirectory(src)
target_include_directories(calculator
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/lib
)