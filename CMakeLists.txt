cmake_minimum_required(VERSION 3.24)
project(unt)

set(CMAKE_CXX_STANDARD 17)

add_executable(unt main.cpp Joueur.hpp Inventaire.hpp Zone.hpp Zone.cpp Joueur.cpp Inventaire.cpp Arbre.hpp Arbre.cpp Objet.hpp Objet.cpp)
