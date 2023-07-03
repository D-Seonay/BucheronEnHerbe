#include "Inventaire.hpp"
#include <iostream>


void Inventaire::ajouterObjet(const std::string& nomObjet, int quantite) {
    Objet objet(nomObjet, quantite);
    m_objets.push_back(objet);
}




void Inventaire::supprimerObjet(const std::string& nomObjet, int quantite) {
    for (Objet& objet : m_objets) {
        if (objet.getNom() == nomObjet) {
            objet.setQuantite(objet.getQuantite() - quantite);
            if (objet.getQuantite() <= 0) {
                m_objets.erase(std::remove_if(m_objets.begin(), m_objets.end(),
                                              [&](Objet o) { return o.getNom() == nomObjet; }),
                               m_objets.end());
            }
            break;
        }
    }
}

void Inventaire::afficher() const {
    if (m_objets.empty()) {
        std::cout << "L'inventaire est vide." << std::endl;
    } else {
        std::cout << "Contenu de l'inventaire :" << std::endl;
        for (const Objet& objet : m_objets) {
            std::cout << "- " << objet.getNom() << " : " << objet.getQuantite() << std::endl;
        }
    }
}
