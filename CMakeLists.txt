cmake_minimum_required(VERSION 3.27)
project(EsteRPG)

set(CMAKE_CXX_STANDARD 17)

add_executable(EsteRPG main.cpp
        Personaje.cpp
        Headers/Personaje.h
        Guerrero.cpp
        Headers/Guerrero.h
        Hechicero.cpp
        Headers/Hechicero.h
        GuerreroHechicero.cpp
        Headers/GuerreroHechicero.h
        Equipo.cpp
        Headers/Equipo.h
        Batalla.cpp
        Headers/Batalla.h)
