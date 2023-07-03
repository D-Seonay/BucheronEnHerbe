#ifndef ARBRE_HPP
#define ARBRE_HPP

class Arbre {
public:
    Arbre(int bois);

    int couper();

    int getBois() const;

    void afficher() const;

private:
    int m_bois;
};

#endif // ARBRE_HPP
