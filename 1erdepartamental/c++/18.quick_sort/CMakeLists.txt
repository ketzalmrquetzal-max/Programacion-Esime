cmake_minimum_required(VERSION 3.10)
project(Ej18QuickSort)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej18QuickSort
    main.cpp
    interfaces/IOrdenador.h
    operations/OrdenadorQuick.h
)
