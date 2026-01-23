cmake_minimum_required(VERSION 3.10)
project(Ej10PromedioPuntero)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej10PromedioPuntero
    main.cpp
    utils/Puntero.h
    utils/Puntero.cpp
    core/EstadisticasPuntero.h
    core/EstadisticasPuntero.cpp
)
