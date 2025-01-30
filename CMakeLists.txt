# 1. cmake version
cmake_minimum_required(VERSION 2.8)

# 2. project name
project(SimpleDIP)

# 3. head file path
include_directories(
  src
)

if (CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++11)
    add_definitions(-Wno-unused-function)
endif()

#check_include_file(string.h HAVE_STRING_H)

# 4. source file path
aux_source_directory(src DIR_SRCS)

#add_subdirectory(src)

#message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
#message(${DIR_SRCS})
add_executable(simpleDIP ${DIR_SRCS} "main.cpp")

#target_link_libraries(simpleDIP m)
