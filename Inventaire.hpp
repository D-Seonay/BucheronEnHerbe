#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include <vector>
#include <string>
#include "Objet.hpp"

class Inventaire {
public:
    Inventaire() : m_objets() {}
    void ajouterObjet(const Objet& objet);    //void supprimerObjet(const std::string& nomObjet, int quantite);
    void afficher() const;
    //const std::vector<Objet>& getObjets() const  { return m_objets; }
    int getNbObjets() const { return m_objets.size(); }
    void ajouterObjet(const std::string& nomObjet, int quantite);
    void supprimerObjet(const std::string& nomObjet, int quantite);

private:
    std::vector<Objet> m_objets;

};

#endif // INVENTAIRE_H
