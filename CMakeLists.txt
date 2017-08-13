cmake_minimum_required(VERSION 3.1)

project(SmootSpeech)
set (CMAKE_CXX_STANDARD 11)
include_directories("${CMAKE_SOURCE_DIR}/header")
file(GLOB SOURCES "./source/*.cpp")
add_executable(SmoothSpeech ${SOURCES})
