cmake_minimum_required(VERSION 3.10)
project(Ej16Burbuja)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej16Burbuja
    main.cpp
    interfaces/IOrdenador.h
    operations/OrdenadorBurbuja.h
)
