/*
 * Ex1.cpp
 *
 *  Created on: 29 oct. 2026
 *      Author: hP
 */
#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
    string nom;
    string prenom;
public:
    Personne(string n, string p) {
        nom = n;
        prenom = p;
    }
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Prenom : " << prenom << endl;
    }
};

class Chercheur {
protected:
    string domaineRecherche;
public:
    Chercheur(string d) {
        domaineRecherche = d;
    }
    void afficher() {
        cout << "Domaine de recherche : " << domaineRecherche << endl;
    }
};

// heritage multiple
class EnseignantChercheur : public Personne, public Chercheur {
public:
    EnseignantChercheur(string n, string p, string d) : Personne(n, p), Chercheur(d) {
    }
    void afficher() {
        // on appelle les deux afficher() des parents
        Personne::afficher();
        Chercheur::afficher();
    }
};

int main() {
    EnseignantChercheur ec("Alami", "Karim", "Intelligence artificielle");
    ec.afficher();
    return 0;
}



