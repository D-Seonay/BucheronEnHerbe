#include "Arbre.hpp"


#include <iostream>


Arbre::Arbre(int bois /* = 0 */) :
        m_bois(bois) {}

int Arbre::couper() {
    int xp = m_bois;
    m_bois = 0;
    return xp;
}

int Arbre::getBois() const {
    return m_bois;
}

void Arbre::afficher()const {
    std::cout << "Bois : " << m_bois << std::endl;
}
