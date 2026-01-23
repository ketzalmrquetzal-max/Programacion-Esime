cmake_minimum_required(VERSION 3.10)
project(Ej2SumaParametros)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej2SumaParametros
    main.cpp
    core/Sumador.h
    core/Sumador.cpp
    interfaces/IOperadorMatematico.h
)
