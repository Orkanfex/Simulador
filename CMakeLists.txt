cmake_minimum_required(VERSION 3.22)
project(Simulador)

set(CMAKE_CXX_STANDARD 17)

include_directories(/home/madeira/Documentos/PP/Simulador/SFML-2.5.1/include)
link_directories(/home/madeira/Documentos/PP/Simulador/SFML-2.5.1/build/lib)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")


add_executable(Simulador main.cpp
        Componentes.cpp
        Componentes.h
        BOARD.cpp
        BOARD.h
        IO.cpp
        IO.h
        ComponentesApp.cpp
        ComponentesApp.h
        AppSimulador.cpp
        AppSimulador.h
        CalcLogico.cpp
        CalcLogico.h
        BUttonComponentApp.cpp
        BUttonComponentApp.h)

target_compile_options(Simulador INTERFACE
        "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;-g>>"
        "$<${msvc_cxx}:-W3")

target_link_libraries(Simulador -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio)