cmake_minimum_required(VERSION 3.10)
project(Ej13TipoDatoPuntero)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ej13TipoDatoPuntero
    main.cpp
    utils/PunteroTipado.h
    core/Estudiante.h
    core/Estudiante.cpp
    core/EstadisticasEstudiantes.h
    core/EstadisticasEstudiantes.cpp
)
