cmake_minimum_required(VERSION 4.1)
project(Ej4ESIME)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej4ESIME main.cpp
        interfaces/Operacion.h
        operations/Suma.h
        operations/Resta.h
        operations/Multiplicacion.h
        operations/Division.h
        core/Calculadora.cpp
        core/Calculadora.h
        utils/Parametros.h
        utils/Parametros.cpp
        operations/Suma.cpp
        operations/Resta.cpp
        operations/Multiplicacion.cpp
        operations/Division.cpp
)
