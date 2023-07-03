#ifndef ZONE_HPP
#define ZONE_HPP

#include "Inventaire.hpp"
#include "Arbre.hpp"
#include <vector>

class Zone {
public:
    Zone(int niveau, int xpNecessaire, int nbBuches, int prixBuche);
    ~Zone();
    int getNiveau() const;
    int getXpNecessaire() const;
    int getNbBuches() const;
    void collecterBuches(Inventaire* inventaire);
    int getNbArbres() const;
    Arbre getArbre(int i) const;
    void afficher() const;

    Zone(); // Déclaration du constructeur par défaut

private:
    int m_niveau;
    int m_xpNecessaire;
    int m_nbBuches;
    int m_prixBuche;
    std::vector<Arbre> m_arbres;
};

#endif // ZONE_HPP
