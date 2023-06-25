cmake_minimum_required(VERSION 3.24)
project(SourceCode_Indenter)

set(CMAKE_CXX_STANDARD 17)

add_executable(SourceCode_Indenter main.cpp Tokeniser.cpp Tokeniser.h FileIO.cpp FileIO.h)
