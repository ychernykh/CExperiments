cmake_minimum_required(VERSION 2.8)

project(CAlg)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

include_directories(include)

set(SRC_DIR src)

set(SOURCE_FILES
  ${SRC_DIR}/SList.c
  ${SRC_DIR}/DList.c)

add_library(calg STATIC ${SOURCE_FILES})
