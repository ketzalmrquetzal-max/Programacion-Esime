cmake_minimum_required(VERSION 3.10)
project(Ej20MergeIndirecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej20MergeIndirecto
    main.cpp
    interfaces/IOrdenadorIndirecto.h
    operations/OrdenadorIndirectoMerge.h
)
