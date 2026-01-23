cmake_minimum_required(VERSION 3.10)
project(Ej1HolaMundo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej1HolaMundo 
    main.cpp
    core/Saludo.h
    core/Saludo.cpp
    interfaces/ISaludador.h
)
