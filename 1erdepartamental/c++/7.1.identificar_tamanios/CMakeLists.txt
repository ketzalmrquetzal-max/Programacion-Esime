cmake_minimum_required(VERSION 3.10)
project(Ej7_1IdentificarTamanios)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej7_1IdentificarTamanios
    main.cpp
    core/AnalizadorTamanios.h
    core/AnalizadorTamanios.cpp
    core/Persona.h
    core/Persona.cpp
)
