#ifndef OBJET_HPP
#define OBJET_HPP

#include <string>

class Objet {
public:
    Objet(const std::string& nom, int quantite) : m_nom(nom), m_quantite(quantite) {}
    const std::string& getNom() const { return m_nom; }
    int getQuantite() const { return m_quantite; }
    void setQuantite(int quantite);


private:
    std::string m_nom;
    int m_quantite;
};


#endif // OBJET_HPP
