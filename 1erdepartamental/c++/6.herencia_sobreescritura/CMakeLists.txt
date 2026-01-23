cmake_minimum_required(VERSION 3.10)
project(Ej6HerenciaSobreescritura)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej6HerenciaSobreescritura
    main.cpp
    interfaces/ICalculadora.h
    core/CalculadoraBase.h
    core/CalculadoraBase.cpp
    operations/CalculadoraDirecta.h
    operations/CalculadoraDirecta.cpp
    operations/CalculadoraSucesiva.h
    operations/CalculadoraSucesiva.cpp
)
