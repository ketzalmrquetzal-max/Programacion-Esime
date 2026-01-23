cmake_minimum_required(VERSION 3.10)
project(Ej19BurbujaIndirecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej19BurbujaIndirecto
    main.cpp
    interfaces/IOrdenadorIndirecto.h
    operations/OrdenadorIndirectoBurbuja.h
)
