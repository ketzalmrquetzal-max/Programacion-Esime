cmake_minimum_required(VERSION 3.10)
project(Ej17MergeSort)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej17MergeSort
    main.cpp
    interfaces/IOrdenador.h
    operations/OrdenadorMerge.h
)
