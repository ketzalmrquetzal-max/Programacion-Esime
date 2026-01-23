cmake_minimum_required(VERSION 3.10)
project(Ej3Calculadora)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej3Calculadora
    main.cpp
    interfaces/ICalculadora.h
    core/Calculadora.h
    core/Calculadora.cpp
    utils/Menu.h
    utils/Menu.cpp
)
