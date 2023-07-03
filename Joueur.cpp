#include "Joueur.hpp"
//#include "Inventaire.hpp"
#include "Zone.hpp"
#include "Objet.hpp"
#include "Inventaire.hpp"
#include <random>

using namespace std;


#include <iostream>

Joueur::Joueur(const string& nom, int niveauMax, int xpActuelle)
        : m_nom(nom), m_niveauMax(niveauMax), m_xpActuelle(xpActuelle), m_level(1),
          nbBuches(10), prixParBuche(5), coefficientHache(1), nbArbresCouper_(0),
          xpGagner_(0), niveauHache_(1), m_argent(0), m_inventaire()
{
    // Initialisation du tableau des xp requis pour chaque niveau
    m_xpRequis.resize(niveauMax);
    for (int i = 0; i < niveauMax; ++i) {
        m_xpRequis[i] = 100 * (i + 1);
    }
}

string Joueur::getNom() const
{
    return m_nom;
}

int Joueur::getNiveau() const
{
    return m_level;
}

int Joueur::getXp() const
{
    return m_xpActuelle;
}

void Joueur::gagnerXp(int xp)
{
    m_xpActuelle += xp;
    if (m_xpActuelle >= m_xpRequis[m_level - 1]) {
        ++m_level;
        cout << "Bravo ! Vous êtes maintenant niveau " << m_level << "." << std::endl;
    }
}

int Joueur::getXpRestant() const {
    return m_xpRequis[m_level] - m_xpActuelle;
}


const int niveauMax = 50;
const vector<unsigned long long> xpRequis = {0, 100ull, 200ull, 400ull, 800ull, 1600ull, 3200ull, 6400ull,
                                                  12800ull, 25600ull, 51200ull, 102400ull, 204800ull, 409600ull,
                                                  819200ull, 1638400ull, 3276800ull, 6553600ull, 13107200ull,
                                                  26214400ull, 52428800ull, 104857600ull, 209715200ull,
                                                  419430400ull, 838860800ull, 1677721600ull, 3355443200ull,
                                                  6710886400ull, 13421772800ull, 26843545600ull, 53687091200ull,
                                                  107374182400ull, 214748364800ull, 429496729600ull,
                                                  858993459200ull, 1717986918400ull, 3435973836800ull,
                                                  6871947673600ull, 13743895347200ull, 27487790694400ull,
                                                  54975581388800ull, 109951162777600ull, 219902325555200ull,
                                                  439804651110400ull, 879609302220800ull, 1759218604441600ull,
                                                  3518437208883200ull, 7036874417766400ull, 14073748835532800ull,
                                                  28147497671065600ull, 56294995342131200ull, 112589990684262400ull,
                                                  28147497671065600ull};


void Joueur::ajouterArgent(int argent) {
    m_argent += argent;
}

void Joueur::ajouterObjet(const Objet& objet)
{
    m_inventaire.ajouterObjet(objet.getNom(), objet.getQuantite());
}

void Joueur::afficherInventaire() const
{
    cout << "*** INVENTAIRE ***" << std::endl;
    m_inventaire.afficher();
}

void afficherInventaire(const Joueur& joueur) {
    cout << "*** INVENTAIRE ***" << std::endl;
    joueur.getInventaire().afficher();
}

void Joueur::ajouterArbreCoupe(int nb)
{
    nbArbresCouper_ += nb;
}

void Joueur::ajouterXPGagne(int xp)
{
    xpGagner_ += xp;
}

void Joueur::augmenterNiveauHache()
{
    ++niveauHache_;
}

void Joueur::afficherStatistiques() const
{
    cout << "*** STATISTIQUES ***" << endl;
    cout << "Statistiques pour le joueur " << m_nom << ":" << endl;
    cout << "  Nombre d'arbres coupés : " << nbArbresCouper_ << endl;
    cout << "Niveau : " << getNiveau() << endl;
    cout << "  XP gagné              : " << xpGagner_ << endl;
    cout << "  Niveau de la hache    : " << niveauHache_ << endl;
    cout << "Argent : " << getArgent() << endl;
}

int Joueur::getArgent() const {
    return m_argent;
}


Inventaire& Joueur::getInventaire()
{
    return m_inventaire;
}


void Joueur::vendreBois() {
    int prixUnitaire = 5; // Prix unitaire de chaque tronc
    int nbTroncsVendus = getInventaire().getNbObjets();
    int gain = nbTroncsVendus * prixUnitaire;
    getInventaire().supprimerObjet("tronc", nbTroncsVendus);
    ajouterArgent(gain);
    cout << "Vous avez vendu " << nbTroncsVendus << " tronc(s) pour " << gain << " pièce(s) d'or." << endl;
}



void Joueur::couperBois(Joueur& joueur, Zone& zone) {
    cout << "Vous entrez dans la zone de jeu." << endl;
    zone.afficher();
    int nbArbresCoupes = 0;
    for (int i = 0; i < zone.getNbArbres(); i++) {
        Arbre arbre = zone.getArbre(i);
        random_device rd;
        mt19937 gen(rd());
        int xp = arbre.couper();
        joueur.gagnerXp(xp);
        cout << "Vous avez coupé un arbre et gagné " << xp
             << " points d'expérience !" << endl;
        cout << "Il vous reste " << joueur.getXpRestant() << " points d'expérience pour atteindre le niveau suivant." << endl;

        uniform_int_distribution<int> troncDist(1, 3); // Distribution aléatoire pour déterminer le nombre de troncs obtenus
        int nbTroncs = troncDist(gen);
        cout << "Vous avez obtenu " << nbTroncs << " tronc(s)." << endl;
        if (nbTroncs > 0) {
            Objet tronc("Tronc", nbTroncs);
            joueur.ajouterObjet(tronc);
        }
        nbArbresCoupes++;
    }
    cout << "Vous avez coupé " << nbArbresCoupes << " arbres." << endl;
}


const Inventaire& Joueur::getInventaire() const {
    return m_inventaire;
}
