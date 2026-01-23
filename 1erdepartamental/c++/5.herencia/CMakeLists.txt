cmake_minimum_required(VERSION 3.10)
project(Ej5Herencia)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej5Herencia
    main.cpp
    interfaces/ICalculadora.h
    core/CalculadoraBase.h
    core/CalculadoraBase.cpp
    operations/CalculadoraCientifica.h
    operations/CalculadoraCientifica.cpp
    operations/CalculadoraFinanciera.h
    operations/CalculadoraFinanciera.cpp
)
