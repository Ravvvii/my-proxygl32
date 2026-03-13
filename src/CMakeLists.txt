cmake_minimum_required(VERSION 3.20)
project(opengl32)

set(CMAKE_CXX_STANDARD 20)

enable_language(ASM_MASM)

include_directories(proxy_gl32)

add_library(opengl32 SHARED
    main.cpp
    proxy_gl32/opengl32.cpp
    proxy_gl32/opengl32_asm.asm
    proxy_gl32/opengl32.def
    proxy_gl32/empty.h
    proxy_gl32/proxy_gl32.h
)
