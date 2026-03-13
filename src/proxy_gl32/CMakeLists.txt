set(CMAKE_GENERATOR_PLATFORM "x64" CACHE STRING "" FORCE)
PROJECT(opengl32)
ENABLE_LANGUAGE(C CXX ASM_MASM)
ADD_LIBRARY(opengl32 SHARED opengl32_asm.asm opengl32.cpp opengl32.def empty.h proxy_gl32.h)