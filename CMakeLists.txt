cmake_minimum_required(VERSION 3.8)
project(cpp_waste_recycling_AndrasKovacs84)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Garbage.cpp include/Garbage.h src/PaperGarbage.cpp include/PaperGarbage.h src/PlasticGarbage.cpp include/PlasticGarbage.h src/DustbinContentError.cpp include/DustbinContentError.h src/Dustbin.cpp include/Dustbin.h src/DustbinIsFull.cpp include/DustbinIsFull.h)
add_executable(cpp_waste_recycling_AndrasKovacs84 ${SOURCE_FILES})