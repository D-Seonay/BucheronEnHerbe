#include "Zone.hpp"
#include "Arbre.hpp"
#include "Inventaire.hpp" // ajout de l'en-tête Inventaire.hpp

#include <iostream>

Zone::Zone(int niveau, int xpNecessaire, int nbBuches, int prixBuche)
        : m_niveau(niveau), m_xpNecessaire(xpNecessaire), m_nbBuches(nbBuches), m_prixBuche(prixBuche)
{}

Zone::~Zone()
{}

int Zone::getNiveau() const
{
    return m_niveau;
}

int Zone::getXpNecessaire() const
{
    return m_xpNecessaire;
}

int Zone::getNbBuches() const
{
    return m_nbBuches;
}

int Zone::getNbArbres() const {
    return m_arbres.size();
}

Arbre Zone::getArbre(int i) const {
    return m_arbres[i];
}

void Zone::afficher() const {
    std::cout << "La zone contient " << m_arbres.size() << " arbres : " << std::endl;
    for (int i = 0; i < m_arbres.size(); i++) {
        std::cout << "Arbre " << i+1 << " : ";
        m_arbres[i].afficher();
    }
}

Zone::Zone() {
    // Initialise la zone avec des arbres
    m_arbres.push_back(Arbre(1));
    m_arbres.push_back(Arbre(1));
    m_arbres.push_back(Arbre(2));
    m_arbres.push_back(Arbre(2));
    m_arbres.push_back(Arbre(2));
}


