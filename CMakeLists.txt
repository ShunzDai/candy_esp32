cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

set(PROJECT_NAME "candy_esp32")

set(COMPONENTS main)

project(${PROJECT_NAME})
