cmake_minimum_required(VERSION 3.10)
project(Ej21QuickIndirecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej21QuickIndirecto
    main.cpp
    interfaces/IOrdenadorIndirecto.h
    operations/OrdenadorIndirectoQuick.h
)
