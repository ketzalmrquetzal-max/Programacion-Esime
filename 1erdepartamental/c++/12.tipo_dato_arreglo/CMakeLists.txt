cmake_minimum_required(VERSION 3.10)
project(Ej12TipoDatoArreglo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej12TipoDatoArreglo
    main.cpp
    core/Producto.h
    core/Producto.cpp
    core/ColeccionProductos.h
    core/ColeccionProductos.cpp
)
