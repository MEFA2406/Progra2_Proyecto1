cmake_minimum_required(VERSION 4.1)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto1 main.cpp
        Usuario.cpp
        Usuario.h
        Estudiante.cpp
        Estudiante.h
        Prestamo.cpp
        Prestamo.h
        NodoPrestamo.cpp
        NodoPrestamo.h
        ListaPrestamo.cpp
        ListaPrestamo.h)
