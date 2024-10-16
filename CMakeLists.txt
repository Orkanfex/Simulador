cmake_minimum_required(VERSION 3.22)
project(Simulador)

set(CMAKE_CXX_STANDARD 17)

include_directories(/home/madeira/Documentos/PP/Simulador/SFML-2.5.1/include)
link_directories(/home/madeira/Documentos/PP/Simulador/SFML-2.5.1/build/lib)

add_executable(Simulador main.cpp
        AND.cpp
        AND.h
        Componentes.cpp
        Componentes.h
        OR.cpp
        OR.h
        NOT.cpp
        NOT.h
        BOARD.cpp
        BOARD.h
        WIRE.cpp
        WIRE.h
        Alocar.cpp
        Alocar.h
        IO.cpp
        IO.h)

target_link_libraries(Simulador -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio)