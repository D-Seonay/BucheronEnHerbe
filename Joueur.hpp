#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <string>
#include <vector>
#include "Inventaire.hpp"
#include "Objet.hpp"
#include "Zone.hpp"

class Joueur
{
public:
    Joueur(const std::string& nom, int niveauMax, int xpActuelle);

    std::string getNom() const;
    int getNiveau() const;
    int getXp() const;
    void gagnerXp(int xp);
    int getXpRestant() const;
    void ajouterArgent(int argent);
    int getArgent() const;
    void ajouterObjet(const Objet& objet);
    void afficherInventaire() const;
    void ajouterArbreCoupe(int nb);
    void ajouterXPGagne(int xp);
    void augmenterNiveauHache();
    void afficherStatistiques() const;
    void vendreBois();
    void couperBois(Joueur& joueur, Zone& zone);

    Inventaire& getInventaire();
    const Inventaire& getInventaire() const; // On ajoute une version constante de la fonction getInventaire()

private:
    std::string m_nom;
    int m_niveauMax;
    int m_xpActuelle;
    int m_level;
    std::vector<int> m_xpRequis;
    int nbBuches;
    int prixParBuche;
    float coefficientHache;
    int nbArbresCouper_;
    int xpGagner_;
    int niveauHache_;
    int m_argent;
    Inventaire m_inventaire;
};

#endif // JOUEUR_HPP
